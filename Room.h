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

class Room {
	int sizex;
	int sizey;
	std::list<Interactable*> inters;
public:
	Room();
	Room(int sizex, int sizey);
	Interactable* getInteractable(int x, int y);
	void addInteractable(Interactable* inter);
	//int location[3];
	bool collide(int x, int y);
	void render();
};

#endif /* ROOM_H_ */
