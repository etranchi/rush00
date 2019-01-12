/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:32:51 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 14:55:19 by fmuller          ###   ########.fr       */
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
    
    (void)g; // (to test compilatio, because g is unused)
    getch();
    endwin();
    
    return 0;
}

