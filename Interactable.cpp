/*
 * Interactable.cpp
 *
 *  Created on: 26.05.2022
 *      Author: Noyavy
 */

#include "Interactable.h"

Interactable::Interactable() {}
Interactable::Interactable(int x, int y, _win_st* stdscr) {
	posx = x;
	posy = y;
	this->stdscr = stdscr;
}

int Interactable::getxPos() {
	return posx;
}
int Interactable::getyPos() {
	return posy;
}

void Interactable::render() {
	mvwprintw(stdscr, posy, posx, "0");
}

void Interactable::interact(Player* pl) {
	
}
