/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:52:34 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/28 20:19:55 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "../include/PmergeMe.hpp"

int main(int argc, const char *argv[]) {
  if (argc <= 2) {
    return 0;
  }
  try {
    pMergeMe::argsValidator(argc, argv);
    std::vector<long> container = pMergeMe::parseArgs(argc, argv);
    (void) container;
  } catch (const PmergeMeException &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}