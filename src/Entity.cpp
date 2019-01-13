#include "Entity.hpp"

Entity::Entity() : _y(0), _x(0), _display(' ') {

}


Entity::Entity(int y, int x, chtype display) : _y(y), _x(x), _display(display) {

}

//Entity::Entity(Entity const &src) {
//	*this = src;
//}

Entity::~Entity() {

}

// ~~~~~~~~~~
// OPERATORS
// ~~~~~~~~~~

// Entity &	Entity::operator=(Entity const &rhs)
// {
// 	this->_y = rhs._y;
// 	this->_x = rhs._x;
// 	this->_display = rhs._display;
	//return *this;
//}

// ~~~~~~~~~~
// ACCESSORS
// ~~~~~~~~~~

int Entity::getX() const {
	return this->_x;
}

void Entity::setX(int x) {
	this->_x = x;
}

int	Entity::getY () const {
	return this->_y;
}
void	Entity::setY (int y) {
	this->_y = y;
}

chtype	Entity::getDisplay () const {
	return this->_display;
}


// ~~~~~~~~~~
// OTHER
// ~~~~~~~~~~

// void Entity::print() const {
// 	mvaddch(this->_y, this->_x, this->_skin);
//}