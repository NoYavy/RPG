/*
 * main.cpp
 *
 *  Created on: 19.02.2022
 *      Author: Noyavy
 */

#include <ncurses.h>
#include "main.h"
#include "Player.h"
#include "Room.h"
#include "Interactable.h"
#include "Text.h"
#include "Item.h"
#include <iostream>
using namespace std;


void boom() {
	mvwprintw(stdscr, 20, 20, "O=0");
}

void quit() {
	clear();
	//cout << pl.score;
	endwin();                       	/* End curses mode */
	exit(1);
}

int main() {
	int ch; 				/* characters typed */
	initscr();				/* Start curses mode */
	start_color();			/* Start color functionality	*/
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	cbreak();				/* Line buffering disabled,
							 * Pass on everything */
	keypad(stdscr, TRUE); 	/* Activate additional keys like F1 */
	curs_set(0);			/* hide cursor */
	int row, col;
	getmaxyx(stdscr,row,col); /* Terminal size */
	int roomx = 100;
	int roomy = 37;
	if (col < roomx || row < roomy) {cout << "please resize your window" << row << "|" << col; quit();}
	Room room(roomx-1, roomy-1); /* adjust for counting from 1 */
	Player pl((roomx/2), (roomy/2), stdscr, &room);
	

	/* set this to something you'd like
	 * default: */
	const int user_up = KEY_UP;
	const int user_down = KEY_DOWN;
	const int user_left = KEY_LEFT;
	const int user_right = KEY_RIGHT;

	Interactable blob(15, 20, stdscr);
	Item blob2(10, 20, stdscr);
	Text blob3(30, 20, stdscr, "x Hello World", &boom);
	room.addInteractable(&blob);
	room.addInteractable(&blob2);
	room.addInteractable(&blob3);
	room.addWall(9, 21, 30, 21);

	pl.render();
	room.render();
	while((ch = getch()) != KEY_F(1)) {	/* F1 as exit key */
		clear();
		room.render();
		mvwprintw(stdscr, roomy/2, roomx/2, "#");
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
				pl.render('~'); /* prevent player from turning invisible */
				continue;
		}
		refresh();
	}
	quit();
	return 0;
}


