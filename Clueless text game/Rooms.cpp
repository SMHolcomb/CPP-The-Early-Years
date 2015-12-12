/*************************************************************************************************
 ** Program Filename:	Rooms.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				December 5, 2015
 ** Description:		Contains methods for Room class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
	
#include "Rooms.h"
#include "Player.h"

/*************************************************************************************************
 ** Function:			setExits() , getNorth(), getSouth(), getEast(), getWest()
 ** Description:		  Assigns rooms to 4 pointers for each room, gets rooms for movement	 
 ** Parameters:			Room pointers
 ** Pre-Conditions:		Room objects have already been created
 ** Post-Conditions:	None
 ***************************************************************************************************/

void Room::setExits(Room *n, Room *s,Room *e, Room *w) {
    North = n;
	South = s;
	East = e;
	West = w;
}

Room* Room::getNorth() {
	return North;
}

Room* Room::getSouth() {

	return South;
}

Room* Room::getEast() {

	return East;
}

Room* Room::getWest() {

	return West;
}


/*************************************************************************************************
 ** Function:			Room Constructor functions (multiple)
 ** Description:		  Creates room object and initializes data members.	 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Room::Room() {

	visited = 0;
	description = "";
	description_visited = "";

}

frontPorch::frontPorch() {
	
	ringDoorbell = 0;
	name = "Front Porch";
	description = "\nIt was a dark and stormy night (isn't it always..and in past tense no less?).  You've been invited to spend the weekend at the country estate of your dearest friend (whom you haven't seen in many years.\n\nAs you stand on the front porch with nothing but your small overnight valise. You hesitate and wonder if this was a mistake.  It seems a little isolated out here....\n";
	description_visited = "\nYou are back on the front porch."; // this will be unused as player doesn't exit

	}
  
foyer::foyer() {
	
	name = "Foyer";
	description = "\nYou are in the foyer of a dark (and scary) house. There don't appear to be any lights on in the house at all.  Did I mention it was very dark?\n\nTo the East is a closed door. To the West is a large room. To the North is a hallway. Also straight ahead is a set of stairs, but you've already made up your mind that you won't be going up *there* anytime soon!\nYou can't go South, but you can try.\n\nThe butler tells you he will be back in 5 minutes and off he goes.  Your curiosity gets the better of you and you decide to explore. After all you have 5 minutes before anyone comes back.\n\nFrankly, you can't wait to get some LIGHT, some HEAT, and a nice DRINK. [*** <-- DID YOU GET THAT DEAR READER? THIS IS WHAT'S KNOWN AS A CLUE]";
	description_visited = "\nYou are back in the foyer. To the North is a Hallway. To the East is a doorway. To the West is the Grand Hall. You can't go South.";
	}

hallway::hallway() {
	
	name = "Hallway";
	description = "\nYou are in the (very) dark hallway. You hope this is leading somewhere.  As you creep along, it seems that the photos are watching you\n\nTo the West is a doorway to another room. To the South is the foyer. There's nothing to the North or East except walls.";
	description_visited = "\nYou are back in the hallway. The eyes still seem to be watching you. To the West is a doorway to another room. To the South is the foyer.";
	
	//flashlight = 0;

}

library::library() {

	name = "Library";
	description = "\nYou are in a library.  The walls are covered with floor to ceiling bookshelves. It's very dusty and you have to keep from sneezing.  To the North, through a set of French Doors, seems to be a study.   To the South is a wall of books.  To the East is another wall of books, broken only by a stained glass window.  To the West is the foyer you just left behind. ";
	description_visited = "\nYou are back in the library. You must have left the door open. To the North is a study.  To the West is the foyer. There are nothing but books to the East and South";
	
	libraryDoor = 0; // starts off shut
  
  };

grandHall::grandHall() {
	
	name = "Grand Hall";
	description = "\nYou are in the Grand Hall. There is a fireplace. It is not lit which explains the cold. The couch looks distinctly uncomfortable and unused.  To the North is a passageway, possibly to a kitchen?  To the South is a wall. To the East is the foyer.  To the West is a wall with a large fireplace.";
	description_visited = "\nYou are back in the Grand Hall.";
	//fireplace = 0; // starts unlit
	
}

kitchen::kitchen() {
	
	name = "Kitchen";
	description = "\nYou find yourself in a large kitchen.  There is nothing apparent to eat here (darn). But on the counter, there is a blender.\n\nTo the north is a window overlooking the dark back yard. It looks nailed shut. To the south is the Grand Hall. To the west is a hallway. To the east is a wall with floor to ceiling storage.";
	description_visited = "\nYou are back in the kitchen. The blender is still on the counter.";
}

secretPassage::secretPassage() {
	
	name = "Secret Passageway";
	description = "\nYou pull on the book to examine it more closely and suddenly, you are in a secret Passage. Well, not really a secret anymore.  It appears there are only two ways to go:  Back East from whence you came or onward to the West (but there's nothing to keep you from trying).";
	description_visited = "\nYou are back in the (not so) secret passage.";
	

}

study::study() {
	
	name = "Study";
	//glass = 0;
	description = "\nYou open the french doors and find yourself in some sort of study.  There is a large dark wooden desk at the east end of the small room.  To the north is a wall with a small cupboard and some portraits. On the cupboard are several clean glasses.  To the south is the library from which you just came.  To the west is a bookshelf. Curiously, there is a book sticking out at an odd angle. ";
	description_visited = "\nYou are back in the study. To the South is the library. To the West is a bookshelf with a book sticking out at an odd angle. To the North and East are solid walls (good luck with that!)";

}

laboratory::laboratory() {

	transformerSwitch = 0;
	name = "Secret Luh-BOR-atory";
	description = "\nYou are in the laboratory.  There is a large green (yes, GREEN!) spider crawling across the table. Sitting on the workbench is a bunsen burner.  Across the room is a long person-sized steel table. ";
	description_visited = "\nYou are back in the laboratory.";
		
}



/*************************************************************************************************
 ** Function:			Set functions (multiple)
 ** Description:		  Sets various values for Room objects 
 ** Parameters:			None
 ** Pre-Conditions:		Room object must exist
 ** Post-Conditions:	None
 ***************************************************************************************************/

