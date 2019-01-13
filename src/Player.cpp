#include "Player.hpp"

Player::Player() : Entity(LINES / 2, 10, '>') {

}

Player::~Player() {

}


// int Player::getX() const {
// 	return this->_x;
// }

// int Player::getY() const {
// 	return this->_y;
// }

void Player::move(int y, int x) {
	int n_x = this->getX() + x;
	int n_y = this->getY() + y;
	this->setX(n_x);
	this->setY(n_y);
}



