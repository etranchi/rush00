/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:53 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 20:40:46 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <curses.h>

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

        WINDOW *getWin(void);
};

#endif //GAME_HPP
