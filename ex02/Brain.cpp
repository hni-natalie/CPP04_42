/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:13:45 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 16:22:30 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor is called.\n";
	for (int i=0; i < 100; i++) {
		std::stringstream ss;
		ss << "General Idea " << i;	
		_ideas[i] = ss.str();
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor is called.\n";
}

Brain::Brain(const Brain& other) {
	std::cout << "Copy constructor is called.\n";
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}

	std::cout << "Copy assignment operator is called.\n";
	return *this;
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index < 0 || index > 100)
		std::cout << "Error: Index must be 0 - 99\n";
	_ideas[index] = idea;
}

std::string& Brain::getIdea(int index) {	
	static std::string empty = "";
	if (index < 0 || index > 100) {
		std::cout << "Error: Index must be 0 - 99\n";
		return empty;
	}
	return _ideas[index];
}