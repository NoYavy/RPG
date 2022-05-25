/*
 * main.h
 *
 *  Created on: 19.02.2022
 *      Author: Noyavy
 */

#include <ncurses.h>
#include "main.h"
#include "Player.h"
#include "Room.h"
#include <iostream>
using namespace std;


void drawRoom() {
	clear();
}


int main() {
	int ch; 				/* characters typed */
	initscr();				/* Start curses mode */
	cbreak();				/* Line buffering disabled, 
							   Pass on everything to me */
	keypad(stdscr, TRUE); 	/* Activate additional keys like F1 */
	curs_set(0);			/* hide cursor */
	int row, col;
	getmaxyx(stdscr,row,col); /* IMPORTANT */
	cout << col << "|" << row << ". ";
	Room room;
	Player pl((col/2), (row/2), stdscr, room);
	
	/* set this to something you'd like */
	/*
	const int user_up = 'w'; 
	const int user_down = 's';
	const int user_left = 'a';
	const int user_right = 'd';
	*/
	/* default */
	const int user_up = KEY_UP;
	const int user_down = KEY_DOWN;
	const int user_left = KEY_LEFT;
	const int user_right = KEY_RIGHT;
	
	pl.render((col/2), (row/2));
	while((ch = getch()) != KEY_F(1)) {	
		clear();
		mvwprintw(stdscr, row/2, col/2, "#");
		switch(ch) {
			case user_left:
				pl.moveLeft();
				break;
			case user_right:
				pl.moveRight();
				break;
			case user_up:
				pl.moveUp();
				break;
			case user_down:
				pl.moveDown();
				break;
			default:
				continue;
		}
		//drawRoom();
		/* check borders */
		/*
		if (coordx < 0) {coordx = 0;}
		if (coordx > col-1) {coordx = col-1;}
		if (coordy < 0) {coordy = 0;}
		if (coordy > row-1) {coordy = row-1;}
		*/
		refresh();
	}
	endwin();                       	/* End curses mode */
	return 0;
}


