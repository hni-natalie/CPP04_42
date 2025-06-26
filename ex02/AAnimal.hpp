/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:13:37 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 19:06:17 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		void setType(std::string& type);
		std::string getType() const;
		// pure virtual function
		virtual void makeSound() const = 0;
};

#endif