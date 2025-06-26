/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:11:08 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 17:55:47 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal Constructor is called.\n";
}

Animal::Animal(std::string new_type) : _type(new_type) {
	std::cout << "Animal Constructor is called.\n";
}

Animal::~Animal() {
	std::cout << "Animal Destructor is called.\n";
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal Copy Constructor is called.\n";
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal Copy Assignment Operator is called.\n";
	if (this != &other) {
		_type = other._type;
	}

	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal make sound ~\n";
}

std::string Animal::getType() const {
	return _type;
}

void Animal::setType(std::string& type) {
	_type = type;
}