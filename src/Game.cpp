/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:56 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/13 05:05:02 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~
// CONSTRUCTOR / DESTRUCTOR
// ~~~~~~~~~~~~~~~~~~~~~~~~~~

Game::Game() : _width(), _height(), _win(), _enemies(NULL), _missiles(NULL), _exit(false) {

}

Game::Game(WINDOW *w, int width, int height) : _width(width), _height(height), _win(w), _player(Player(5, 5)), _enemies(NULL), _missiles(NULL), _exit(false) {

}

Game::Game(Game const & ref) {
	*this = ref;
}

Game::~Game() {

}

// ~~~~~~~~~~
// OPERATORS
// ~~~~~~~~~~

Game &Game::operator=(Game const & rhs) {
	this->_width = rhs._width;
	this->_height = rhs._height;
	this->_win = rhs._win;
	this->_enemies = rhs._enemies;
	return *this;
}

// ~~~~~~~~~~
// ACCESSORS
// ~~~~~~~~~~

WINDOW * Game::getWin(void) {
	return this->_win;
}

bool	Game::getExit () const {
	return this->_exit;
}

// ~~~~~~~~~~
// OTHER
// ~~~~~~~~~~

void Game::updateAll() {
	if (this->_missiles) {
		this->_missiles->tick(*this);
	}
	// TODO : call tick of all enemies and all bullet
}

void Game::printAll() {
	this->_player.print();
	if (this->_missiles) {
		this->_missiles->print();
	}
	// TODO : print all enemies and all bullet
}

void Game::getUserInput() {
	char userInput = getch();

	switch(userInput) {
		case 'w':
		case 'W':
			this->_player.move(this->_player.getY() - 1, this->_player.getX());
			break;

		case 'a':
		case 'A':
			this->_player.move(this->_player.getY(), this->_player.getX() - 1);
			break;

		case 's':
		case 'S':
			this->_player.move(this->_player.getY() + 1, this->_player.getX());
			break;

		case 'd':
		case 'D':
			this->_player.move(this->_player.getY(), this->_player.getX() + 1);
			break;

		case ' ':
			// this->_player.fire(); // Do we need a fire function ?
			// TODO : add new Missile to a real list
			this->_missiles = new Missile(this->_player.getY(), this->_player.getX() + 1, ORIGIN_PLAYER);
			break;

		case 'q':
		case 'Q':
			this->_exit = true;
			break;
	}
}
