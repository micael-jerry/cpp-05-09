/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/04 17:33:25 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main() {
  try {
    Bureaucrat boss("Boss", 1);
    Bureaucrat employee("Employee", 150);

    Form contract("Contract", 50, 20);

    std::cout << contract << std::endl;

    std::cout << "\n=== Employee tries to sign ===" << std::endl;
    employee.signForm(contract);

    std::cout << "\n=== Boss signs ===" << std::endl;
    boss.signForm(contract);

    std::cout << contract << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
