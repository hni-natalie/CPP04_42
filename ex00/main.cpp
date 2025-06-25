#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	std::cout << "\n";
	// We need to take Animal class here instead of Dog class 
	// so that we can see the behavior of polymorphism
	const Animal* j = new Dog();
	std::cout << "\n";
	const Animal* i = new Cat();
	std::cout << "\n";
	const WrongAnimal* alpha = new WrongAnimal();
	std::cout << "\n";
	const WrongAnimal* minion = new WrongCat();

	std::cout << "\n=== 42 Test ===\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "=== 42 Test End ===\n\n";

	alpha->makeSound();
	minion->makeSound();

	std::cout << "\n=== Free ===\n";
	delete meta;
	delete j;
	delete i;
	delete alpha;
	delete minion;

	return 0;
}
