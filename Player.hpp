/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:37:27 by etranchi          #+#    #+#             */
/*   Updated: 2019/01/12 14:37:28 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"
#include <iostream>
#include <curses.h>
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int _y;
    int _x;
    bool _alive;
    chtype _display;
public:
    Player();
    Player(int x, int y);
    Player(Player const & ref);
    ~Player();
    void move(int y);
    void fire();
    void tick();
    bool isAlive();
    int getX();
    int getY();
    chtype getDisplay();
};

#endif //PLAYER_H
