/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:57:00 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/12 20:51:13 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICSHIP_HPP
#define BASICSHIP_HPP

/**
 * Basic ship, move forward and take one shot to kill
 */

#define BASIC_SKIN '<'
#define BASIC_LIFE 1
#define BASIC_SPEED 1

#include "AEnemy.hpp"

class BasicShip : public AEnemy {
	public: 
		BasicShip();
		BasicShip(int y, int x);
		BasicShip(BasicShip const &src); 
		~BasicShip(); 

		BasicShip	&operator=(BasicShip const &rhs);

		virtual void move(int const y, int const x);
		virtual void tick(Game &game);
	private:
};

#endif
