/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 05:52:32 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/20 05:34:25 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include "./Base.hpp"

namespace identifier {
Base *generate(void);
void identify(Base *p);
void identify(Base &p) throw();
}  // namespace identifier

#endif