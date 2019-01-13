/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:53 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 14:50:25 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <curses.h>
#include "Player.hpp"
#ifndef GAME_H
#define GAME_H
class Game {
    private:
        int _width;
        int _height;
        WINDOW *_win;
    public:
        Game();
        Game(WINDOW *w, int width, int height);
        Game(Game const & ref);
        ~Game();

        Game & operator=(Game const & rhs);
        void addPlayer(Player *);
        WINDOW *getWin(void);
        Player *player;
};

#endif //GAME_H
