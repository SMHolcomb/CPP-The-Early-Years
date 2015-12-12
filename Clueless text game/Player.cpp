/*************************************************************************************************
 ** Program Filename:	Player.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				December 5, 2015
 ** Description:		Contains methods for Player class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/


#include <string>
#include <vector>
#include <cstdlib>

#include "Player.h"


/*************************************************************************************************
 ** Function:			Player Win Check Function
 ** Description:		  Checks that all reqs have been met towards goal	 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/


void Player::winCheck() {

			/*// Keep for testing
			std::cout << "Electricity: " << electricity << std::endl;
			std::cout << "Glass: " << glass << std::endl;
			std::cout << "Fireplace: " << fireplace << std::endl;
			std::cout << "Blender: " << blender << std::endl;
			*/
		
	  if (electricity ==1 && glass == 1 && fireplace == 1 && blender == 1) {
	  
		std::cout << "\n\n***********************" << std::endl;
		std::cout << "\nCongratulations!! You have succeeded in your quest!! You now have light, a warm fire, and a nice drink.\n" << std::endl;
		
		// in addition you might have a useless key and some Ding-Dongs as well
		if(food==1) {
			std::cout << "...and some Ding-Dongs in case you get hungry." << std::endl;
			}
		if(key==1) {
			std::cout << "\n....In addition, you have a useless key!" << std::endl;
			}
		std::cout << "Just as you are congratulating yourself. You hear the Butler return....\n\n" << std::endl;
		std::exit(0);
		 
		}
		
	
}



/*************************************************************************************************
 ** Function:			Player Constructor/Deconstructor functions
 ** Description:		  Creates Player object and initializes data members. Destroys at end.	 
 ** Parameters:			constructor: string name
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
Player::Player(std::string n) {

 name = n;
 fireplace = 0;
 electricity = 0;
 flashlight=0;
 glass=0;
 blender = 0;
 maxItems = 3;
 std::vector<std::string> Valise;

}

Player::~Player() {

}


/*************************************************************************************************
 ** Function:			Player Inventory Functions
 ** Description:		  Add, Remove, Show current items in players bag.	 
 ** Parameters:			addItem = Player object and string item name
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/


void Player::showInventory()  {
	
	if(Valise.size() ==0) {
		std::cout << "\nYour valise is currently empty." << std::endl;
	  }
	else if (Valise.size() > 0) {
		std::cout << "\nYou have " << Valise.size() << " item(s) in your valise:" << std::endl;
		for(int i = 0; i < Valise.size(); i++) {
		std::cout << "- " << Valise[i] << std::endl;
		}
		if(Valise.size()>=maxItems) {
			std::cout << "You have no more room in your Valise. You'll have to remove something before you can add anything." << std::endl;
			}
		else {
			std::cout << "\nYou have room for " << (maxItems - getNumItems()) << " item(s)." << std::endl;
			}
	  }
	std::cout << std::endl;


}

void Player::addItem(Player player,std::string item)   {
    
	char removeChoice;
	int remove;
	
	if(Valise.size() >= maxItems) {
	
		std::cout << "Sorry, you don't have room for any more items in your valise." << std::endl;
		std::cout << "Do you want to remove an item and replace it with this one?" << std::endl;
		
		while(removeChoice!= 'y' && removeChoice!='Y' && removeChoice!= 'n' && removeChoice!='N') {
		    
			std::cin >> removeChoice;
			
			if(removeChoice=='y' || removeChoice=='Y') {
				removeItem();
				if (Valise.size() < maxItems) { // check in case user confirmed No in removeItem
					Valise.push_back(item);
					std::cout << "\nThe " << item << " has been added to your Valise." << std::endl;
					}
				}
			else if (removeChoice=='n' || removeChoice=='N') {
				//don't do anything
				}
			else {
				std::cout << "I need a 'y' or 'n' answer. Try again" << std::endl;
				}
			} 
		} 
	
	else {

		Valise.push_back(item);
		std::cout << "\nThe " << item << " has been added to your Valise." << std::endl;
	
	}
}

void Player::removeItem() {
	int remove;
	char removeChoice;
	
	if (Valise.size() < 1) {
		std::cout << "You don't have anything to remove." << std::endl;
	  }
	else {
		std::cout << "Which item would you like to remove? (enter integer) " << std::endl;
		
		for (int i = 0; i < Valise.size(); i++) {
			std::cout << i + 1 << ". " << Valise[i] << std::endl;
		  }
		std::cout << std::endl;
		std::cin >> remove;
        
		std::cout << "Are you sure you want to remove " << Valise[remove-1] << "? Once it's gone, it's gone and you'll have to go find it again. Things have a way of disappearing around here. (Y or N)" << std::endl;
		
		while (removeChoice!='y' && removeChoice!='Y' && removeChoice!='n' && removeChoice!='N') {
			std::cin >> removeChoice;
			if (removeChoice == 'y' || removeChoice == 'Y') {
			
			// remove flags here
				if(Valise[remove-1] == "Flashlight") {
					setFlashlight(0);
				 }
				 else if (Valise[remove-1] == "Glass") {
					setGlass(0);
				 }
				 else if (Valise[remove-1] == "Ding-Dongs") {
				   setFood(0);
				 }
				 else if (Valise[remove-1] == "Key") {
				   setKey(0);
				 }

			 
			winCheck();
			 std::cout << "Ok. The " << Valise[remove-1] << " has been removed from your Valise." << std::endl;
			Valise.erase (Valise.begin() +(remove-1));
			showInventory();
		   } // end remove = 'y'
		else if (removeChoice == 'n' || removeChoice =='N') {
			std::cout << "Ok, nothing has been removed from your Valise." << std::endl;
			showInventory();
			}
		else {
			std::cout << "I don't know what that means.  Y or N is the right response." << std::endl;
		 }
	 } // end while
	} // end valise size check
}



/*************************************************************************************************
 ** Function:			Player "set" and "get" functions (multiple)
 ** Description:		 Sets and Gets values for various Player protected data members.	 
 ** Parameters:			varies - string or int
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/



void Player::setName(std::string playerName) {

 name = playerName;

}

std::string Player::getName() {

return name;

}

void Player::setFlashlight(int flash) {
	flashlight = flash;
}

int Player::getFlashlight() {

	return flashlight;
	
}

void Player::setKey(int skeleton) {
	key = skeleton;
}

int Player::getKey() {
	return key;
}

void Player::setElectricity(int electric) {
	electricity = electric;
}

int Player::getElectricity() {
	return electricity;
}

void Player::setFireplace(int fire) {
	fireplace = fire;
}

int Player::getFireplace() {
	return fireplace;
}

void Player::setFood(int eat) {
	food = eat;
}

int Player::getFood() {
	return food;
}

void Player::setGlass(int cup) {
	glass = cup;
}

int Player::getGlass() {
	return glass;
}

void Player::setBlender(int blend) {
	blender = blend;
}

int Player::getBlender() {
	return blender;
}

int Player::getNumItems() {

	return Valise.size();

}

