/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:13:33 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/27 11:08:16 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Constructor is called.\n";
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << "Cure Copy Constructor is called.\n";
}

Cure& Cure::operator=(const Cure& other) {
	std::cout << "Cure Copy Assignment Operator is called.\n";
	if (this != &other)
		AMateria::operator=(other);

	return *this;
}

Cure::~Cure() {
	std::cout << "Cure Destructor is called.\n";
}

Cure* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}