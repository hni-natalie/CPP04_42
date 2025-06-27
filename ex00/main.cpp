/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:11:35 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/27 13:45:38 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void ocf_animal()
{
	std::cout << "=== OCF Animal ===\n";

	Animal a1;
	Animal a2(a1);
	Animal a3;

	a3 = a2;
	a3.makeSound();
	
	std::cout << "\n=== Free ===\n";
}

void ocf_dog()
{
	std::cout << "\n=== OCF Dog ===\n";

	Dog d1;
	Dog d2(d1);
	Dog d3;

	d3 = d2;
	d3.makeSound();
	
	std::cout << "\n=== Free ===\n";
}


void ocf_cat()
{
	std::cout << "\n=== OCF Cat ===\n";

	Cat c1;
	Cat c2(c1);
	Cat c3;

	c3 = c2;
	c3.makeSound();

	std::cout << "\n=== Free ===\n";
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

	std::cout << j->getType() << "\n";
	std::cout << i->getType() << "\n";
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

	std::cout << "\n=== Free ===\n";
}

void constructor_wif_name() {
	std::cout << "\n=== Constructor with type ===\n";
	Animal animal("Mammal");
	Dog dog("Corgi");
	Cat cat("Garfield");

	std::cout << animal.getType() << "\n";
	std::cout << dog.getType() << "\n";
	std::cout << cat.getType() << "\n";

	std::cout << "\n=== Free ===\n";
}

int main() 
{
	ocf_animal();
	ocf_cat();
	ocf_dog();
	tester_42();
	wrong_animal();
	constructor_wif_name();
	return 0;
}
