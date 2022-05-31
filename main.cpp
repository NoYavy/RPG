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
	if (col < roomx || row < roomy) {cout << "please resize your window to " << roomx << "|" << roomy; quit();}
	Room room(roomx-1, roomy-1); /* adjust for counting from 1 */
	Player pl((roomx/2), (roomy/2), stdscr, &room);
	

	/* set this to something you'd like
	 * default: */
	const int user_up = KEY_UP;
	const int user_down = KEY_DOWN;
	const int user_left = KEY_LEFT;
	const int user_right = KEY_RIGHT;

	room.addInteractable(new Item(50, 36, stdscr));
	room.addInteractable(new Item(60, 26, stdscr));
	room.addInteractable(new Item(13, 19, stdscr));
	room.addInteractable(new Item(75, 16, stdscr));
	room.addInteractable(new Text(6, 1, stdscr, "x Start game", &quit));
	room.addInteractable(new Text(6, 3, stdscr, "x Quit game", &quit));
	
	// add walls
	// top left
	room.addWall(0, 6, 100, 6);
	room.addWall(47, 17, 47, 20);
	room.addWall(37, 17, 47, 17);
	room.addWall(37, 17, 37, 19);
	room.addWall(37, 19, 43, 19);
	room.addWall(33, 12, 33, 20);
	room.addWall(21, 12, 33, 12);
	room.addWall(21, 10, 33, 10);
	room.addWall(33, 8, 33, 10);
	room.addWall(17, 8, 33, 8);
	room.addWall(17, 8, 17, 14);
	room.addWall(13, 17, 25, 14);
	room.addWall(17, 6, 17, 16);
	room.addWall(17, 18, 17, 20);
	room.addWall(5, 18, 17, 18);
	room.addWall(13, 8, 13, 18);
	room.addWall(9, 6, 9, 16);
	room.addWall(5, 8, 5, 18);
	room.addWall(25, 15, 25, 20);
	// top right
	room.addWall(53, 8, 53, 20);
	room.addWall(53, 8, 95, 8);
	room.addWall(95, 8, 95, 18);
	room.addWall(58, 13, 90, 13);
	room.addWall(58, 18, 95, 18);
	room.addWall(58, 13, 58, 18);
	// bottom left
	room.addWall(0, 21, 48, 21);
	room.addWall(3, 23, 52, 23);
	room.addWall(0, 25, 46, 25); room.addWall(50, 25, 52, 25);
	room.addWall(0, 27, 26, 27); room.addWall(30, 27, 48, 27);
	room.addWall(3, 29, 28, 29); room.addWall(32, 29, 40, 29); room.addWall(44, 29, 48, 29);
	room.addWall(40, 27, 40, 35);
	room.addWall(3, 35, 52, 35);
	room.addWall(3, 29, 3, 33);	room.addWall(0, 33, 3, 33);
	room.addWall(7, 31, 40, 31);
	room.addWall(3, 33, 36, 33);
	room.addWall(46, 29, 46, 33);
	// bottom right
	room.addWall(52, 21, 100, 21);
	room.addWall(52, 22, 52, 22);
	room.addWall(52, 23, 53, 35);
	

	pl.render();
	room.render();
	while((ch = getch()) != KEY_F(1)) {	/* F1 as exit key */
		clear();
		room.render();
		mvwprintw(stdscr, roomy/2, roomx/2, "+");
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


