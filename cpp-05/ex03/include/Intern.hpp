/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 05:46:44 by mfidimal          #+#    #+#             */
/*   Updated: 2025/12/17 05:53:18 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "../include/AForm.hpp"

class Intern {
 public:
  Intern();
  Intern(Intern const &src);

  ~Intern();

  Intern &operator=(Intern const &src);

  AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif