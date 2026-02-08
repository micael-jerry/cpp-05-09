
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 07:34:08 by mfidimal          #+#    #+#             */
/*   Updated: 2026/02/08 08:24:20 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int toFind) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), toFind);

  if (it == container.end()) {
    throw NotFoundException();
  }
  return it;
}