std::string Room::getDescription() {
	return description;
}
std::string Room::getDescription_visited() {
	return description_visited;
}

void laboratory::setTransformerSwitch(int electricity){
	transformerSwitch = electricity;
}

void library::setLibraryDoor(int open) {
 this->libraryDoor = open;
 
 }

void Room::setVisited(int visit) {
	this->visited = visit;
}

int Room::getVisited() {
	return visited;
}


/*************************************************************************************************
 ** Function:			runControl() (multiple)
 ** Description:		  Runs room-specific scripts	 
 ** Parameters:			Room and Player objects
 ** Pre-Conditions:		Rooms and Player must exist
 ** Post-Conditions:	None
 ***************************************************************************************************/


void Room::runControl(Room *currentRoom, Player player) {
	
	//run prescript for any pre-room scripts
	currentRoom->runPreScript(player);
	
	if (currentRoom->visited ==0) {
		std::cout << currentRoom->description << std::endl;
		currentRoom->setVisited(1);
		}
	else {
		std::cout << currentRoom->description_visited << std::endl;
		}
	
	player.winCheck(); // win check before moving on
	
	moveMenu(currentRoom,player);
	
}

void frontPorch::runControl(Room *currentRoom,Player player) {

	char ringChoice;
	std::string playerName;
	
	time_t start_time = clock();
	
	currentRoom->setVisited(1); // set Room's visited flag
	std::cout << description << std::endl;

	if(ringDoorbell==0) {
	
		std::cout << "Do you want to ring the doorbell? ('y' to continue or 'n' to run away)" << std::endl;
		
		while (ringChoice!='y' && ringChoice!='Y' && ringChoice!='n' && ringChoice!='N') {
			std::cin >> ringChoice;
			std::cout << std::endl;
		if(ringChoice=='Y' || ringChoice=='y') {
			std::cout << "Ding-Dong..." << std::endl;
			ringDoorbell = 1;	
			}
		else if (ringChoice == 'N' || ringChoice == 'n') {
			std::cout << "Scaredy-cat! Here I'll ring it for you..." << std::endl;
			std::cout << "Ding-Dong... Ding-Dong....." << std::endl;
			ringDoorbell = 1;
			}
		else {
			std::cout << "What's that supposed to mean? I need a 'Y' or 'N'answer!" << std::endl;
				}
		} 
	} 
	
	else {  //this should never trigger after changes but just in case.
		std::cout << "It appears you already rang once before. Perhaps we'll knock this time." << std::endl;
		}
	
	// door opens
	std::cout << std::endl << std::endl;
	std::cout << "It seems hardly a moment before the big door slowly creaks open and you are confronted by a tall, very pale looking man. You can only assume he's the butler." << std::endl;
	std::cout << "\n'May I say who is ringing, Sir'? (He calls everyone 'Sir' no matter who they are)." << std::endl;
	
	std::cout << "[Enter your name..or the butler will keep calling you Sir]" << std::endl;
	std::cin >> playerName;
	std::cout << std::endl;

	//create player
	player.setName(playerName);
 
	std::cout << "'Ah yes, very good Sir " << player.getName() << ". The master has been expecting you. Please come in and I will dispatch forthright to fetch him.'" << std::endl;
	std::cout << "You don't know what that means exactly, but you enter the house...." << std::endl;
	
	//move Into house - this is a forced move to enter the house - no user choice
	Room *temp = currentRoom->getNorth();
	currentRoom = temp;

	// send new room to runControl
	Room::runControl(currentRoom,player);

}

