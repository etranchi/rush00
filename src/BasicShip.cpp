/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:57:15 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/13 15:56:21 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BasicShip.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~
// CONSTRUCTOR / DESTRUCTOR
// ~~~~~~~~~~~~~~~~~~~~~~~~~~

BasicShip::BasicShip() : AEnemy((rand() % (LINES - 2)) + 1  , COLS - 2	, BASIC_SKIN, BASIC_LIFE, BASIC_IDLE_TIME) {

}

BasicShip::BasicShip(int y, int x) : AEnemy(y, x, BASIC_SKIN, BASIC_LIFE, BASIC_IDLE_TIME) {

}

BasicShip::BasicShip(BasicShip const &src) {
	*this = src;
}

BasicShip::~BasicShip() {

}

// ~~~~~~~~~~
// OPERATORS
// ~~~~~~~~~~

BasicShip &	BasicShip::operator=(BasicShip const &rhs)
{
	AEnemy::operator=(rhs);
	return *this;
}

// ~~~~~~~~~~
// OTHER
// ~~~~~~~~~~

void BasicShip::behavior(Game &g) {
	this->move(this->getY(), this->getX() - 1);
	int ra = (rand() % 10); 
	if (ra == 0){
		Missile *m = new Missile(this->getY(), this->getX(), 1);
		g.addMissile(m);
	}
}
