/*
 * Item.cpp
 *
 *  Created on: 29.05.2022
 *      Author: Noyavy
 */

#include "Item.h"
#include "Player.h"

void Item::interact(Player* pl) {
	pl->addtoInventory(this);
}