void hallway::runControl(Room *currentRoom, Player player) {
	
	int direction=0;

   char pickChoice;
   
   //run prescript for pre-room stuff like door opening
	currentRoom->runPreScript(player);
	
	if (currentRoom->getVisited() ==0) {
		std::cout << currentRoom->getDescription() << std::endl;
		currentRoom->setVisited(1);
		}
	else {
		std::cout << currentRoom->getDescription_visited() << std::endl;
		}
   
   //if player has flashlight don't give them the option to pick up this time
   if(player.getFlashlight()==1) {
		std::cout << "This is where you picked up the flashlight last time." << std::endl;
		}
   else {
	   
		std::cout << "\nAs you stumble in the dark, you feel something down by your feet. You reach down and feel a flashlight.  You don't have much space in your valise, but a flashlight might come in handy what with all the darkness.  Do you want to pick it up?  ('y' or 'n')" << std::endl;
		
		while (pickChoice !='n' && pickChoice!='N' && pickChoice !='y' && pickChoice!='Y') {
			
			std::cin >> pickChoice;
	 
			if(pickChoice=='Y' || pickChoice=='y') {
				
				player.addItem(player,"Flashlight");
				player.showInventory();
				player.setFlashlight(1);
				}
			else if (pickChoice == 'N' || pickChoice == 'n') {
				std::cout << "Ok... if you change your mind you can always come back and get it." << std::endl;
				}
			else {
				std::cout << "How do you both pick something up and NOT pick something up? I need a 'Y' or 'N'answer!" << std::endl;	
				}		
		} 		
	} 

	player.winCheck();
	
	// Display move menu
	moveMenu(currentRoom,player);
	
}

