/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:24:41 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/27 14:24:34 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

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

void pointer() 
{
	std::cout << "\n=== Pointer ===\n";
	const AAnimal* j = new Dog;

	std::cout << j->getType() << "\n";
	j->makeSound();

	delete j;
}

void tester()
{
	std::cout << "\n=== Test ===\n";
	int n = 10;
	const AAnimal*meta[n];

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

	Dog dog3(dog2);

	std::cout << "dog1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog1's idea: " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << "dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2's idea: " << dog2.getBrain()->getIdea(1) << std::endl;
	std::cout << "dog3's idea: " << dog3.getBrain()->getIdea(0) << std::endl;

	std::cout << "dog1's brain address: " << dog1.getBrain() << std::endl;
	std::cout << "dog2's brain address: " << dog2.getBrain() << std::endl;
	std::cout << "dog3's brain address: " << dog3.getBrain() << std::endl;
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
}

int main() 
{
	// This will show error
	// AAnimal a;
	
	ocf_cat();
	ocf_dog();
	pointer();
	tester();
	dog_brain_test();
	cat_brain_test();
	return 0;
}
