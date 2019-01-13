/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 04:14:44 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/13 04:56:18 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_HPP
#define MISSILE_HPP

#define MISSILE_SKIN '-'
#define MISSILE_LIFE 1
#define MISSILE_IDLE_TIME 10

#define ORIGIN_PLAYER 0
#define ORIGIN_ENEMY 1


#include "AEnemy.hpp"

// Missile is a AEnemy, ok that's weird, kind of logic
// TODO : Maybe we need to rename AEnemy to something like AInteligentEntity

class Missile : public AEnemy {
	public: 
		Missile();
		Missile(int y, int x, int origin);
		Missile(Missile const &src); 
		~Missile(); 

		Missile	&operator=(Missile const &rhs);
		virtual void behavior(Game &game);

	private:
		int		_origin;
};

#endif
