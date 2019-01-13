/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:11:53 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/13 04:50:50 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <curses.h>
#include <deque>
#include "Player.hpp"
#include "AEnemy.hpp"
#include "Missile.hpp"
#include "BasicShip.hpp"
#include <sys/time.h>

class Game {
	public:
		Game();
		Game(WINDOW *w, int width, int height);
		Game(Game const & ref);
		~Game();

		Game & operator=(Game const & rhs);

		void	updateAll();
		void    printAll();
		void    getUserInput();

		WINDOW  *getWin(void);
		bool    getExit() const;
		void 	addMissile();
		void 	addEnemie(BasicShip *);
		void 	tick();
		void 	checkCollision();
		static long int getTimeInMs();
		int 		getScore() const;
		int 		getX() const;
		int 		getY() const;
	private:
		int     _width;
		int     _height;
		WINDOW  *_win;

		Player  _player;
		std::deque<BasicShip *>	_enemies;
		std::deque<Missile *>	_missiles;
		bool    _exit;
		long int	_idleTime;
		long int	_lastTimePlayed;
};

#endif //GAME_HPP
