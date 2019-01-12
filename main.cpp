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
#include "Player.hpp"
void loop(Game *g);



void read_inputs(Game *g) {
    int ch = getch();
    
    switch (ch)
    {
        case ERR: 
            break;
        case KEY_UP:
            g->player->move(1);
            exit(0);
        case KEY_DOWN:
            g->player->move(-1);
        case KEY_RIGHT:
            g->player->fire();
        case KEY_ENTER:
            loop(g);
        default:
            endwin();
    }
    return;
}


void render_player(Player *player) {
    move(player->getY(), player->getX());
    addch(player->getDisplay());
}

void loop(Game *g) {
    while(g->player->isAlive()) {
        read_inputs(g);
        render_player(g->player);
        refresh();
        
    }
    
}

Game *initGame(void) {
    Game* g = new Game(initscr(), COLS, LINE_MAX - 3);
    noecho();
    cbreak();
    nodelay(g->getWin(), TRUE);
    wborder(g->getWin(), ACS_DIAMOND, ACS_DIAMOND, '-', '-', '+', '+', '+', '+');
    return g;
}

int main(void) {
    Game *g = initGame();
    Player *p = new Player(10, LINES / 2);
    g->addPlayer(p);
  // move(LINES / 2, COLS /2 );  // Déplace le curseur tout en bas à droite de l'écran
    loop(g);
    return 0;
}

