/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 05:02:51 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/14 14:47:27 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void) {
  Bureaucrat tom = Bureaucrat("Tom", 50);
  Form form1 = Form("1", 60, 60);
  Form form2 = Form("2", 40, 40);

  tom.signForm(form1);
  tom.signForm(form2);

  return 0;
}