void library::runControl(Room *currentRoom, Player player) {

	int direction = 0;
	char pickChoice;

	//run prescript for any user interacted changes to room
	currentRoom->runPreScript(player);
	
	if (currentRoom->getVisited() ==0) {
		std::cout << currentRoom->getDescription() << std::endl;
		currentRoom->setVisited(1);
		}
	else {
		std::cout << currentRoom->getDescription_visited()<< std::endl;
		}

   // if player already has the key don't give them the option to pick it up this time
   if(player.getKey()==1) {
		std::cout << "This is where you picked up the key last time." << std::endl;	
		}
   else {
		
		std::cout << "You see a key on one of the sidetables in the library.  Do you want to pick it up?  ('y' or 'n')" << std::endl;
	
		while (pickChoice !='n' && pickChoice!='N' && pickChoice !='y' && pickChoice!='Y') {
			std::cin >> pickChoice;
	 
			if(pickChoice=='Y' || pickChoice=='y') {
				player.addItem(player,"Key");
				player.showInventory();
	
				if(player.Valise[player.Valise.size()-1] == "Key") {
					player.setKey(1);
				 }
				}
				
			else if (pickChoice == 'N' || pickChoice == 'n') {
				std::cout << "Ok... if you change your mind you can always come back and get it." << std::endl;
				}
			else {
				std::cout << "How do you both pick something up and NOT pick something up? I need a 'Y' or 'N'answer!" << std::endl;	
				}
		
		} 
		
		
  } 

	// show menu to move
	moveMenu(currentRoom,player);
		
}

void laboratory::runControl(Room *currentRoom,Player player) {
	int direction = 0;
	int answer = 0;
	int flip = 0;
	
	
	std::string transformer;
		
	 //check if transformer switch was thrown earlier and generate string for script below
	 if(transformerSwitch == 0) {
		
		transformer = "DOWN";
		}
	  else if (transformerSwitch == 1){
	   
		transformer = "UP";
		}
	  else {
		std::cout << "We don't know what's up with the switch! Time to debug some more." << std::endl;
		}
	
	
	if (currentRoom->getVisited()==1) {
	     std::cout << "It looks like you've been here before. You already fixed the electricity the first time. There's nothing more to see here! Besides, that (GREEN!) spider is still crawling around somewhere." << std::endl;
		}
	else {
		std::cout << "You are in a laboratory.  There is a large green (yes, GREEN!) spider crawling across the table. Sitting on the workbench is a bunsen burner.  Across the room is a long person-sized steel table.Near the head of the table is a transformer switch, currently in the " + transformer + " position.\n\nAlso on the table, a little too close to the spider for comfort, is a piece of paper.  You pick it up and read the following just as the secret passageway you came through slams shut!\n\n 'If you wish to escape your doom,\nanswer this riddle and exit this room:\n" << std::endl;

		std::cout << "I was born in 1847 in Ohio. By the time I was 10 I had my own chemistry laboratory. Following an accident as a child, I became deaf.  As an adult I created the world's first industrial research laboratory in New Jersey. Who am I?'\n" << std::endl << std::endl;
		std::cout << "1. George Washington" << std::endl;
		std::cout << "2. Steve Jobs" << std::endl;
		std::cout << "3. Thomas Edison" << std::endl;
		std::cout << "4. Johann Strauss" << std::endl;
	
		std::cout << "\nPlease enter an integer " << std::endl;
		while (answer!=3) {
			std::cin >> answer;
			if(answer ==3) {
			
				std::cout << "\nThat's Correct!!\n" << std::endl;
				
			 // ** enter option to flip switch up -- don't go on until it's done... then flip the switch up.
			
			std::cout << "This gives you an idea.  You walk across the room and examine the transformer switch.  What do you do? " << std::endl;
			std::cout << "1) Flip it to the up position" << std::endl;
			std::cout << "2) Leave it and stand staring blankly at it" << std::endl;
		
			while (flip !=1) {
			
				std::cin >> flip;
			
					if(flip==1) {
					std::cout << "As you flip up the transformer switch, the door to the laboratory suddenly slides open!  You're free! As an added bonus you can see light through the secret passage. Looks like you turned the electricity back on!" << std::endl;
					setTransformerSwitch(1);
					player.setElectricity(1);
										}
				else if(flip==2) {
					std::cout << "Are you just going to stand there and stare at it all day? DO SOMETHING!" << std::endl;
					}
				else {
					std::cout << "Try again! It's not that hard!" << std::endl;
					}
				} 
			 }
			 
			else {
				std::cout << "Sorry, that's not correct. Try again:" << std::endl;
				}
		}
  } 
  
  
	// set this down here so the script above will run one time
	currentRoom->setVisited(1);
	
	// run move menu
	moveMenu(currentRoom,player);
	
	
}

