/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:13:33 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 19:06:46 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria Default Constructor is called.\n";
}

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMateria Constructor is called.\n";
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << "AMateria Copy Constructor is called.\n";
}

AMateria& AMateria::operator=(const AMateria& other) {
	std::cout << "AMateria Copy Assignment Operator is called.\n";
	if (this != &other)
		_type = other._type;

	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor is called.\n";
}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria used " << target.getName() << "\n";
}