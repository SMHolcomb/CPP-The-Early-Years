/*************************************************************************************************
 ** Program Filename:	Main.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				December 5, 2015
 ** Description:		Main implementation file for Clueless
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/


#include <iostream>
#include <string>
#include "Rooms.h"
#include "Player.h"


/*************************************************************************************************
 ** Function:			main()
 ** Description:		  main functions for implementation of game	 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
int main(int argc, const char * argv[])
{
	
    //std::string playerName;
	
	// set up all the rooms 
	Room *fporch = new frontPorch();
	Room *lib = new library();
	Room *stud = new study();
	Room *foy = new foyer();
	Room *lab = new laboratory();
	Room *hall = new hallway();
	Room *grandhall = new grandHall();
	Room *kitch = new kitchen();
	Room *secret = new secretPassage();

	
	
	// set up all the room pointers - move this to a separate function later
	fporch->setExits(foy,NULL,NULL,NULL);
	foy->setExits(hall,NULL,lib,grandhall);
	lib->setExits(stud,NULL,NULL,foy);
	stud->setExits(NULL,lib,NULL,secret);
	lab->setExits(NULL,NULL,secret,NULL);
	hall->setExits(NULL,foy,NULL,kitch);
	grandhall->setExits(kitch,NULL,foy,NULL);
	kitch->setExits(NULL,grandhall,hall,NULL);
	secret->setExits(NULL,NULL,stud,lab);


	std::cout << "                    X                 X" << std::endl;
	std::cout << "  XXX X   X X XXX  X  X   XXX XXX XXX  X" << std::endl;
	std::cout << "  X   X   X X X   XX  X   X   X   X    XX" << std::endl;
	std::cout << "  X   X   X X XXX X   X   XXX XXX XXZ   X" << std::endl;
	std::cout << "  X   X   X X X   XX  X   X     X   X  XX" << std::endl;
	std::cout << "  XXX XXX XXX XXX  X  XXX XXX XXX XXX  X" << std::endl;
	std::cout << "                    X                  X" << std::endl;

	std::cout << std::endl << std::endl;

	// Initialize currentRoom to front porch as starting point
	Room *currentRoom;
	currentRoom = fporch;
	
	Player player("");
	
	// ** START GAME RUN  ** //
	currentRoom->runControl(currentRoom,player);
		


    return 0;
}

