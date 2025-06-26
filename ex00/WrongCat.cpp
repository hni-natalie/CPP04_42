/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:11:47 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 16:11:48 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat Constructor is called\n";
	type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor is called.\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat Copy Constructor is called.\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat Copy Assignment Operator is called.\n";
	if (this != &other) {
		WrongAnimal::operator=(other);
	}

	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Silent Meow ~ Silent Meow ~\n";
}