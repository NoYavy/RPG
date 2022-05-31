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
#include "Portal.h"
#include <iostream>
using namespace std;

int roomx;
int roomy;
Player pl();

void tutorial() {
	clear();
	mvwprintw(stdscr, 15, 10, "Du bist ein Archäologe und musst die Artefakte (X) finden. Hebe sie auf mit \"E\".");
	mvwprintw(stdscr, 16, 10, "Bewege dich mit \"WASD\" und weiche den Wänden (#) aus, oder nutze die uralte Magie in");
	mvwprintw(stdscr, 17, 10, "diesem antiken Tempel. Sie bewirkt, dass man in einem bestimmten Winkel durch Wände");
	mvwprintw(stdscr, 18, 10, "hindurch gehen kann, du solltest das zu deinem Vorteil nutzen! * Benutze \"M\", falls");
	mvwprintw(stdscr, 19, 10, "du feststeckst, es bringt dich zurück zum Menü. Doch Obacht alle Artefakte kehren");
	mvwprintw(stdscr, 20, 10, "an ihre ursprüngliche Stelle zurück. Portale (0) kannst du ohne Gefahr nutzen.");
	mvwprintw(stdscr, 36, 69, "* it's not a bug it's a feature");
}

void quit() {
	clear();
	endwin();                       	/* End curses mode */
	exit(1);
}

void initInters(Room* room) {
	room->clearInteractables();
	room->addInteractable(new Item(47, 36, stdscr));
	room->addInteractable(new Item(60, 26, stdscr));
	room->addInteractable(new Item(13, 19, stdscr));
	room->addInteractable(new Item(75, 16, stdscr));
	room->addInteractable(new Text(6, 1, stdscr, "x Instructions", &tutorial));
	room->addInteractable(new Text(6, 3, stdscr, "x Quit game", &quit));
	room->addInteractable(new Text(9, 2, stdscr, "<- enter to start", &quit));
	room->addInteractable(new Portal(7, 2, stdscr, (roomx/2), (roomy/2)));
	room->addInteractable(new Portal(50, 36, stdscr, (roomx/2), (roomy/2)));
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
	roomx = 100;
	roomy = 37;
	if (col < roomx || row < roomy) {cout << "please resize your window to at least " << roomx << " by " << roomy << " as it currently is " << col << " by " << row; quit();}
	Room room(roomx-1, roomy-1); /* adjust for counting from 1 */
	Player pl(2, 2, stdscr, &room);
	

	/* set this to something you'd like
	 * default: */
	const int user_up = 'w';
	const int user_down = 's';
	const int user_left = 'a';
	const int user_right = 'd';

	initInters(&room);

	
	// add walls
	// top left
	room.addWall(0, 6, 99, 6);
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
	room.addWall(52, 21, 99, 21);
	room.addWall(52, 22, 52, 22);
	room.addWall(52, 23, 53, 36);
	

	tutorial();
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
			case 'm':
				pl.teleport(2, 2);
				pl.clearInventory();
				initInters(&room);
			default:
				pl.render('~'); /* prevent player from turning invisible */
				continue;
		}
		if (pl.score == 4) {
			clear();
			mvwprintw(stdscr, roomy/2, roomx/2, "You won! Press any key to quit");
			if (getch()) {quit();}
		}
		refresh();
	}
	quit();
	return 0;
}


