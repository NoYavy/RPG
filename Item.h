/*
 * Item.h
 *
 *  Created on: 29.05.2022
 *      Author: Noyavy
 */

#ifndef ITEM_H_
#define ITEM_H_

#include "Interactable.h"
#include <string>

class Item : public Interactable {
	std::string name;
	public:
		void interact(Player* pl);
};

#endif /* ITEM_H_ */
