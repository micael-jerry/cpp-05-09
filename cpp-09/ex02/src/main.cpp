/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:52:34 by mfidimal          #+#    #+#             */
/*   Updated: 2026/04/06 21:09:33 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

#include "../include/PmergeMe.hpp"

typedef std::vector<long> vec;
typedef std::vector<std::pair<long, long> > pairVec;

typedef std::deque<long> deq;
typedef std::deque<std::pair<long, long> > pairDeq;

long getTimeInUs() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000000 + tv.tv_usec;
}

template <typename Container>
bool isSorted(const Container &c) {
  for (size_t i = 1; i < c.size(); ++i) {
    if (c[i - 1] > c[i]) return false;
  }
  return true;
}

void printResult(int size, const std::string &containerName, long start,
                 long end) {
  std::cout << "Time to process a range of " << size << " elements with "
            << containerName << " : " << (end - start) << " us" << std::endl;
}

void runTests() {
  std::cout << "\n--- Running Robustness Tests ---\n" << std::endl;

  int testCases[][11] = {
      {1},                                // Single element
      {2, 1},                             // Two elements, reverse
      {1, 2, 3},                          // Three elements, sorted
      {3, 2, 1},                          // Three elements, reverse
      {1, 3, 2, 4},                       // Even, mixed
      {5, 2, 9, 1, 7},                    // Odd, mixed
      {42, 42, 42, 42},                   // Duplicates
      {10, 1, 10, 1, 10},                 // Interleaved duplicates
      {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},     // Longer reverse
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}  // Longer sorted
  };
  int testSizes[] = {1, 2, 3, 3, 4, 5, 4, 5, 10, 11};

  for (int i = 0; i < 10; ++i) {
    vec v;
    for (int j = 0; j < testSizes[i]; ++j) v.push_back(testCases[i][j]);

    std::cout << "Test " << i + 1 << " (size " << testSizes[i] << "): ";
    vec vCopyV = v;
    vec sortedV = pMergeMe::mergeInsertSort<vec, pairVec>(vCopyV);

    deq d(v.begin(), v.end());
    deq sortedD = pMergeMe::mergeInsertSort<deq, pairDeq>(d);

    bool vSorted = isSorted(sortedV);
    bool dSorted = isSorted(sortedD);
    bool match = true;
    if (sortedV.size() != sortedD.size())
      match = false;
    else {
      for (size_t k = 0; k < sortedV.size(); ++k)
        if (sortedV[k] != sortedD[k]) match = false;
    }

    if (vSorted && dSorted && match) {
      std::cout << "\033[32mOK\033[0m" << std::endl;
    } else {
      std::cout << "\033[31mFAILED\033[0m" << std::endl;
      if (!vSorted) std::cout << "  Vector NOT sorted" << std::endl;
      if (!dSorted) std::cout << "  Deque NOT sorted" << std::endl;
      if (!match)
        std::cout << "  Results mismatch between containers" << std::endl;
    }
  }
  std::cout << "\n--------------------------------\n" << std::endl;
}

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    std::cerr << "Error: Invalid args" << std::endl;
    return 1;
  }

  if (argc == 2 && std::string(argv[1]) == "test") {
    runTests();
    return 0;
  }

  try {
    pMergeMe::argsValidator(argc, argv);
    vec v = pMergeMe::parseArgs<vec>(argc, argv);
    deq d(v.begin(), v.end());

    std::cout << "Before:   ";
    pMergeMe::printContainer<vec>(v);

    long startV = getTimeInUs();
    vec sortedV = pMergeMe::mergeInsertSort<vec, pairVec>(v);
    long endV = getTimeInUs();

    long startD = getTimeInUs();
    pMergeMe::mergeInsertSort<deq, pairDeq>(d);
    long endD = getTimeInUs();

    std::cout << "After:    ";
    pMergeMe::printContainer<vec>(sortedV);

    printResult(v.size(), "std::vector", startV, endV);
    printResult(v.size(), "std::deque", startD, endD);
  } catch (const PmergeMeException &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}