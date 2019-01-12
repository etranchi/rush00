/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:32:51 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 12:32:52 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <curses.h>
#include <iostream>
#include "Game.hpp"


Game *initGame(void) {
    Game* g = new Game(initscr(), COLS, LINE_MAX);
    noecho();
    wborder(g->getWin(), ACS_DIAMOND, ACS_DIAMOND, '-', '-', '+', '+', '+', '+');
    cbreak();
    keypad(g->getWin(), TRUE);
    nodelay(g->getWin(), TRUE);
    return g;
}

int main(void) {
    Game *g = initGame();
    
    getch();
    endwin();
    
    return 0;
}

