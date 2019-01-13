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
#include <curses.h>
// ~~~~~~~~~~~~~~~~~~~~~~~~~~
// CONSTRUCTOR / DESTRUCTOR
// ~~~~~~~~~~~~~~~~~~~~~~~~~~

Game::Game() : _width(), _height(), _win(), _enemies(0), _missiles(0), _exit(false) {

}

Game::Game(WINDOW *w, int width, int height) : _width(width), _height(height), _win(w), _enemies(0), _missiles(0), _exit(false), _idleTime(2000), _lastTimePlayed(getTimeInMs()){

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

int Game::getScore() const {
	return this->_player.getScore();
}
int Game::getX() const {
	return this->_player.getX();
}
int Game::getY() const {
	return this->_player.getY();
}

// ~~~~~~~~~~
// OTHER
// ~~~~~~~~~~


void Game::checkCollision() {
	int p_y = this->_player.getY();
	int p_x = this->_player.getX();
	int j = -1;

	while (++j < (int)this->_enemies.size()) {
		int e_y = this->_enemies[j]->getY();
		int e_x = this->_enemies[j]->getX();
		int i = -1;
		while (++i < (int)this->_missiles.size()) {
			int m_y = this->_missiles[i]->getY();
			int m_x = this->_missiles[i]->getX();
			if (e_x == m_x && e_y == m_y) {
				this->_missiles.erase(this->_missiles.begin() + i);
				this->_enemies.erase(this->_enemies.begin() + j);
				this->_player.putScore(10);
			}
		}
		if (e_y == p_y && e_x == p_x) {
			this->_exit = true;
		}
		if (e_x <= 0) {
			this->_exit = true;
		}
	}
}

void Game::updateAll() {
	int j = -1;
	while (++j < (int)this->_enemies.size()) {
		this->_enemies[j]->tick(*this);
	}

	checkCollision();

	int i = -1;
	while (++i < (int)this->_missiles.size()) {
		this->_missiles[i]->tick(*this);
	}

	

	// TODO : call tick of all enemies and all bullet
}

void Game::printAll() {
	this->_player.print();
	int i = -1;

	while (++i < (int)this->_missiles.size()) {
		this->_missiles[i]->print();
	}

	int j = -1;

	while (++j < (int)this->_enemies.size()) {
		this->_enemies[j]->print();
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

		case 'd' :
		case 'D':
		// case KEY_RIGHT :
			this->_player.move(this->_player.getY(), this->_player.getX() + 1);
			break;

		case ' ':
			// this->_player.fire(); // Do we need a fire function ?
			// TODO : add new Missile to a real list
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

void Game::addEnemie(BasicShip *b) {
	int ra = (rand() % 5);
	if (ra == 0) {
		BasicShip *b1 = new BasicShip(b->getY() - 1, b->getX());
		this->addEnemie(b1);
		BasicShip *b2 = new BasicShip(b->getY() - 1, b->getX() - 1);
		this->addEnemie(b2);
		BasicShip *b3 = new BasicShip(b->getY(), b->getX() - 1);
		this->addEnemie(b3);
	}
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
		BasicShip *b = new BasicShip();
		this->addEnemie(b);
	}
}

long int Game::getTimeInMs() {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return ms;
}

