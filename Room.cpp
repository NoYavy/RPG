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
	for (auto wall : walls) {
		if ((x >= wall.startx && x <= wall.endx) && (y >= wall.starty && y <= wall.endy)) {return true;}
	}
	return false;
}

Interactable* Room::getInteractable(int x, int y) {
	for (auto inter : inters) {
		if (inter->getxPos() == x && inter->getyPos() == y) {
			return inter;
		}
	}
	return NULL;
}

void Room::addInteractable(Interactable* inter) {
	this->inters.push_back(inter);
}

void Room::addWall(int startx, int starty, int endx, int endy) {
	Wall newwall = {
		startx,
		starty,
		endx,
		endy
	};
	this->walls.push_back(newwall);
}

void Room::render() {
	for (auto wall : walls) {
		for (int i = wall.startx; i <= wall.endx; i++) {
			for (int j = wall.starty; j <= wall.endy; j++) {
				mvprintw(j, i, "#");
			}
		}
	}
}
