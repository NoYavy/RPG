/*
 * Portal.h
 *
 *  Created on: 29.05.2022
 *      Author: Noyavy
 */

#ifndef PORTAL_H_
#define PORTAL_H_

#include "Interactable.h"
#include <string>

class Portal : public Interactable {
	int targetx;
	int targety;
	public:
		Portal();
		Portal(int x, int y, _win_st* stdscr, int targetx, int targety);
		void interact(Player* pl);
		void render();
};

#endif /* PORTAL_H_ */
