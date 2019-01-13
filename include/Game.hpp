/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:53 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/13 02:43:03 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <curses.h>

// #include "AEnemy.hpp"
class AEnemy;

class Game {
    private:
        int     _width;
        int     _height;
        WINDOW  *_win;
        AEnemy  *_enemies;

    public:
        Game();
        Game(WINDOW *w, int width, int height);
        Game(Game const & ref);
        ~Game();

        Game & operator=(Game const & rhs);

        WINDOW *getWin(void);
};

#endif //GAME_HPP
