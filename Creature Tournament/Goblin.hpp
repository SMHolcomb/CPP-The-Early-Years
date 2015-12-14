/*************************************************************************************************
 ** Program Filename:	Goblin.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Class specification file for Goblin Class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/
 
#ifndef __Goblin
#define __Goblin

#include <iostream>
#include "Creature.hpp"

// specifications for Goblin class
class Goblin:public Creature {

	public:
	
	Goblin();
	Goblin(std::string name, std::string team);
	~Goblin();
	int attackRoll(Creature *, Creature *);
	void setAchilles(int);	

};


#endif 
