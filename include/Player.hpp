/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 03:06:08 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/13 04:22:15 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#define PLAYER_SKIN '>'

#include "AEntity.hpp"

class Player : public AEntity {
	public: 
		Player();
		Player(int y, int x);
		Player(Player const &src); 
		~Player(); 

		Player	&operator=(Player const &rhs);

		virtual void	move(int const y, int const x);
		virtual void	tick(Game &game);
		void			fire();

	private:
		bool _alive;
};

#endif
