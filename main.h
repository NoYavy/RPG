/*
 * main.h
 *
 *  Created on: 19.02.2022
 *      Author: Noyavy
 */



#ifndef MAIN_H_
#define MAIN_H_

#include <list>
#include <string>
using namespace std;


class Room;
class Ship {
public:


private:
	list<Room> rooms;
};

class Item {
public:
    string name;

};


class Room {
public:
	string walls;
	//int location[3];

private:
};
class Player {
    list<Item> inventory;
    int health;
    int location[2];
    char playermiddle;
    public:
		Player(int location[2]);
		void moveRight();
		void moveLeft();
		void moveDown();
		void moveUp();
};

class ShipAI {

};


#endif /* MAIN_H_ */
