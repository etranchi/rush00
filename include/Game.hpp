/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:53 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/13 04:11:56 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <curses.h>

#include "AEnemy.hpp"
#include "Player.hpp"

class Game {
	public:
		Game();
		Game(WINDOW *w, int width, int height);
		Game(Game const & ref);
		~Game();

		Game & operator=(Game const & rhs);

		void    printAll();
		void    getUserInput();

		WINDOW  *getWin(void);
		bool    getExit() const;
		
	private:
		int     _width;
		int     _height;
		WINDOW  *_win;

		Player  _player;
		AEnemy  *_enemies;

		bool    _exit;
};

#endif //GAME_HPP
