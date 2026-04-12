/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 06:02:24 by mfidimal          #+#    #+#             */
/*   Updated: 2026/04/12 18:28:00 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

#include <cctype>
#include <cstddef>
#include <cstdlib>

bool pMergeMe::isPositiveNumberStr(const std::string &str) {
  size_t i = 0;

  if (str.length() >= 2 && str[0] == '+' && std::isdigit(str[1])) {
    i = 2;
  }

  while (i < str.length())
  {
    if (!std::isdigit(str[i])) return false;
    i++;
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

size_t pMergeMe::getJacobsthalNumber(size_t n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}
