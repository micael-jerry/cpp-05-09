/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 05:22:37 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/28 17:50:55 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

#include "../include/ScalarConverter.hpp"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cerr << "Invalid args" << std::endl;
    return 1;
  }
  ScalarConverter::convert(argv[1]);
  return 0;
}
