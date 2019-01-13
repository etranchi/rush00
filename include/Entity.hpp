/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:58:28 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 12:58:30 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <iostream>
#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
    private:
        int _y;
        int _x;
        chtype _display;
    public:
    	Entity();
    	Entity(int y, int x, chtype display);
        virtual ~Entity();
        virtual void move(int y, int x) = 0;
        // virtual void tick();
        virtual int getX() const;
        virtual void setX(int x);
        virtual int getY() const;
        virtual void setY(int y);
        virtual chtype getDisplay() const;
};

#endif //ENTITY_H

