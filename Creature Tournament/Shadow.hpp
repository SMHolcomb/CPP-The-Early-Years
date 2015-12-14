/*************************************************************************************************
 ** Program Filename:	Shadow.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Class specification file for Shadow Class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/


#ifndef __Shadow
#define __Shadow

#include <iostream>
#include "Creature.hpp"

// Specifications for Shadow Class
class Shadow:public Creature {

	public:
		
		Shadow();
		Shadow(std::string name, std::string team);
		~Shadow();
		int defenseRoll(Creature *, Creature *);
		void setShadow(int);

};


#endif 
