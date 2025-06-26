/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:13:33 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 19:06:46 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource Constructor is called.\n";
	for (int i = 0 ; i < 4; i++)
		_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "MateriaSource Copy Constructor is called.\n";
	for (int i = 0 ; i < 4; i++)
	{
		if (other._memory[i] == NULL)
			_memory[i] = NULL;
		else
			_memory[i] = other._memory[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "MateriaSource Copy Assignment Operator is called.\n";
	if (this != &other)
	{
		for (int i = 0 ; i < 4; i++)
		{
			if (_memory[i])
				delete _memory[i];
			if (other._memory[i])
				_memory[i] = other._memory[i]->clone();
			else
				_memory[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource Destructor is called.\n";
	for (int i = 0 ; i < 4; i++)
		if (_memory[i])
			delete _memory[i];
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0 ; i < 4; i++)
	{
		if (!_memory[i])
		{
			_memory[i] = materia;
			return;
		}
	}
	std::cout << "Memory is full.\n";
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0 ; i < 4; i++)
	{
		if (_memory[i] && _memory[i]->getType() == type)
		{
			std::cout << "Create new materia " << _memory[i]->getType() << "\n";
			return _memory[i]->clone();
		}
	}
	return 0;
}