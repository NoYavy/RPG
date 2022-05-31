/*
 * Room.h
 *
 *  Created on: 19.02.2022
 *      Author: Noyavy
 */



#ifndef ROOM_H_
#define ROOM_H_

#include "Interactable.h"
#include "Text.h"
#include "Item.h"
#include <list>
#include <utility>

struct Wall {
	int startx;
	int starty;
	int endx;
	int endy;
};

class Room {
	int sizex;
	int sizey;
	std::list<Interactable*> inters;
	std::list<Wall> walls;
public:
	Room();
	Room(int sizex, int sizey);
	Interactable* getInteractable(int x, int y);
	void addInteractable(Interactable* inter);
	void removeInteractable(Interactable* inter);
	void clearInteractables();
	bool collide(int x, int y);
	void render();
	void addWall(int startx, int starty, int endx, int endy);
};

#endif /* ROOM_H_ */
