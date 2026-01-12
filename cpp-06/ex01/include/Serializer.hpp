/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 05:17:36 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/12 06:02:13 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

#include "./Data.hpp"

class Serializer {
 private:
  Serializer();
  Serializer(Serializer const &serializer);
  Serializer &operator=(Serializer const &serializer);

  ~Serializer();

 public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif