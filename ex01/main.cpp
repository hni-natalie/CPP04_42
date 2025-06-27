/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:24:41 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/27 14:19:03 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void tester()
{
	std::cout << "\n=== Test ===\n";
	int n = 10;
	const Animal*meta[n];

	for (int idx = 0; idx < n; idx++) {
		if (idx < (n / 2)) 
			meta[idx] = new Dog();
		else 
			meta[idx] = new Cat();
	}
	std::cout << "\n";

	for (int idx=0; idx < n; idx++) {
		meta[idx]->makeSound();
	}

	std::cout << "\n=== Free ===\n";
	for (int idx=0; idx < n; idx++) {
		delete meta[idx];
	}
}

void brain_test() {
	std::cout << "\n=== Brain Test ===\n";
	
	Brain b1;
	Brain b2(b1);
	Brain b3;

	b3 = b2;
	std::cout << "\n=== Idea in b1 ===\n";
	for (int idx=0; idx < 5; idx++) {
		std::cout << b1.getIdea(idx) << "\n";
	}

	std::cout << "\n=== Idea in b2 ===\n";
	for (int idx=0; idx < 5; idx++) {
		std::cout << b2.getIdea(idx) << "\n";
	}

	std::cout << "\n=== Idea in b3 ===\n";
	for (int idx=0; idx < 5; idx++) {
		std::cout << b3.getIdea(idx) << "\n";
	}

	std::cout << "\n=== Free ===\n";
}

void dog_brain_test() {
	std::cout << "\n=== Dog Brain Test ===\n";
	Dog dog1; 
	dog1.getBrain()->setIdea(0, "I want Bone!");

	Dog dog2 = dog1;
	dog2.getBrain()->setIdea(0, "Let's play!");

	Dog dog3(dog2);

	std::cout << "dog1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog1's idea: " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << "dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2's idea: " << dog2.getBrain()->getIdea(1) << std::endl;
	std::cout << "dog3's idea: " << dog3.getBrain()->getIdea(0) << std::endl;

	std::cout << "dog1's brain address: " << dog1.getBrain() << std::endl;
	std::cout << "dog2's brain address: " << dog2.getBrain() << std::endl;
	std::cout << "dog3's brain address: " << dog3.getBrain() << std::endl;

	std::cout << "\n=== Free ===\n";
}

void cat_brain_test() {
	std::cout << "\n=== Cat Brain Test ===\n";
	Cat cat1; 
	cat1.getBrain()->setIdea(0, "I want Fish!");

	Cat cat2 = cat1;
	cat2.getBrain()->setIdea(0, "I want sleep!");

	Cat cat3(cat2);

	std::cout << "cat1's idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << "cat3's idea: " << cat3.getBrain()->getIdea(0) << std::endl;

	std::cout << "cat1's brain address: " << cat1.getBrain() << std::endl;
	std::cout << "cat2's brain address: " << cat2.getBrain() << std::endl;
	std::cout << "cat3's brain address: " << cat3.getBrain() << std::endl;

	std::cout << "\n=== Free ===\n";
}

int main() 
{
	ocf_animal();
	ocf_cat();
	ocf_dog();
	tester();
	brain_test();
	dog_brain_test();
	cat_brain_test();
	return 0;
}
