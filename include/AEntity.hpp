/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:58:28 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/13 03:14:16 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
#define AENTITY_HPP

#include "Game.hpp"

class AEntity {
	public:
		AEntity();
		AEntity(int y, int x, char skin);
		AEntity(AEntity const &src); 
		virtual ~AEntity();

		AEntity	&operator=(AEntity const &rhs);

		void print() const;

		virtual void	move(int const y, int const x) = 0;
		virtual void	tick(Game &game) = 0;

		int		getX() const;
		void	setX(int _x);
		int		getY() const;
		void	setY(int y);

	private:
		int    _y;
		int    _x;
		char   _skin;
};

#endif //ENTITY_HPP
