#ifndef __ROOM_H
#define __ROOM_H

#define ROOM_ITEM_DETAILS 7

typedef struct
{
	int numOfBeds;
	unsigned char roomInfo;
} Room;

void GenerateRoomInfo(Room *myRoom);
void printRoomDetails(Room myRoom);
void setBitFromRight(unsigned char *ch, int index, int value);
int getBitFromRight(unsigned char ch, int index);
int doesFeatureExistInRoom(Room r, int indexFeature);



#endif // !__ROOM_H