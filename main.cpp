#include <iostream>
/* Select which OS this is compiled on */
#include <ncurses.h>
#include <curses.h>	/* Windows */
#include "main.h"
using namespace std;


void drawRoom() {
	clear();
	//const char* roomstr = "___________________________|     |";
	//mvwprintw(stdscr, 0, 0, roomstr);
}
void Player::moveRight() {
		this->location[0]++;
		mvwprintw(stdscr, location[1], location[0], ">~>");
	}
void Player::moveLeft() {
		location[0]--;
		mvwprintw(stdscr, location[1], location[0], "<~<");
	}
void Player::moveDown() {
		location[1]++;
		mvwprintw(stdscr, location[1], location[0], "v~v");
	}
void Player::moveUp() {
		location[1]--;
		mvwprintw(stdscr, location[1], location[0], "^~^");
	}

int main() {
	int ch; 				/* characters typed */
	initscr();				/* Start curses mode */
	cbreak();				/* Line buffering disabled, 
							   Pass on everything to me */
	keypad(stdscr, TRUE); 	/* Activate additional keys like F1 */
	curs_set(0);			/* hide cursor */
	int row, col;
	getmaxyx(stdscr,row,col);
	int coordx = col/2; /* IMPORTANT */
	int coordy = row/2;
	Player pl();
	
	/* set this to something you'd like */
	const int user_up = 'w'; 
	const int user_down = 's';
	const int user_left = 'a';
	const int user_right = 'd';
	/* default
	const int user_up = KEY_UP; 
	const int user_down = KEY_DOWN;
	const int user_left = KEY_LEFT;
	const int user_right = KEY_RIGHT;
	*/
	
	
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case user_left:
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
		drawRoom();
		/* check borders */
		if (coordx < 0) {coordx = 0;}
		if (coordx > col-1) {coordx = col-1;}
		if (coordy < 0) {coordy = 0;}
		if (coordy > row-1) {coordy = row-1;}
		refresh();
	}
	endwin();                       	/* End curses mode */
	return 0;
}


