#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog Constructor is called\n";
	type = "Dog";
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

