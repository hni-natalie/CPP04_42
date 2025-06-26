/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:11:17 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 18:16:10 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat Constructor is called\n";
	_type = "Cat";
}

Cat::Cat(std::string type) : Animal(type)  {
	std::cout << "Cat Constructor is called\n";
}

Cat::~Cat() {
	std::cout << "Cat Destructor is called.\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat Copy Constructor is called.\n";
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignment Operator is called.\n";
	if (this != &other) {
		Animal::operator=(other);
	}

	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow ~ Meow ~\n";
}
