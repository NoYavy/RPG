/*
 * Player.cpp
 *
 *  Created on: 16.05.2022
 *      Author: Noyavy
 */
/* Select which OS this is compiled on */
//#include <ncurses.h>
#include <curses.h>	/* Windows */
#include "Player.h"
Player::Player(int location[2], WINDOW stdscr) {
	this->location = location;
	this->stdscr = stdscr;
}
void Player::moveRight(){
	this->location[0]++;
	mvwprintw(stdscr, location[1], location[0], ">~>");
}
void Player::moveLeft(){
	location[0]--;
	mvwprintw(stdscr, location[1], location[0], "<~<");
}
void Player::moveDown(){
	location[1]++;
	mvwprintw(stdscr, location[1], location[0], "v~v");
}
void Player::moveUp(){
	location[1]--;
	mvwprintw(stdscr, location[1], location[0], "^~^");
}
};


