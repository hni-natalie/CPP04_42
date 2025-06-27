/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:13:33 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/27 14:03:13 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("anonymous") {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character Default Constructor is called.\n";
}

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << _name << " Character Constructor is called.\n";
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] == NULL)
			_inventory[i] = NULL;
		else
			_inventory[i] = other._inventory[i]->clone();
	}
	std::cout << "Character Copy Constructor is called.\n";
}

Character& Character::operator=(const Character& other) {
	std::cout << "Character Copy Assignment Operator is called.\n";
	if (this != &other)
	{
		for (int i = 0 ; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}

	return *this;
}

Character::~Character() {
	std::cout << _name << " Character Destructor is called.\n";
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _name << " equipped " << m->getType() << " at index " << i << "\n";
			return ;
		}
	}
	std::cout << _name << " is full.\n";
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 4) {
		std::cout << idx << " out of bound (0-3)\n";
		return ;
	}
	if (_inventory[idx])
	{
		std::cout << _inventory[idx]->getType() << " is removed from inventory.\n";
		_inventory[idx] = NULL;
		return ; 
	}
	std::cout << "Inventory at index " << idx << " is empty.\n";
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 4) {
		std::cout << idx << " out of bound (0-3)\n";
		return ;
	}
	if (_inventory[idx])
	{
		_inventory[idx]->use(target);
		return;
	}
	std::cout << "Inventory at index " << idx << " is empty.\n";
}

// AMateria* Character::getInventoryAddress(int i) const {
// 	if (i < 0 || i >= 4)
//         return NULL;
//     return _inventory[i];
// }
