/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:14:41 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 19:08:19 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << "Dog Constructor is called\n";
	_type = "Dog";
	_dog_ideas = new Brain();
}

Dog::~Dog() {
	delete _dog_ideas;
	std::cout << "Dog Destructor is called.\n";
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	std::cout << "Dog Copy Constructor is called.\n";
	_dog_ideas = new Brain(*other._dog_ideas);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Copy Assignment Operator is called.\n";
	if (this != &other) {
		AAnimal::operator=(other);
		delete _dog_ideas;
		_dog_ideas = new Brain(*other._dog_ideas);
	}

	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof ~ Woof ~\n";
}

Brain* Dog::getBrain() {
	return _dog_ideas;
}