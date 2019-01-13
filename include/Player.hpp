#include <iostream>
#include <curses.h>
#include <deque>
#include "Entity.hpp"
#ifndef PLAYER_H
# define PLAYER_H

class Player : public Entity
{
public:
	Player();
	~Player();
	void move(int y, int x);
};

#endif