/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:11:40 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 16:11:41 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal Constructor is called.\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor is called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "WrongAnimal Copy Constructor is called.\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal Copy Assignment Operator is called.\n";
	if (this != &other) {
		type = other.type;
	}

	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal make sound ~\n";
}

std::string WrongAnimal::getType() const {
	return type;
}