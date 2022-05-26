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
#include "Interactable.h"
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
	Room room(col-1, row-1);
	Player pl((col/2), (row/2), stdscr, room);
	pl.render((col/2), (row/2));
	
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
	
	Interactable blob(15, 20, stdscr);
	room.addInteractable(blob);
	
	while((ch = getch()) != KEY_F(1)) {	
		clear();
		blob.render();
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
			case 'e':
				pl.interact();
				break;
			default:
				pl.render('~');
				continue;
		}
		//drawRoom();
		refresh();
	}
	endwin();                       	/* End curses mode */
	return 0;
}


