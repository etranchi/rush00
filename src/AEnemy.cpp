/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:05:24 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/13 02:53:11 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEnemy.hpp"
#include <sys/time.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~
// CONSTRUCTOR / DESTRUCTOR
// ~~~~~~~~~~~~~~~~~~~~~~~~~~

AEnemy::AEnemy() : AEntity(0, 0, '<'), _life(1), _idleTime(1000), _lastTimePlayed(getTimeInMs()) {

}

AEnemy::AEnemy(int y, int x, char skin, int life, int idleTime) :	AEntity(y, x, skin),
																	_life(life),
																	_idleTime(idleTime),
																	_lastTimePlayed(getTimeInMs()) {

}

AEnemy::AEnemy(AEnemy const &src) {
	*this = src;
}

AEnemy::~AEnemy() {

}

// ~~~~~~~~~~
// OPERATORS
// ~~~~~~~~~~

AEnemy &	AEnemy::operator=(AEnemy const &rhs)
{
	AEntity::operator=(rhs);
	this->_life = rhs._life;
	this->_idleTime = rhs._idleTime;
	this->_lastTimePlayed = rhs._lastTimePlayed;
	return *this;
}

// ~~~~~~~~~~
// OTHER
// ~~~~~~~~~~

void AEnemy::move(int const y, int const x) {
	if (y < -1) {
		this->setY(-1);
	} else {
		this->setY(y);
	}

	if (x < -1) {
		this->setX(-1);
	} else {
		this->setX(x);
	}
}

void AEnemy::tick(Game &game) {
	long int currentTime;

	(void)game;
	currentTime = AEnemy::getTimeInMs();
	if (this->_lastTimePlayed + this->_idleTime <= currentTime) {
		this->_lastTimePlayed = currentTime;
		this->behavior(game);
	}
}

long int AEnemy::getTimeInMs() {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return ms;
}
