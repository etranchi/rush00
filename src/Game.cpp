/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:56 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/13 17:21:05 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <curses.h>
// ~~~~~~~~~~~~~~~~~~~~~~~~~~
// CONSTRUCTOR / DESTRUCTOR
// ~~~~~~~~~~~~~~~~~~~~~~~~~~

Game::Game() : _width(), _height(), _win(), _enemies(0), _missiles(0), _exit(false) {

}

Game::Game(WINDOW *w, int width, int height) : _width(width), _height(height), _win(w), _player(Player(5, 5)), _enemies(0), _missiles(0), _exit(false), _idleTime(2000), _lastTimePlayed(getTimeInMs()){

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


void Game::checkCollision() {
	int p_y = this->_player.getY();
	int p_x = this->_player.getX();

	for(int j = 0; j < (int)this->_enemies.size(); j++) {
		int e_y = this->_enemies[j]->getY();
		int e_x = this->_enemies[j]->getX();

		for (int i = 0; i < (int)this->_missiles.size(); i++ ) {
			int m_y = this->_missiles[i]->getY();
			int m_x = this->_missiles[i]->getX();
			// Missile <-> Enemy
			if (e_x == m_x && e_y == m_y) {
				delete this->_missiles[i];
				this->_missiles.erase(this->_missiles.begin() + i);
				delete this->_enemies[j];
				this->_enemies.erase(this->_enemies.begin() + j);
			}
		}
		// Player <-> Enemy
		if (e_y == p_y && e_x == p_x) {
			this->_exit = true;
		}
		// Enemy <-> left screen side
		if (e_x <= 0) {
			this->_exit = true;
		}
	}
	for (int i = 0; i < (int)this->_missiles.size(); i++ ) {
		// Missile <-> right screen side 
		if (this->_missiles[i]->getX() > this->_width) {
			delete this->_missiles[i];
			this->_missiles.erase(this->_missiles.begin() + i);
		}
	}
}

void Game::updateAll() {
	for (int j = 0; j < (int)this->_enemies.size(); j++) {
		this->_enemies[j]->tick(*this);
	}

	checkCollision();

	for (int i = 0; i < (int)this->_missiles.size(); i++) {
		this->_missiles[i]->tick(*this);
	}
}

void Game::printAll() {
	this->_player.print();

	for (int j = 0; j < (int)this->_enemies.size(); j++) {
		this->_enemies[j]->print();
	}

	for (int i = 0; i < (int)this->_missiles.size(); i++) {
		this->_missiles[i]->print();
	}
}

void Game::getUserInput() {
	char userInput = getch();

	switch(userInput) {
		case 'w':
		case 'W':
		// case KEY_UP :
			this->_player.move(this->_player.getY() - 1, this->_player.getX());
			break;

		case 'a':
		case 'A':
		// case KEY_LEFT :
			this->_player.move(this->_player.getY(), this->_player.getX() - 1);
			break;

		case 's':
		case 'S':
		// case KEY_DOWN :
			this->_player.move(this->_player.getY() + 1, this->_player.getX());
			break;

		case 'd':
		case 'D':
		// case KEY_RIGHT :
			this->_player.move(this->_player.getY(), this->_player.getX() + 1);
			break;

		case ' ':
			// this->_player.fire(); // TODO : Do we need a fire function ?
			this->addMissile();
			break;

		case 'q':
		case 'Q':
			this->_exit = true;
			break;
	}
}

void Game::addMissile() {
	Missile *m = new Missile(this->_player.getY(), this->_player.getX(), 0);
	std::deque<Missile *>::iterator it = find(this->_missiles.begin(), this->_missiles.end(), m);
    if (it == this->_missiles.end()) {
        this->_missiles.push_back(m);
    }
    return ;
}

void Game::addEnemie() {
	BasicShip *b = new BasicShip();
	std::deque<BasicShip *>::iterator it = find(this->_enemies.begin(), this->_enemies.end(), b);
    if (it == this->_enemies.end()) {
        this->_enemies.push_back(b);
    }
    return ;
}

void Game::tick() {
	long int currentTime;

	currentTime = Game::getTimeInMs();
	if (this->_lastTimePlayed + this->_idleTime <= currentTime) {
		this->_lastTimePlayed = currentTime;
		this->addEnemie();
	}
}

long int Game::getTimeInMs() {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return ms;
}

