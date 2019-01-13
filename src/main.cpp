/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:32:51 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/13 21:13:42 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <curses.h>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "BasicShip.hpp"


Game *initGame(void) {
	initscr();
	WINDOW *game_win = subwin(stdscr, LINES, COLS , 0, 0);
	Game* g = new Game(game_win, COLS, LINES);

	raw();							// Line buffering disabled (and disable ctrl+C)
	noecho();						// Disable echo user input
	curs_set(0);				// Hide cursor
	keypad(stdscr, TRUE);		// We can get arrow key, F1, F2...
	nodelay(stdscr, TRUE);		// Asking user input doesn't block
	start_color();				// Allow use of color
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
		mvwprintw(g->getWin(), 1, 1, "Score : " );
		std::string score = std::to_string(g->getScore());
		mvwprintw(g->getWin(), 1, 9, score.c_str());
		mvwprintw(g->getWin(), 1, 12, "| y : " );
		std::string y = std::to_string(g->getY());
		mvwprintw(g->getWin(), 1, 18, y.c_str());
		mvwprintw(g->getWin(), 1, 20, "| x : " );
		std::string x = std::to_string(g->getX());
		mvwprintw(g->getWin(), 1, 26, x.c_str());
		


		refresh();
	}

	// Stoping ncurses
	curs_set(1);
	endwin();

	std::cout << "\e[31m" << "Game over" << "\e[0m" << std::endl;
	std::cout << "score: " << g->getScore() << std::endl;
	delete g;

	return 0;
}

