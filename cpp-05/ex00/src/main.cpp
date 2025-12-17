/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/17 05:10:01 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main() {
  std::cout << "=== Valid creation ===" << std::endl;
  try {
    Bureaucrat bob("Bob", 42);
    std::cout << bob << std::endl;

    bob.incrementGrade();
    std::cout << "After increment: " << bob << std::endl;

    bob.decrementGrade();
    std::cout << "After decrement: " << bob << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Invalid creation ===" << std::endl;
  try {
    Bureaucrat jim("Jim", 151);
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Grade too high ===" << std::endl;
  try {
    Bureaucrat king("King", 1);
    king.incrementGrade();
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  return 0;
}