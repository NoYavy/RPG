/*
 * Player.h
 *
 *  Created on: 17.05.2022
 *      Author: Noyavy
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <ncurses.h>
#include <list>
#include "main.h"

class Player {
	_win_st* stdscr;
    std::list<Item> inventory;
    int health = 100;
    public:
        int locx;
		int locy;
		Player(int locx, int locy, _win_st* stdscr);
		void render(int x, int y, char pose = '~');
		void moveRight();
		void moveLeft();
		void moveDown();
		void moveUp();
};



#endif /* PLAYER_H_ */