void study::runControl(Room *currentRoom, Player player) {
	char pickChoice;
	int direction = 0;
    
	currentRoom->runPreScript(player);
	
	if (currentRoom->getVisited()==0) {
		std::cout << currentRoom->getDescription() << std::endl;
		currentRoom->setVisited(1);
		}
	else {
		std::cout << currentRoom->getDescription_visited() << std::endl;
		}
	
   if(player.getGlass()==1) {
		std::cout << "This is where you picked up the glass last time." << std::endl;
		}
   else {
		
		std::cout << "You see some glasses on the cupboard. Do you want to pick one up for later?  ('y' or 'n')" << std::endl;
	
		while (pickChoice !='n' && pickChoice!='N' && pickChoice !='y' && pickChoice!='Y') {
			
			std::cin >> pickChoice;
	 
			if(pickChoice=='Y' || pickChoice=='y') {
				player.addItem(player,"Glass");
				player.showInventory();
				player.setGlass(1);
			}
			
		else if (pickChoice == 'N' || pickChoice == 'n') {
			std::cout << "Ok... if you change your mind you can always come back and get it." << std::endl;
			}
		else {
			std::cout << "How do you both pick something up and NOT pick something up? I need a 'Y' or 'N'answer!" << std::endl;	
			}
	   } 	   
	
	
  }

	player.winCheck();

	// show menu to move
	moveMenu(currentRoom,player);	
	
}

void grandHall::runControl(Room *currentRoom, Player player) {
	
	 int light = 0;
	 std::string fire;
	 int direction = 0;
	 
	//std::cout << "\n**Have you visited here before: " << currentRoom->getVisited() << std::endl;
	player.winCheck();
	currentRoom->runPreScript(player);
	
	if (currentRoom->getVisited() ==0) {
		std::cout << currentRoom->getDescription() << std::endl;
		std::cout << "\nAs you look around, you see a needlework quote on the wall. It's hard to read, but it says:\n\n'Tear one off, scratch my head what was red is black instead.'\n" << std::endl;
		
		std::cout << "This gives you an idea.  You walk across the room and examine the fireplace.  There are some matches on the mantle!  What do you do? " << std::endl;
		std::cout << "1) Light 'em up and get some warmth in this place" << std::endl;
		std::cout << "2) Concentrate very hard and hope spontaneous combustion occurs" << std::endl;
		
		while (light !=1) {
		    std::cin >> light;
		
			if(light==1) {
				std::cout << "As you strike a match and touch it to the logs in the fireplace, the warmth is almost immediate and you think this weekend may not be so bad after all." << std::endl;
				player.setFireplace(1);
				
				//std::cout << player.getFireplace() << std::endl; //confirm it flipped to 1 "LIT"
				}
			else if(light==2) {
				std::cout << "Really? Is that gonna happen anytime soon? Try Again, Genius!" << std::endl;
				}
			else {
				std::cout << "Try again! It's not that hard!" << std::endl;
				}
			}

		currentRoom->setVisited(1);
		}
	else {
		std::cout << currentRoom->getDescription_visited() << std::endl;
		 
		 //check if fireplace was already lit earlier
		if(player.getFireplace() == 0) {
			fire = "NOT LIT";
			}
		else if (player.getFireplace() == 1){
			fire = "LIT";
			}
		else {
			std::cout << "We don't know what's up with the fireplace! Time to debug some more." << std::endl;
			}
		
		std::cout << "Across the room is a fireplace. It's currently " + fire + "." << std::endl;
			}
	 
	 
	player.winCheck();
	
	// show menu to move
	moveMenu(currentRoom,player);

}

