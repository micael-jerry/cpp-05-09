/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 06:02:24 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/29 16:19:52 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

bool pMergeMe::isPositiveNumberStr(const std::string &str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (!std::isdigit(str[i])) return false;
  }
  return true;
}

void pMergeMe::argsValidator(int ac, const char *av[]) {
  for (size_t i = 1; i < (size_t)ac; i++) {
    if (!isPositiveNumberStr(av[i])) {
      throw PmergeMeException("Invalid argument: " + std::string(av[i]));
    }
  }
}

std::vector<long> pMergeMe::parseArgs(int ac, const char *av[]) {
  std::vector<long> container;
  for (size_t i = 1; i < (size_t)ac; i++) {
    long num = std::strtol(av[i], NULL, 10);
    container.push_back(num);
  }
  return container;
}

void pMergeMe::printContainer(const std::vector<long> &container) {
  for (size_t i = 0; i < container.size(); i++) {
    std::cout << container[i] << " ";
  }
  std::cout << std::endl;
}

void sortPairs(std::vector<std::pair<long, long> > &pairs) {
  if (pairs.size() <= 1) {
    return;
  }

  // MERGE SORTE
}

void pMergeMe::mergeInsertSort(std::vector<long> &container) {
  long struggler = -1;
  (void)struggler;

  if (container.size() % 2 != 0) {
    struggler = container.back();
    container.pop_back();
  }

  std::vector<std::pair<long, long> > pairContainer;
  for (size_t i = 0; i < container.size() - 1; i += 2) {
    if (container[i] > container[i + 1]) {
      pairContainer.push_back(std::make_pair(container[i + 1], container[i]));
    } else {
      pairContainer.push_back(std::make_pair(container[i], container[i + 1]));
    }
  }
}
