/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:57:15 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/12 20:51:13 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BasicShip.hpp"
#include <iostream>

BasicShip::BasicShip() : AEnemy(0, 0, BASIC_SKIN, BASIC_LIFE, BASIC_SPEED) {

}

BasicShip::BasicShip(int y, int x) : AEnemy(y, x, BASIC_SKIN, BASIC_LIFE, BASIC_SPEED) {

}

BasicShip::BasicShip(BasicShip const &src) {
	*this = src;
}

BasicShip::~BasicShip() {

}

BasicShip &	BasicShip::operator=(BasicShip const &rhs)
{
	AEnemy::operator=(rhs);
	return *this;
}

void BasicShip::move(int const y, int const x) {
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

void BasicShip::tick(Game &game) {
	(void)game;
	move(this->getY(), this->getX() - 1);
}
