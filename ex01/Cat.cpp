#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat Constructor is called\n";
	type = "Cat";
	_cat_ideas = new Brain();
}

Cat::~Cat() {
	delete _cat_ideas;
	std::cout << "Cat Destructor is called.\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat Copy Constructor is called.\n";
	// deep copy
	_cat_ideas = new Brain(*other._cat_ideas);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy Assignment Operator is called.\n";
	if (this != &other) {
		Animal::operator=(other);
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