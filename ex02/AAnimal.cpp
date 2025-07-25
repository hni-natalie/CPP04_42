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

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal Constructor is called.\n";
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal Destructor is called.\n";
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "AAnimal Copy Constructor is called.\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "AAnimal Copy Assignment Operator is called.\n";
	if (this != &other) {
		_type = other._type;
	}

	return *this;
}

std::string AAnimal::getType() const {
	return _type;
}

void AAnimal::setType(std::string& type) {
	_type = type;
}
