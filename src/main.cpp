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

void loop(Game *g);

void read_inputs(Game *g) {
    int ch = getch();
    
    switch (ch)
    {
        case ERR: 
            break;
        case KEY_UP:
            g->player->move(-1, 0);
            break;
        case KEY_DOWN:
            g->player->move(1, 0);
            break;
        case KEY_RIGHT:
            g->player->move(0,1);
        break;
        case KEY_LEFT:
            g->player->move(1,0);
        break;
        case KEY_ENTER:
            loop(g);
            break;
        case 27:
            clear();

            endwin();
            exit(0);
        default:
            endwin();
            break;
    }
    return;
}


void render_player(Player *player) {
    move(player->getY(), player->getX());
    addch(player->getDisplay());
}

void loop(Game *g) {
    while(1) {

        read_inputs(g);
        clear();
        render_player(g->player);
        refresh();
        
    }
    
}

Game *initGame(void) {
    Game* g = new Game(initscr(), COLS, LINE_MAX - 3);
    noecho();
    // cbreak();
    keypad(g->getWin(), TRUE);
    nodelay(g->getWin(), TRUE);
    wborder(g->getWin(), ACS_DIAMOND, ACS_DIAMOND, '-', '-', '+', '+', '+', '+');
    return g;
}

int main(void) {
    Game *g = initGame();
    Player *p = new Player();
    g->addPlayer(p);
  // move(LINES / 2, COLS /2 );  // Déplace le curseur tout en bas à droite de l'écran
    loop(g);
    return 0;
}
