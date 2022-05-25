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
void Player::moveRight(){
	locx++;
	render(locx, locy, '>');
}
void Player::moveLeft(){
	locx--;
	if (locx < 1) {locx = 1;}
	render(locx, locy, '<');
}
void Player::moveDown(){
	locy++;
	render(locx, locy, 'v');
}
void Player::moveUp(){
	locy--;
	if (locy < 0) {locy = 0;}
	render(locx, locy, '^');
}


