/*
 * Player.cpp
 *
 *  Created on: 16.05.2022
 *      Author: Noyavy
 */

/* Select which OS this is compiled on */
#include <ncurses.h>
//#include <curses.h>	/* Windows */
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int locx, int locy, _win_st* stdscr) {
	this->location[0] = locx;
	this->location[1] = locy;
	this->stdscr = stdscr;
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
	location[0]++;
	render(location[0], location[1], '>');
}
void Player::moveLeft(){
	location[0]--;
	if (location[0] < 1) {location[0] = 1;}
	render(location[0], location[1], '<');
}
void Player::moveDown(){
	location[1]++;
	render(location[0], location[1], 'v');
}
void Player::moveUp(){
	location[1]--;
	if (location[1] < 0) {location[1] = 0;}
	render(location[0], location[1], '^');
}


