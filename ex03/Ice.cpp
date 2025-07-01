/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:13:33 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/27 11:08:04 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Constructor is called.\n";
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Ice Copy Constructor is called.\n";
}

Ice& Ice::operator=(const Ice& other) {
	std::cout << "Ice Copy Assignment Operator is called.\n";
	if (this != &other)
		AMateria::operator=(other);

	return *this;
}

Ice::~Ice() {
	std::cout << "Ice Destructor is called.\n";
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}