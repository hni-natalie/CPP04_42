/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:14:33 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 19:08:10 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Cat Constructor is called\n";
	_type = "Cat";
	_cat_ideas = new Brain();
}

Cat::~Cat() {
	delete _cat_ideas;
	std::cout << "Cat Destructor is called.\n";
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Cat Copy Constructor is called.\n";
	// deep copy
	_cat_ideas = new Brain(*other._cat_ideas);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignment Operator is called.\n";
	if (this != &other) {
		AAnimal::operator=(other);
		delete _cat_ideas;
		_cat_ideas = new Brain(*other._cat_ideas);
	}

	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow ~ Meow ~\n";
}

Brain* Cat::getBrain() {
	return _cat_ideas;
}