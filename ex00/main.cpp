#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void ocf_animal()
{
	std::cout << "\n=== OCF Animal ===\n";

	Animal a1;
	Animal a2(a1);
	Animal a3;

	a3 = a2;
	a3.makeSound();
}

void ocf_dog()
{
	std::cout << "\n=== OCF Dog ===\n";

	Dog d1;
	Dog d2(d1);
	Dog d3;

	d3 = d2;
	d3.makeSound();
}


void ocf_cat()
{
	std::cout << "\n=== OCF Cat ===\n";

	Cat c1;
	Cat c2(c1);
	Cat c3;

	c3 = c2;
	c3.makeSound();
}

void tester_42()
{
	std::cout << "\n=== 42 Test ===\n";
	const Animal* meta = new Animal();
	std::cout << "\n";
	// We need to take Animal class here instead of Dog class 
	// so that we can see the behavior of polymorphism
	const Animal* j = new Dog();
	std::cout << "\n";
	const Animal* i = new Cat();
	std::cout << "\n";

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n=== Free ===\n";
	delete meta;
	delete j;
	delete i;
}

void wrong_animal() 
{
	std::cout << "\n=== Wrong Animal Test ===\n";
	const WrongAnimal* alpha = new WrongAnimal();
	const WrongAnimal* minion = new WrongCat();
	
	alpha->makeSound();
	minion->makeSound();
	
	delete alpha;
	delete minion;
}

int main() 
{
	ocf_animal();
	ocf_cat();
	ocf_dog();
	tester_42();
	wrong_animal();
	return 0;
}
