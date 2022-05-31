/*
 * Portal.cpp
 *
 *  Created on: 29.05.2022
 *      Author: Noyavy
 */

#include "Portal.h"
#include "Player.h"

#include <iostream>

Portal::Portal() {}
Portal::Portal(int x, int y, _win_st* stdscr, int targetx, int targety) {
	posx = x;
	posy = y;
	this->stdscr = stdscr;
	this->targetx = targetx;
	this->targety = targety;
}

void Portal::interact(Player* pl) {
	pl->teleport(targetx, targety);
}

void Portal::render() {
	mvwprintw(stdscr, posy, posx, "0");
}
