/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/17 05:12:10 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main() {
  Bureaucrat boss("Boss", 1);
  Bureaucrat employee("Employee", 150);

  Form contract("Contract", 50, 20);

  std::cout << contract << std::endl;

  std::cout << "\n=== Employee tries to sign ===" << std::endl;
  employee.signForm(contract);

  std::cout << "\n=== Boss signs ===" << std::endl;
  boss.signForm(contract);

  std::cout << contract << std::endl;

  return 0;
}