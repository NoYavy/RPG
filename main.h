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


class ShipAI {

};


#endif /* MAIN_H_ */
