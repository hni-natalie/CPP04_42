#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal Constructor is called.\n";
}

Animal::~Animal() {
	std::cout << "Animal Destructor is called.\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal Copy Constructor is called.\n";
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal Copy Assignment Operator is called.\n";
	if (this != &other) {
		type = other.type;
	}

	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal make sound ~\n";
}

std::string Animal::getType() const {
	return type;
}
