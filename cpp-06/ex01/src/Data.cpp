/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 05:48:33 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/12 05:50:48 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

Data::Data() : _id(0), _name("") {}

Data::Data(int id, const std::string &name) : _id(id), _name(name) {}

Data::Data(const Data &src) { *this = src; }

Data::~Data() {}

Data &Data::operator=(const Data &src) {
  if (this != &src) {
    this->_id = src._id;
    this->_name = src._name;
  }
  return (*this);
}

int Data::getId() const { return (this->_id); }

const std::string &Data::getName() const { return (this->_name); }
