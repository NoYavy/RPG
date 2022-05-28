/*
 * Room.cpp
 *
 *  Created on: 16.05.2022
 *      Author: Noyavy
 */

#include "Room.h"
#include <iostream>

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

std::pair<Interactable, bool> Room::getInteractable(int x, int y) {
	for (auto inter : inters) {
		if (inter.getxPos() == x && inter.getyPos() == y) {
			return std::make_pair(inter, true);
		}
	}
	return std::make_pair(Interactable(), false);
}

void Room::addInteractable(Interactable inter) {
	this->inters.push_back(inter);
}
