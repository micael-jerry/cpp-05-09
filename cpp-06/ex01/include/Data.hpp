/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 05:23:08 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/12 05:50:28 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
 private:
  int _id;
  std::string _name;

 public:
  Data();
  Data(int id, const std::string &name);
  Data(const Data &src);
  ~Data();

  Data &operator=(const Data &src);

  int getId() const;
  const std::string &getName() const;
};

#endif