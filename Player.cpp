/*
 * Player.cpp
 *
 *  Created on: 16.05.2022
 *      Author: Noyavy
 */

#include <ncurses.h>
#include "Player.h"
#include "Room.h"
#include <iostream>
using namespace std;

Player::Player(int locx, int locy, _win_st* stdscr, Room rm) {
	this->locx = locx;
	this->locy = locy;
	this->stdscr = stdscr;
	this->currroom = rm;
}
void Player::render(int x, int y, char pose) {
	switch (pose) {
		case '~':
			mvwprintw(stdscr, y, x-1, ">~<");
			break;
		case '>':
			mvwprintw(stdscr, y, x-1, ">~>");
			break;
		case '<':
			mvwprintw(stdscr, y, x-1, "<~<");
			break;
		case 'v':
			mvwprintw(stdscr, y, x-1, "v~v");
			break;
		case '^':
			mvwprintw(stdscr, y, x-1, "^~^");
			break;
	}
}
void Player::render(char pose) {render(locx, locy, pose);}
void Player::moveRight(){
	if (!currroom.collide(locx+2, locy)) {locx++;}
	
	render(locx, locy, '>');
}
void Player::moveLeft(){
	if (!currroom.collide(locx-2, locy)) {locx--;}
	
	render(locx, locy, '<');
}
void Player::moveDown(){
	if (!currroom.collide(locx, locy+1)) {locy++;}
	
	render(locx, locy, 'v');
}
void Player::moveUp(){
	if (!currroom.collide(locx, locy-1)) {locy--;}	
	render(locx, locy, '^');
}

void Player::interact() {
		std::pair<Interactable, bool> inter = currroom.getInteractable(locx, locy);
		if (inter.second) {
			inter.first.interact(this);
		}
}


