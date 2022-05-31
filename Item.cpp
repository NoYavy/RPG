/*
 * Item.cpp
 *
 *  Created on: 29.05.2022
 *      Author: Noyavy
 */

#include "Item.h"
#include "Player.h"

#include <iostream>

Item::Item() {}
Item::Item(int x, int y, _win_st* stdscr) {
	posx = x;
	posy = y;
	this->stdscr = stdscr;
}

void Item::interact(Player* pl) {
	pl->addtoInventory(this);
	pl->getRoom()->removeInteractable(this);
}

void Item::render() {
	mvwprintw(stdscr, posy, posx, "X");
}
