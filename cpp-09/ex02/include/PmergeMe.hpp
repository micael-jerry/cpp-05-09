/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:59:13 by mfidimal          #+#    #+#             */
/*   Updated: 2026/04/26 13:38:27 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define NO_STRUGGLER -1

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <utility>

class PmergeMeException : public std::exception {
 private:
  std::string _msg;

 public:
  PmergeMeException(const std::string &msg) : _msg("ERROR: " + msg) {}
  virtual ~PmergeMeException() throw() {}
  virtual const char *what() const throw() { return _msg.c_str(); }
};

namespace pMergeMe {
bool isPositiveNumberStr(const std::string &str);
void argsValidator(int ac, const char *av[]);

template <typename Container>
Container parseArgs(int ac, const char *av[]);

template <typename Container>
void printContainer(const Container &container);

template <typename Container, typename PairContainer>
PairContainer extractPairs(const Container &container);

template <typename PairContainer>
void sortPairs(PairContainer &pairs);

template <typename Container, typename PairContainer>
std::pair<Container, Container> extractMainAndPendingChain(PairContainer pairs);

size_t getJacobsthalNumber(size_t n);

template <typename Container>
Container insertPendingElements(Container mainChain, Container pendingChain,
                                long struggler);

template <typename Container, typename PairContainer>
Container mergeInsertSort(Container &container);
}  // namespace pMergeMe

template <typename Container>
Container pMergeMe::parseArgs(int ac, const char *av[]) {
  Container container;
  for (size_t i = 1; i < (size_t)ac; i++) {
    long num = std::strtol(av[i], NULL, 10);
    container.push_back(num);
  }
  return container;
}

template <typename Container>
void pMergeMe::printContainer(const Container &container) {
  for (size_t i = 0; i < container.size(); i++) {
    std::cout << container[i] << " ";
  }
  std::cout << std::endl;
}

template <typename Container, typename PairContainer>
PairContainer pMergeMe::extractPairs(const Container &container) {
  PairContainer pairsContainer;

  for (size_t i = 0; i < container.size() - 1; i += 2) {
    if (container[i] > container[i + 1]) {
      pairsContainer.push_back(std::make_pair(container[i + 1], container[i]));
    } else {
      pairsContainer.push_back(std::make_pair(container[i], container[i + 1]));
    }
  }

  return pairsContainer;
}

template <typename PairContainer>
void pMergeMe::sortPairs(PairContainer &pairs) {
  if (pairs.size() <= 1) {
    return;
  }

  size_t mid = pairs.size() / 2;

  PairContainer leftPairs(pairs.begin(), pairs.begin() + mid);
  PairContainer rightPairs(pairs.begin() + mid, pairs.end());

  sortPairs<PairContainer>(leftPairs);
  sortPairs<PairContainer>(rightPairs);

  size_t i = 0, j = 0, k = 0;

  while (i < leftPairs.size() && j < rightPairs.size()) {
    if (leftPairs[i].second <= rightPairs[j].second) {
      pairs[k] = leftPairs[i];
      i++;
    } else {
      pairs[k] = rightPairs[j];
      j++;
    }
    k++;
  }

  while (i < leftPairs.size()) {
    pairs[k] = leftPairs[i];
    i++;
    k++;
  }

  while (j < rightPairs.size()) {
    pairs[k] = rightPairs[j];
    j++;
    k++;
  }
}

template <typename Container, typename PairContainer>
std::pair<Container, Container> pMergeMe::extractMainAndPendingChain(
    PairContainer pairs) {
  Container mainChain;
  Container secondChain;

  typename PairContainer::iterator it = pairs.begin();
  if (it == pairs.end()) {
    return std::make_pair(mainChain, secondChain);
  }

  mainChain.push_back(it->first);
  mainChain.push_back(it->second);
  it++;

  while (it != pairs.end()) {
    mainChain.push_back(it->second);
    secondChain.push_back(it->first);
    it++;
  }

  return std::make_pair(mainChain, secondChain);
}

template <typename Container>
Container pMergeMe::insertPendingElements(Container mainChain,
                                          Container pendingChain,
                                          long struggler) {
  size_t curJacobthalIndex = 3;

  size_t prev = 0;
  if (pendingChain.empty()) {
    if (struggler != NO_STRUGGLER) {
      typename Container::iterator it =
          std::lower_bound(mainChain.begin(), mainChain.end(), struggler);
      mainChain.insert(it, struggler);
    }
    return mainChain;
  }
  size_t curr = pMergeMe::getJacobsthalNumber(curJacobthalIndex) - 1;
  if (curr >= pendingChain.size()) {
    curr = pendingChain.size() - 1;
  }
  //   TODO: lower_bound optimisation (begin to max of current pending element)
  while (prev < pendingChain.size()) {
    typename Container::iterator it = std::lower_bound(
        mainChain.begin(), mainChain.end(), pendingChain[curr]);
    mainChain.insert(it, pendingChain[curr]);
    if (curr == prev) {
      prev = pMergeMe::getJacobsthalNumber(curJacobthalIndex);
      curJacobthalIndex++;
      curr = pMergeMe::getJacobsthalNumber(curJacobthalIndex) - 1;
      if (curr >= pendingChain.size()) {
        curr = pendingChain.size() - 1;
      }
      continue;
    }
    curr--;
  }

  if (struggler != NO_STRUGGLER) {
    typename Container::iterator it =
        std::lower_bound(mainChain.begin(), mainChain.end(), struggler);
    mainChain.insert(it, struggler);
  }
  return mainChain;
}

template <typename Container, typename PairContainer>
Container pMergeMe::mergeInsertSort(Container &container) {
  long struggler = NO_STRUGGLER;

  if (container.size() <= 1) {
    return container;
  }

  if (container.size() % 2 != 0) {
    struggler = container.back();
    container.pop_back();
  }

  PairContainer pairsContainer =
      pMergeMe::extractPairs<Container, PairContainer>(container);
  pMergeMe::sortPairs(pairsContainer);

  std::pair<Container, Container> mainAndSecondChain =
      pMergeMe::extractMainAndPendingChain<Container, PairContainer>(
          pairsContainer);

  return pMergeMe::insertPendingElements(mainAndSecondChain.first,
                                         mainAndSecondChain.second, struggler);
}

#endif