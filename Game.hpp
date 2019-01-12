/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:53 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 13:11:53 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <curses.h>

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
    Game & operator=(Game const & rhs);
    ~Game();
    WINDOW *getWin(void);
};

#endif //GAME_H
