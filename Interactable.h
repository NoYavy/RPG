/*
 * Interactable.h
 *
 *  Created on: 26.05.2022
 *      Author: Noyavy
 */

#ifndef INTERACTABLE_H_
#define INTERACTABLE_H_

//#include "Player.h"
#include <ncurses.h>
class Player;
class Interactable {
	protected:
		int posx;
		int posy;
		_win_st* stdscr;
	public:
		Interactable();
		Interactable(int x, int y, _win_st* stdscr);
		int getxPos();
		int getyPos();
		virtual void interact(Player* pl); // ahhhhhh it had to be virtual
		void render();
};
#endif /* INTERACTABLE_H_ */
