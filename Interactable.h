/*
 * Interactable.h
 *
 *  Created on: 26.05.2022
 *      Author: Noyavy
 */

#ifndef INTERACTABLE_H_
#define INTERACTABLE_H_

#include "Player.h"

class Interactable {
	int posx;
	int posy;
	_win_st* stdscr;
	public:
		Interactable();
		Interactable(int x, int y, _win_st* stdscr);
		int getxPos();
		int getyPos();
		void interact(Player pl);
		void render();
};
#endif /* INTERACTABLE_H_ */