void kitchen::runControl(Room *currentRoom, Player player) {

	int direction = 0;
	char pickChoice;
	char blendChoice;
	
	player.winCheck();
   
   	
	if (currentRoom->getVisited() ==0) {
		std::cout << currentRoom->getDescription() << std::endl;
		currentRoom->setVisited(1);
		}
	else {
		std::cout << currentRoom->getDescription_visited() << std::endl;
		}
	
   if(player.getFood()==1) {
		std::cout << "This is where you picked up the Ding-Dongs last time." << std::endl;
	}
   else {
	   
		std::cout << "\nYou suddenly notice a box of Ding-Dongs on the counter.  Do you want to pick it up?  ('y' or 'n')" << std::endl;

		while (pickChoice !='n' && pickChoice!='N' && pickChoice !='y' && pickChoice!='Y') {
			std::cin >> pickChoice;
	 
			if(pickChoice=='Y' || pickChoice=='y') {
				player.addItem(player,"Ding-Dongs");
				player.showInventory();
				player.setFood(1);	
			}
		else if (pickChoice == 'N' || pickChoice == 'n') {
			std::cout << "Ok... if you change your mind you can always come back and get it." << std::endl;
			}
		else {
			std::cout << "How do you both pick something up and NOT pick something up? I need a 'Y' or 'N'answer!" << std::endl;	
			}
		} 
		
	
	}
  
	//blender won't turn on unless you've turned electricity on and have the glass
   if (player.getBlender() == 0) {
		std::cout << "You look around some more and see that, in the icebox, there are the makings of a smoothie." << std::endl;
		std::cout << "Do you want to make a smoothie? ('Y' or 'N')" << std::endl;

		while(blendChoice!='y' && blendChoice!='Y' && blendChoice!='n' && blendChoice!='N') {
			std::cin >> blendChoice;
			if(blendChoice== 'y'|| blendChoice =='Y') {
			
				if(player.getGlass()==0 && player.getElectricity()==1) {
					std::cout << "It's too bad you don't have a glass. You look in the cupboards but there aren't any. [HINT: Try the study]." << std::endl;
					}
				else if(player.getGlass()==0 && player.getElectricity()==0) {
					std::cout << "The electricity doesn't seem to be on.  Perhaps you should fix that [HINT: try the laboratory]. It would also help if you had a glass [Try the study]. That's enough hints for now." << std::endl;
					}
				else if (player.getGlass()==1 && player.getElectricity()==0) {
					std::cout << "The electricity doesn't seem to be on.  Perhaps you should fix that [HINT: try the laboratory]." << std::endl;
					}
				else if (player.getGlass()==1 && player.getElectricity()==1) {	
					std::cout << "Bingo. You have the glass, you turned the electricity back on. The Smoothie is as good as made! All you need to do is put the makings in and turn the blender on." << std::endl;
					std::cout << "You put the banana in the blender, add some milk, and flip the switch. You have a nice smoothie in no time." << std::endl;
					player.setBlender(1);  // in order to get here, must have electricity and glass so blender=on.
					}
				 } 
			else if (blendChoice=='n' || blendChoice=='N') {
					std::cout << "Ok, you can try again later if you want." << std::endl;
				 }
			else {
				std::cout << "I have no idea what that means. Do you want to try to make a smoothie or not? Y or N?" << std::endl;
				}
	
		} 
	} 
	
	player.winCheck();
	
	// show menu to move
	moveMenu(currentRoom,player);
	
}


