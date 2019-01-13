/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 04:14:28 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/13 04:57:58 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~
// CONSTRUCTOR / DESTRUCTOR
// ~~~~~~~~~~~~~~~~~~~~~~~~~~

Missile::Missile() : AEnemy(0, 0, MISSILE_SKIN, MISSILE_LIFE, MISSILE_IDLE_TIME), _origin(ORIGIN_PLAYER) {

}

Missile::Missile(int y, int x, int origin) : AEnemy(y, x, MISSILE_SKIN, MISSILE_LIFE, MISSILE_IDLE_TIME), _origin(origin) {

}

Missile::Missile(Missile const &src) {
	*this=src;
}

Missile::~Missile() {

}

// ~~~~~~~~~~
// OPERATORS
// ~~~~~~~~~~

Missile &	Missile::operator=(Missile const &rhs)
{
	AEnemy::operator=(rhs);
	this->_origin = rhs._origin;
	return *this;
}

// ~~~~~~~~~~
// OTHER
// ~~~~~~~~~~

int Missile::getOrigin() const {
	return this->_origin;
}
void Missile::behavior(Game &game) {
	(void)game;
	if (this->_origin == ORIGIN_PLAYER) {
		this->move(this->getY(), this->getX() + 1);
	} else if (this->_origin == ORIGIN_ENEMY) {
		this->move(this->getY(), this->getX() - 1);
	}
}
