/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:53:07 by fmuller           #+#    #+#             */
/*   Updated: 2019/01/12 20:50:45 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENEMY_HPP
#define AENEMY_HPP

#include "AEntity.hpp"

class AEnemy : public AEntity {
	public:
		AEnemy();
		AEnemy(int y, int x, char skin, int life, int speed);
		AEnemy(AEnemy const &src); 
		~AEnemy();

		AEnemy	&operator=(AEnemy const &rhs);
		
	private:
		int	_life;
		int	_speed;
};

#endif
