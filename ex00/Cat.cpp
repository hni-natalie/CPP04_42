#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat Constructor is called\n";
	type = "Cat";
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
