/*
 * Room.h
 *
 *  Created on: 19.02.2022
 *      Author: Noyavy
 */



#ifndef ROOM_H_
#define ROOM_H_


class Room {
public:
	std::string walls;
	//int location[3];
	bool collide(int x, int y);
};

#endif /* ROOM_H_ */
