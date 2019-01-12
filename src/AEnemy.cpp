/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:05:24 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/12 20:51:13 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEnemy.hpp"
#include <iostream>

AEnemy::AEnemy() : AEntity(0, 0, '<'), _life(1), _speed(1) {

}

AEnemy::AEnemy(int y, int x, char skin, int life, int speed) : AEntity(y, x, skin), _life(life), _speed(speed) {

}

AEnemy::AEnemy(AEnemy const &src) {
	*this = src;
}

AEnemy::~AEnemy() {

}

AEnemy &	AEnemy::operator=(AEnemy const &rhs)
{
	AEntity::operator=(rhs);
	this->_life = rhs._life;
	this->_speed = rhs._speed;
	return *this;
}

