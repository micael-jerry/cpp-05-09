/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 05:57:24 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/19 06:07:51 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Identifier.hpp"

#include <cstdlib>

#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base *identifier::generate() {
  const int random = rand() % 3;
  if (random == 0)
    return new A();
  else if (random == 1)
    return new B();
  else
    return new C();
}

void identifier::identify(Base *p) {
	(void) p;
}

void identifier::identify(Base &p) {
	(void) p;
}
