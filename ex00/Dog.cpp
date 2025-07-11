/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:11:26 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 18:16:16 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog Constructor is called\n";
	_type = "Dog";
}

Dog::Dog(std::string type) : Animal(type)  {
	std::cout << "Dog Constructor is called\n";
}

Dog::~Dog() {
	std::cout << "Dog Destructor is called.\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog Copy Constructor is called.\n";
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Copy Assignment Operator is called.\n";
	if (this != &other) {
		Animal::operator=(other);
	}

	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof ~ Woof ~\n";
}

