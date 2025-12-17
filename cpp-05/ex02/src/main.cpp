/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/15 05:42:57 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
int main(void) {
  Bureaucrat tom = Bureaucrat("Tom", 50);
  ShrubberyCreationForm form1 = ShrubberyCreationForm("target1");

  std::cout << form1 << std::endl;
  tom.signForm(form1);
  std::cout << form1 << std::endl;

  return 0;
}
