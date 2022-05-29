/*
 * Room.h
 *
 *  Created on: 19.02.2022
 *      Author: Noyavy
 */



#ifndef ROOM_H_
#define ROOM_H_

#include "Interactable.h"
#include "Item.h"
#include <list>
#include <utility>

class Room {
	int sizex;
	int sizey;
	std::list<Interactable> inters;
	std::list<Item> items;
public:
	Room();
	Room(int sizex, int sizey);
	std::pair<Interactable, bool> getInteractable(int x, int y);
	std::pair<Item, bool> getItem(int x, int y);
	void addInteractable(Interactable inter);
	void addItem(Item item);
	//int location[3];
	bool collide(int x, int y);
};

#endif /* ROOM_H_ */
