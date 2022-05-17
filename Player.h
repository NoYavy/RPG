/*
 * Player.h
 *
 *  Created on: 17.05.2022
 *      Author: Noyavy
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <list>
#include "main.h"

class Player {
	WINDOW stdscr;
    list<Item> inventory;
    int health = 100;
    int location[2];
    public:
		Player(int location[2], WINDOW stdscr);
		void moveRight();
		void moveLeft();
		void moveDown();
		void moveUp();
};



#endif /* PLAYER_H_ */
