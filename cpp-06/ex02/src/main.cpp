/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 06:04:07 by mfidimal          #+#    #+#             */
/*   Updated: 2026/01/19 06:07:31 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Identifier.hpp"

int main(void) {
	Base *base = identifier::generate();

	identifier::identify(base);
	identifier::identify(*base);

	delete base;

	return 0;
}
