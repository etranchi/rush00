/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:56 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 14:55:54 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Game.hpp"


Game::Game() : _width(), _height(), _win() {

}

Game::Game(WINDOW *w, int width, int height) : _width(width), _height(height), _win(w) {

}


Game::Game(Game const & ref) {
    *this = ref;
}

Game::~Game() {

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