/*************************************************************************************************
 ** Function:			moveMenu() 
 ** Description:		  Displays move menu and advances player from room to room
 ** Parameters:			Current Room
 ** Pre-Conditions:		Rooms and Player must exist
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Room::moveMenu(Room *currentRoom, Player player) {
	int direction = 0;

	// show menu to move
	while (direction!=8) {

	    std::cout << "\nChoose a direction to go next" << std::endl;
		std::cout << "1) North" << std::endl;
		std::cout << "2) South" << std::endl;
		std::cout << "3) East" << std::endl;
		std::cout << "4) West" << std::endl;
		std::cout << "5) Show contents of Valise" << std::endl;
		std::cout << "6) Remove item from Valise" << std::endl;
		std::cout << "7) ** CHEAT (solution for evaluation) **" << std::endl;
		std::cout << "8) Quit" << std::endl;
	
		std::cin >> direction;
		
		switch(direction) {
		
		case 1: {//north
			Room *temp = currentRoom->getNorth();
			
			if(temp == NULL) {
			  std::cout << "Sorry you can't go North. Try again" << std::endl;
			}
			else {
			  currentRoom = temp;
			currentRoom->runControl(currentRoom, player);
			}

			break;
			}
		case 2:  {//south
			Room *temp = currentRoom->getSouth();
			if(temp == NULL) {
			std::cout << "Sorry you can't go South. Try again" << std::endl;
			}
			else {
			 currentRoom = temp;
			currentRoom->runControl(currentRoom, player);
			}

			break;
			}
		case 3:	{//east
			Room *temp = currentRoom->getEast();
			if(temp == NULL) {
			std::cout << "Sorry you can't go East. Try again" << std::endl;
			}
			else {
			 currentRoom = temp;
			currentRoom->runControl(currentRoom, player);
			}

			break;
			}
		case 4: { //west
			Room *temp = currentRoom->getWest();
			if(temp == NULL) {
			std::cout << "Sorry you can't go West. Try again" << std::endl;
			}
			else {
			 currentRoom = temp;
			currentRoom->runControl(currentRoom, player);
			
			}

			break;
			}
		case 5: {
				player.showInventory();
				break;
			}
		case 6: {
				player.removeItem();
				break;
			}
		case 7: {
				std::cout << "\n***\nThe goal of the game is to turn on the electricity, collect a glass, light the fireplace, and make a smoothie (requires glass) in the kitchen.\n\nThe quickest way to get to this is to go East to library\n, North to study\n, collect glass in study\n, Go West to secret passage\n, go West to laboratory\n, answer questions in lab (can't get them wrong) to flip the transformer\n, go East back to secret Passage\n, East back to Study\n, South to library\n, West to Foyer\n, West to Grand Hall\n, light the fireplace in the Grand Hall (can't fail here)\n, North to kitchen, don't have to collect Ding-Dongs\n, answer 'y' to make smoothie." << std::endl;
				
				break;
			}
		case 8: {
		
				std::cout << "Goodbye!" << std::endl;
				std::exit(0);
				break;
			}
		default: {
		
		     std::cout << "Try again" << std::endl;
			//break;

		  }
		} // end switch
	 
	} // end while loop



}

/*************************************************************************************************
 ** Function:			preScript() (multiple)
 ** Description:		  Runs room-specific pre-scripts prior to main run function	 
 ** Parameters:			Player objects
 ** Pre-Conditions:		Rooms and Player must exist
 ** Post-Conditions:	None
 ***************************************************************************************************/

void Room::runPreScript(Player player) {

}

void library::runPreScript(Player player) {
	
	char doorChoice;

	if(libraryDoor==0) {  // door has not been opened yet

		std::cout << "You are confronted by a large door.  Do you want to open it? ('y' or 'n'): " << std::endl;
		while(doorChoice!='y' && doorChoice!='Y' && doorChoice!='n' && doorChoice!='N') {
		
			std::cin >> doorChoice;
			std::cout << std::endl;
			if(doorChoice=='Y' || doorChoice=='y') {
				libraryDoor = 1;
				}
			else if (doorChoice == 'N' || doorChoice == 'n') {
				std::cout << "Scaredy-cat! Here I'll open it for you..." << std::endl;
				libraryDoor = 1;
				}
			else {
				std::cout << "What's that supposed to mean? I need a 'Y' or 'N'answer!" << std::endl;
				}
	
			} 
	 
		// Prints for either choice since we are forcing player to begin game
		std::cout << "You quietly open the door to what you believe is a library and see nothing.  Intrigued now, you step into a very dark room.  You can barely see anything, but you can see enough to know that you *were* RIGHT(!).";
		} 
		else {
			// don't do anything since door is already open. library runControl will handle the rest. 
			}

}



