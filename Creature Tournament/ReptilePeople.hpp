/*************************************************************************************************
 ** Program Filename:	ReptilePeople.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Class specification file for ReptilePeople Class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#ifndef __ReptilePeople
#define __ReptilePeople

#include <iostream>
#include "Creature.hpp"

// specifications for ReptilePeople class
class ReptilePeople:public Creature {

	public:
	
		ReptilePeople();
		ReptilePeople(std::string name, std::string team);
		~ReptilePeople();
	

};


#endif