/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:53:07 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/13 02:50:26 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENEMY_HPP
#define AENEMY_HPP

#include "AEntity.hpp"

class AEnemy : public AEntity {
	public:
		AEnemy();
		AEnemy(int y, int x, char skin, int life, int idleTime);
		AEnemy(AEnemy const &src); 
		~AEnemy();

		AEnemy	&operator=(AEnemy const &rhs);
		
		virtual void move(int const y, int const x);
		virtual void tick(Game &game);
		virtual void behavior(Game &game) = 0;

		static long int getTimeInMs();

	private:
		int			_life;
		long int	_idleTime;
		long int	_lastTimePlayed;
};

#endif
