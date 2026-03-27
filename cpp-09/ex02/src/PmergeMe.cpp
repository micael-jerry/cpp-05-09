/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 06:02:24 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/27 06:27:12 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

#include <cctype>
#include <cstddef>
#include <cstdlib>
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