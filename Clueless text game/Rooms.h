/*************************************************************************************************
 ** Program Filename:	Rooms.h
 ** Author:				Stephanie Holcomb
 ** Date:				December 5, 2015
 ** Description:		Contains class specifications for Room class and derived classes
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#ifndef __Rooms__
#define __Rooms__

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"



class Room {

	protected:
		int visited;
		std::string name;
		std::string description;
		std::string description_visited;
		
	public:
		Room *North;
		Room *South;
		Room *East;
		Room *West;
		
		Room();
		//~Room();
		virtual void setExits(Room *n = NULL, Room *s = NULL, Room *e = NULL, Room *w = NULL);
		Room* getNorth();
		Room* getSouth();
		Room* getEast();
		Room* getWest();
		virtual std::string getDescription();
		virtual std::string getDescription_visited();
		virtual void setVisited(int);
		virtual int getVisited();
		virtual void runControl(Room *currentRoom, Player player);
		virtual void runPreScript(Player);  // any script requiring look at variable. I.e. mention door is shut or
		virtual int moveMenu(Room *currentRoom, Player player);
	
};

class frontPorch:public Room {

	protected:
		int ringDoorbell;
		int visited;
		
	public:
		frontPorch();
		~frontPorch();
		void runControl(Room *currentRoom,Player player);  // keep this one as it's used to start off everything
};

class foyer:public Room {

	protected:
		int visited;
			
	public:
		foyer();
		~foyer();
	
};

class library:public Room {
	
	protected:
	
		int libraryDoor; 
		int visited;
	
	public:
		library();
		~library();
		void setLibraryDoor(int);
		void runPreScript(Player);
		void runControl(Room *currentRoom, Player player);
};

class grandHall:public Room {

	protected:
		int visited;
	
	public:
		grandHall();
		~grandHall();
		//void runPreScript();
		void runControl(Room *currentRoom, Player player);
	
};

class kitchen:public Room {
	
	protected:
		int visited;
	
	public:
		kitchen();
		~kitchen();
		void runPreScript();
		void runControl(Room *currentRoom, Player player);
};

class study: public Room {

	protected:
		int visited;
	
	public:
		study();
		~study();
		void runPreScript();
		void runControl(Room *currentRoom,Player player);
		
};

class laboratory: public Room {

	protected:
		int transformerSwitch;
		int visited;
	
	public:
		laboratory();
		~laboratory();
		void setTransformerSwitch(int);
		void runControl(Room *currentRoom,Player player); 
		//void runPreScript();
		
};

class hallway:public Room {

	protected:
		int visited;
		
	public:
		hallway();
		~hallway();
		void runPreScript();
		void runControl(Room *currentRoom,Player player);
		
};

class secretPassage:public Room {

	protected:
		int visited;
		
	public:
		secretPassage();
		~secretPassage();
		void runPreScript();
		
};



#endif 
