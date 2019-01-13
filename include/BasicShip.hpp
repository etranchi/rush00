/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BasicShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:57:00 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/13 18:13:29 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICSHIP_HPP
#define BASICSHIP_HPP
#include <curses.h>
#include <iostream>
#include "Missile.hpp"
#include "Game.hpp"
#include "AEnemy.hpp"

/**
 * Basic ship, move forward and take one shot to kill
 */

#define BASIC_SKIN '<'
#define BASIC_LIFE 1
#define BASIC_IDLE_TIME 600


class BasicShip : public AEnemy {
	public: 
		BasicShip();
		BasicShip(int y, int x);
		BasicShip(BasicShip const &src); 
		~BasicShip(); 

		BasicShip	&operator=(BasicShip const &rhs);

		virtual void behavior(Game &);
	private:
};

#endif
