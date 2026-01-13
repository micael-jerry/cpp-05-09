/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 05:57:10 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/13 19:21:41 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Data.hpp"
#include "../include/Serializer.hpp"

int main() {
  Data data(42, "Jerry");

  uintptr_t raw = Serializer::serialize(&data);
  Data *ptr = Serializer::deserialize(raw);

  std::cout << "Original ptr: " << &raw << std::endl
            << "Deserialized ptr: " << ptr << std::endl;

  std::cout << "ID: " << ptr->getId() << std::endl;
  std::cout << "Name: " << ptr->getName() << std::endl;

  return 0;
}