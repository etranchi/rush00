/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:56 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 13:11:57 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Game.hpp"


Game::Game(WINDOW *w, int width, int height) : _win(w), _width(width), _height(height) {

}

Game::~Game() {

}

Game::Game() : _win(), _width(), _height() {

}

Game::Game(Game const & ref) {
    *this = ref;
}

Game &Game::operator=(Game const & rhs) {
    this->_width = rhs._width;
    this->_height = rhs._height;
    this->_win = rhs._win;
    return *this;
}

WINDOW * Game::getWin(void) {
    return this->_win;
}

void Game::addPlayer(Player *p) {
    this->player = p;
}

