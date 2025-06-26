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

Animal::Animal() : _type("Animal") {
	std::cout << "AAnimal Constructor is called.\n";
}

Animal::~Animal() {
	std::cout << "AAnimal Destructor is called.\n";
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "AAnimal Copy Constructor is called.\n";
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "AAnimal Copy Assignment Operator is called.\n";
	if (this != &other) {
		_type = other._type;
	}

	return *this;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::setType(std::string& type) {
	_type = type;
}
