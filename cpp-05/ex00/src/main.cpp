/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/14 05:20:08 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat tom = Bureaucrat("Tom", 1);
    std::cout << tom << std::endl;
    tom.incrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "----------------" << std::endl;

  try {
    Bureaucrat jerry = Bureaucrat("Jerry", 150);
    std::cout << jerry << std::endl;
    jerry.decrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
