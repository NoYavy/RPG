/*
 * Room.cpp
 *
 *  Created on: 16.05.2022
 *      Author: Noyavy
 */
#include "Room.h"
Room::Room() {}
Room::Room(int sizex, int sizey) {
		this->sizex = sizex;
		this->sizey = sizey;
}

bool Room::collide(int x, int y) {
	if (x < 0 || y < 0) {return true;}
	if (x > sizex || y > sizey) {return true;}
	return false;
}
