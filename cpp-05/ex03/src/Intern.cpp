/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:58:15 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/17 06:02:09 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern() {
}

Intern::Intern(Intern const &src) {
  (void)src;
}

Intern::~Intern() {
}

Intern &Intern::operator=(Intern const &src) {
  (void)src;
  return *this;
}

AForm *Intern::makeForm(std::string const &formName,
                        std::string const &target) {
}