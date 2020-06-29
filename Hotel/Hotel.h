#ifndef __HOTEL_H
#define __HOTEL_H
#include "Room.h"

#define BALCONY_FEATURE 1


typedef struct
{
	int numOfFloors;
	int numOfRoomsInFloor;
	Room ** allRooms;
} Hotel;

void createHotel(Hotel* h, int floors, int rooms);
void showHotelStatus(Hotel* h);
int checkIfRoomExists(int room, Hotel * h);
Room getRoomForFeatureChecking(int roomNumber, Hotel h);
void allRoomsWithSameExistingFeature(Hotel h, int feature);
void variadicCheckAndPrint(int feature, Room * r, ...);
void freeHotel(Hotel * h);





#endif // !__HOTEL_H