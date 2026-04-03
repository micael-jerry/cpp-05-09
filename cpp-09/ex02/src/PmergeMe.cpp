/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 06:02:24 by mfidimal          #+#    #+#             */
/*   Updated: 2026/04/03 06:06:42 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

#include <algorithm>
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

std::vector<std::pair<long, long> > pMergeMe::extractPairs(
    const std::vector<long> &container) {
  std::vector<std::pair<long, long> > pairsContainer;

  for (size_t i = 0; i < container.size() - 1; i += 2) {
    if (container[i] > container[i + 1]) {
      pairsContainer.push_back(std::make_pair(container[i + 1], container[i]));
    } else {
      pairsContainer.push_back(std::make_pair(container[i], container[i + 1]));
    }
  }

  return pairsContainer;
}

void pMergeMe::sortPairs(std::vector<std::pair<long, long> > &pairs) {
  if (pairs.size() <= 1) {
    return;
  }

  size_t mid = pairs.size() / 2;

  std::vector<std::pair<long, long> > leftPairs(pairs.begin(),
                                                pairs.begin() + mid);
  std::vector<std::pair<long, long> > rightPairs(pairs.begin() + mid,
                                                 pairs.end());

  sortPairs(leftPairs);
  sortPairs(rightPairs);

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

std::pair<std::vector<long>, std::vector<long> >
pMergeMe::extractMainAndPendingChain(
    std::vector<std::pair<long, long> > pairs) {
  std::vector<long> mainChain;
  std::vector<long> secondChain;

  std::vector<std::pair<long, long> >::iterator it = pairs.begin();

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

size_t pMergeMe::getJacobsthalNumber(size_t n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}

std::vector<long> pMergeMe::insertPendingElements(
    std::vector<long> mainChain, std::vector<long> pendingChain,
    long struggler) {
  size_t curJacobthalIndex = 3;

  size_t prev = 0;
  size_t curr = pMergeMe::getJacobsthalNumber(curJacobthalIndex) - 1;
  if (curr > pendingChain.size()) {
    curr = pendingChain.size() - 1;
  }
  // TODO: CONDITION DE NEXT ET D'ARRET
  while (curr >= prev && prev < pendingChain.size()) {
    std::vector<long>::iterator it = std::lower_bound(
        mainChain.begin(), mainChain.end(), pendingChain[curr]);
    mainChain.insert(it, pendingChain[curr]);
    if (curr == prev) {
      curJacobthalIndex++;
      prev = curr;
      curr = pMergeMe::getJacobsthalNumber(curJacobthalIndex) - 1;
      if (curr > pendingChain.size()) {
        curr = pendingChain.size() - 1;
      }
      break;
    }
    curr--;
  }

  if (struggler != NO_STRUGGLER) {
    std::vector<long>::iterator it =
        std::lower_bound(mainChain.begin(), mainChain.end(), struggler);
    mainChain.insert(it, struggler);
  }
  return mainChain;
}

std::vector<long> pMergeMe::mergeInsertSort(std::vector<long> &container) {
  long struggler = NO_STRUGGLER;

  if (container.size() % 2 != 0) {
    struggler = container.back();
    container.pop_back();
  }

  std::vector<std::pair<long, long> > pairsContainer =
      pMergeMe::extractPairs(container);
  pMergeMe::sortPairs(pairsContainer);

  std::pair<std::vector<long>, std::vector<long> > mainAndSecondChain =
      pMergeMe::extractMainAndPendingChain(pairsContainer);

  return pMergeMe::insertPendingElements(mainAndSecondChain.first,
                                         mainAndSecondChain.second, struggler);
}
