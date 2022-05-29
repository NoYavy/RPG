/*
 * Text.h
 *
 *  Created on: 28.05.2022
 *      Author: Noyavy
 */

#ifndef TEXT_H_
#define TEXT_H_

#include "Interactable.h"

class Text : public Interactable {
	const char* text;
	void (*invoke) (void);
	public:
		Text(int x, int y, _win_st* stdscr, const char* text, void (*func) (void));
		void render();
		void interact(Player* pl);
		char t = 't';
};

#endif /* TEXT_H_ */
