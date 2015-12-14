/*************************************************************************************************
 ** Program Filename:	Barbarian.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Class specification file for Barbarian Class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#ifndef __Barbarian
#define __Barbarian

#include <string>
#include "Creature.hpp"

// Barbarian Class specifications
class Barbarian:public Creature {

	public:
		
		Barbarian();
		Barbarian(std::string name, std::string team);
		~Barbarian();

};


#endif 
