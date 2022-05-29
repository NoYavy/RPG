/*
 * Text.cpp
 *
 *  Created on: 28.05.2022
 *      Author: Noyavy
 */
 
#include "Text.h"
#include <iostream>
Text::Text(int x, int y, _win_st* stdscr, const char* text, void (*func) (void)) {
	posx = x;
	posy = y;
	this->stdscr = stdscr;
	this->text = text;
	invoke = func;
}

void Text::render() {
	mvwprintw(stdscr, posy, posx, text);
}

void Text::interact(Player* pl) {
	std::cout << "intern";
	invoke();
}
