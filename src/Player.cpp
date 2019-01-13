/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 03:05:51 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/13 04:22:32 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~
// CONSTRUCTOR / DESTRUCTOR
// ~~~~~~~~~~~~~~~~~~~~~~~~~~

Player::Player() : AEntity(0, 0, PLAYER_SKIN), _alive(true) {

}

Player::Player(int y, int x) : AEntity(y, x, PLAYER_SKIN), _alive(true) {

}

Player::Player(Player const &src) {
	*this = src;
}

Player::~Player() {

}

// ~~~~~~~~~~
// OPERATORS
// ~~~~~~~~~~

Player &	Player::operator=(Player const &rhs)
{
	AEntity::operator=(rhs);
	return *this;
}

// ~~~~~~~~~~
// OTHER
// ~~~~~~~~~~

void Player::move(int const y, int const x) {
	if (y < 0) {
		this->setY(0);
	} else {
		this->setY(y);
	}

	if (x < 0) {
		this->setX(0);
	} else {
		this->setX(x);
	}
}

void Player::tick(Game &game) {
	(void)game;
}

void Player::fire() {
	// TODO : Delte this line (here because: "private field '_alive' is not used")
	(void)this->_alive;
}
