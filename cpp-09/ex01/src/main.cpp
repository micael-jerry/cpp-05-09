/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:25:36 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/24 05:08:12 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/RPN.hpp"

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    std::cerr << "ERROR: invalid arguments" << std::endl;
    return 1;
  }
  try {
    validator::isValidRPN(argv[1]);
  } catch (const validator::ValidatorException &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
