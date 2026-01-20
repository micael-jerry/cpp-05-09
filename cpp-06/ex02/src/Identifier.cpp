/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 05:57:24 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/20 05:59:19 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Identifier.hpp"

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base *identifier::generate() {
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(NULL));
    seeded = true;
  }

  const int random = rand() % 3;
  if (random == 0)
    return new A();
  else if (random == 1)
    return new B();
  else
    return new C();
}

void identifier::identify(Base *p) {
  std::cout << "Pointer identification: ";
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "A";
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << "B";
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << "C";
  else
    std::cout << "Base";
  std::cout << std::endl;
}

void identifier::identify(Base &p) throw() {
  std::cout << "Reference identification: ";
  try {
    A _ = dynamic_cast<A &>(p);
    std::cout << "A";
  } catch (...) {
    try {
      B _ = dynamic_cast<B &>(p);
      std::cout << "B";
    } catch (...) {
      try {
        C _ = dynamic_cast<C &>(p);
        std::cout << "C";
      } catch (...) {
        std::cout << "Base";
      }
    }
  }
  std::cout << std::endl;
}
