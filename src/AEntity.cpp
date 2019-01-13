/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:37:49 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/13 04:15:20 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"
#include <curses.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~
// CONSTRUCTOR / DESTRUCTOR
// ~~~~~~~~~~~~~~~~~~~~~~~~~~

AEntity::AEntity() : _y(0), _x(0), _skin(' ') {

}

AEntity::AEntity(int y, int x, char skin) : _y(y), _x(x), _skin(skin) {

}

AEntity::AEntity(AEntity const &src) {
	*this = src;
}

AEntity::~AEntity() {

}

// ~~~~~~~~~~
// OPERATORS
// ~~~~~~~~~~

AEntity &	AEntity::operator=(AEntity const &rhs)
{
	this->_y = rhs._y;
	this->_x = rhs._x;
	this->_skin = rhs._skin;
	return *this;
}

// ~~~~~~~~~~
// ACCESSORS
// ~~~~~~~~~~

int AEntity::getX() const {
	return this->_x;
}

void AEntity::setX(int x) {
	this->_x = x;
}

int	AEntity::getY () const {
	return this->_y;
}
void	AEntity::setY (int y) {
	this->_y = y;
}

// ~~~~~~~~~~
// OTHER
// ~~~~~~~~~~

void AEntity::print() const {
	mvaddch(this->_y, this->_x, this->_skin);
}
