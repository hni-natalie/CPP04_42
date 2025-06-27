/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:35:34 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/27 14:36:25 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void ocf_ice()
{
	std::cout << "=== OCF Ice ===\n";
	Character* kevin = new Character("Kevin");
	Ice a1;
	Ice a2(a1);
	Ice a3;
	Ice* ice;
	
	a3 = a2;
	ice = a3.clone();
	kevin->equip(ice);
	kevin->use(0, *kevin);
	
	std::cout << "\n=== Free ===\n";
	delete kevin;
}

void ocf_cure()
{
	std::cout << "\n=== OCF Cure ===\n";
	Character* kevin = new Character("Kevin");
	Cure a1;
	Cure a2(a1);
	Cure a3;
	AMateria* cure;
	
	a3 = a2;
	cure = a3.clone();
	kevin->equip(cure);
	kevin->use(0, *kevin);
	
	std::cout << "\n=== Free ===\n";
	delete kevin;
}

void ocf_character()
{
	std::cout << "\n=== OCF Character ===\n";
	Character* kevin = new Character("Kevin");
	Character a1;
	Character a2(a1);
	Character a3;
	
	a3 = a2;
	std::cout << a1.getName() << "\n";
	std::cout << a2.getName() << "\n";
	std::cout << a3.getName() << "\n";
	
	AMateria* cure;
	cure = new Cure();
	
	a1.equip(new Ice());
	a1.equip(cure);
	a1.unequip(1);
	a1.use(0, *kevin);
	a1.use(1, *kevin);

	std::cout << "\n=== Free ===\n";
	delete cure;
	delete kevin;
}

void ocf_materia_source()
{
	std::cout << "\n=== OCF Materia Source ===\n";
	MateriaSource a1;
	MateriaSource a2(a1);
	MateriaSource a3;
	AMateria* ice_cube;
	
	a3 = a2;
	a2.learnMateria(new Ice());
	ice_cube = a2.createMateria("ice");
	
	std::cout << "\n=== Free ===\n";
	delete ice_cube;
}

void tester_42()
{
	std::cout << "\n=== Tester 42 ===\n";
	IMateriaSource* src = new MateriaSource();
	std::cout << "\n";
	src->learnMateria(new Ice());
	std::cout << "\n";
	src->learnMateria(new Cure());
	std::cout << "\n";
	src->learnMateria(new Ice());
	std::cout << "\n";
	
	ICharacter* kevin = new Character("Kevin");
	
	std::cout << "\n=== Create Materia ===\n";
	AMateria* materia;
	materia = src->createMateria("ice");
	kevin->equip(materia);
	materia = src->createMateria("cure");
	kevin->equip(materia);
	materia = src->createMateria("ice");
	kevin->equip(materia);
	
	ICharacter* target = new Character("Gus");
	ICharacter* dinasour = new Character("Dinasour");
	
	kevin->use(0, *target);
	kevin->use(1, *dinasour);
	kevin->use(2, *dinasour);

	std::cout << "\n=== Free ===\n";
	delete dinasour;
	std::cout << "\n";
	delete target;
	std::cout << "\n";
	delete kevin;
	std::cout << "\n";
	delete src;
}

void out_of_bound_test() 
{
	std::cout << "\n=== Out of Bound Test ===\n";
	IMateriaSource* src = new MateriaSource();
	
	std::cout << "\n=== Memory Update ===\n";
	for (int i = 0; i < 6; i++) {
		src->learnMateria(new Ice());
	}
	
	std::cout << "\n=== Free ===\n";
	delete src;
}

void create_test()
{
	std::cout << "\n=== Create Test ===\n";
	IMateriaSource* src = new MateriaSource();
	
	std::cout << "\n=== Memory Update ===\n";
	for (int i = 0; i < 3; i++) {
		src->learnMateria(new Ice());
	}

	std::cout << "\n=== Inventory Update ===\n";
	AMateria* materia;
	for (int i = 0; i < 3; i++) {
		materia = src->createMateria("ice");
		delete materia;
	}

	AMateria* extra;
	extra = src->createMateria("cure");
	delete extra;

	std::cout << "\n=== Free ===\n";
	delete src;
}

void equip_unequip_test()
{
	std::cout << "\n=== Equip & Unequip Test ===\n";
	IMateriaSource* src = new MateriaSource();
	ICharacter* kevin = new Character("Kevin");	
	ICharacter* target = new Character("Gus");

	std::cout << "\n=== Memory Update ===\n";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << "\n=== Inventory Update ===\n";
	AMateria* materia;
	for (int i = 0; i < 3; i++) {
		materia = src->createMateria("cure");
		kevin->equip(materia);
	}

	AMateria *ice;
	ice = src->createMateria("ice");
	kevin->equip(ice);
	kevin->unequip(3);

	for (int i = 0; i < 3; i++) {
		kevin->use(i, *target);
	}

	std::cout << "\n=== Free ===\n";
	delete ice;
	delete target;
	delete kevin;
	delete src;
}

void deep_copy_test() {
    Character original("Original");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    original.equip(ice);
    original.equip(cure);

    Character copy = original;

    std::cout << "Original uses slot 0: ";
    original.use(0, original);

    std::cout << "Copy uses slot 0: ";
    copy.use(0, copy);

	// for (int i = 0; i < 2; i++) {
    // 	std::cout << "original slot " << i << ": " << original.getInventoryAddress(i) << std::endl;
    // 	std::cout << "copy     slot " << i << ": " << copy.getInventoryAddress(i) << std::endl;
	// }

    std::cout << "\n=== Free ===\n";
}

int main()
{
	ocf_ice();
	ocf_cure();
	ocf_character();
	ocf_materia_source();
	tester_42();
	out_of_bound_test();
	create_test();
	equip_unequip_test();
	deep_copy_test();
}

