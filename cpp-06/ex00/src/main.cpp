/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 05:22:37 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/25 19:22:18 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/ScalarConverter.hpp"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cerr << "Invalid args" << std::endl;
    return 1;
  }
	ScalarConverter::convert(argv[1]);
  return 0;
}
