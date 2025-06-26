/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:11:21 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/26 17:58:40 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const;
};

#endif