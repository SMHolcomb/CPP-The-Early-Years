/*************************************************************************************************
 ** Program Filename:	BlueMen.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Class specification file for BlueMen Class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/
 
#ifndef __BlueMen
#define __BlueMen

#include <iostream>
#include "Creature.hpp"

// specifications for BlueMen class
class BlueMen:public Creature {

	public:
		
		BlueMen();
		BlueMen(std::string name, std::string team);
		~BlueMen();

};


#endif 
