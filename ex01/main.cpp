#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

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

void tester()
{
	std::cout << "\n=== Test ===\n";
	int n = 10;
	const Animal*meta[n];

	for (int idx=0; idx < n; idx++) {
		if (idx < (n / 2)) 
			meta[idx] = new Dog();
		else 
			meta[idx] = new Cat();
	}
	std::cout << "\n";

	for (int idx=0; idx < n; idx++) {
		meta[idx]->makeSound();
	}

	std::cout << "\n";
	for (int idx=0; idx < n; idx++) {
		delete meta[idx];
	}
}

void dog_brain_test() {
	std::cout << "\n=== Dog Brain Test ===\n";
	Dog dog1; 
	dog1.getBrain()->setIdea(0, "I want Bone!");

	Dog dog2 = dog1;
	dog2.getBrain()->setIdea(0, "Let's play!");

	std::cout << "dog1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << "dog1's brain address: " << dog1.getBrain() << std::endl;
	std::cout << "dog2's brain address: " << dog2.getBrain() << std::endl;
}

void cat_brain_test() {
	std::cout << "\n=== Cat Brain Test ===\n";
	Cat cat1; 
	cat1.getBrain()->setIdea(0, "I want Fish!");

	Cat cat2 = cat1;
	cat2.getBrain()->setIdea(0, "I want sleep!");

	std::cout << "cat1's idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << "cat1's brain address: " << cat1.getBrain() << std::endl;
	std::cout << "cat2's brain address: " << cat2.getBrain() << std::endl;
}

int main() 
{
	ocf_animal();
	ocf_cat();
	ocf_dog();
	tester();
	dog_brain_test();
	cat_brain_test();
	return 0;
}
