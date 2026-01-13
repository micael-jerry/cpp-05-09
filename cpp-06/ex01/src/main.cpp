/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 05:57:10 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/13 20:03:59 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

#include "../include/Data.hpp"
#include "../include/Serializer.hpp"

int main() {
  Data data(42, "Jerry");

  uintptr_t raw = Serializer::serialize(&data);
  Data *ptr = Serializer::deserialize(raw);

  std::cout << "Original ptr: " << &data << std::endl
            << "Deserialized ptr: " << ptr << std::endl
            << std::endl;
  std::cout << "ID: " << ptr->getId() << std::endl;
  std::cout << "Name: " << ptr->getName() << std::endl;

  return 0;
}