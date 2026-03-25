/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:25:36 by mfidimal          #+#    #+#             */
/*   Updated: 2026/03/25 05:42:03 by mfidimal         ###   ########.fr       */
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
    rpn::rpnParamsValidator(argv[1]);
    std::cout << rpn::rpn(argv[1]) << std::endl;
  } catch (const rpn::RPNException &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
