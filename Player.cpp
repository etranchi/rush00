/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:37:35 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 14:37:37 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() : _x(), _y(){

}

Player::Player(int x, int y) : _x(x), _y(y), _alive(true), _display(ACS_BOARD){
    this->_x = x;
    this->_y = y;
}

Player::~Player() {

}

void Player::move(int y) {
    this->_y += y;
    if (this->_y < 0 || this->_y > LINES) {
        this->_y -= y;
    }
}

void Player::tick() {

}

bool Player::isAlive() {
    return this->_alive;
}

int Player::getX() {
    return this->_x;
}

int Player::getY() {
    return this->_y;
}

chtype Player::getDisplay() {
    return this->_display;
}

void Player::fire() {
    std::cout << "FIRE" << std::endl;
}