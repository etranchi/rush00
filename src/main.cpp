/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:32:51 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/13 15:59:59 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <curses.h>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "BasicShip.hpp"


Game *initGame(void) {
	Game* g = new Game(initscr(), COLS, LINE_MAX);
	raw();							// Line buffering disabled (and disable ctrl+C)
	noecho();						// Disable echo user input
	curs_set(0);					// Hide cursor
	keypad(g->getWin(), TRUE);		// We can get arrow key, F1, F2...
	nodelay(g->getWin(), TRUE);		// Asking user input doesn't block
	start_color();					// Allow use of color

	return g;
}

bool is_game_end(char user_input) {
	if (user_input == 'q' || user_input == 'Q') {
		return true;
	}
	return false;
}

int main(void) {
	Game *g = initGame();
	
	while (!g->getExit()) {
		// Get user input
		g->getUserInput();

		// Update
		g->updateAll();
		g->tick();

		// Render Display
		clear();
		g->printAll();
		refresh();
	}

	curs_set(1);
	endwin();
	return 0;
}

