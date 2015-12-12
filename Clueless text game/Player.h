/*************************************************************************************************
 ** Program Filename:	Player.h
 ** Author:				Stephanie Holcomb
 ** Date:				December 5, 2015
 ** Description:		Contains class specifications for Player Class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#ifndef __Player__
#define __Player__

#include <iostream>
#include <vector>
#include <string>


class Player {

	protected:
		std::string name;
		int flashlight;
		int glass;
		int electricity;
		int food;
		int blender;
		int fireplace;
		int key;
		int itemCount;
		int maxItems;  // 3
		
		
	public:
		Player(std::string);
		~Player();
		std::vector<std::string> Valise;
		std::string getName();
		void setName(std::string);
		void addItem(Player,std::string);
		void removeItem();
		void showInventory();
		int getNumItems();
		void setFlashlight(int);
		int getFlashlight();
		void setKey(int);
		int getKey();
		void setElectricity(int);
		int getElectricity();
		void setFireplace(int);
		int getFireplace();
		void setFood(int);
		int getFood();
		void setGlass(int);
		int getGlass();
		void setBlender(int);
		int getBlender();
		void winCheck();
		
		
};


#endif 
