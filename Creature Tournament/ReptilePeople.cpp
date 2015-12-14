/*************************************************************************************************
 ** Program Filename:	ReptilePeople.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Methods and functions for ReptilePeople class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#include "ReptilePeople.hpp"

/*************************************************************************************************
 ** Function:			ReptilePeople::ReptilePeople(std::string)
 ** Description:		constructor for ReptilePeople Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

ReptilePeople::ReptilePeople(std::string name2, std::string team1) {

	type = "Reptile People";
	name = name2;
	team = team1;
	alive_flag = 1;
	attack_DiceSides = 6;
	attack_DiceNum = 3;
	defense_DiceSides = 6;
	defense_DiceNum = 1;
	armor = 7;
	strengthPoints = 18;
	maxStrengthPoints = 18;
	achilles = 1;
	shadow = 1;
	order = 1;
}



/*************************************************************************************************
 ** Function:			ReptilePeople::ReptilePeople()
 ** Description:		constructor for ReptilePeople Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

ReptilePeople::ReptilePeople() {

	type = "Reptile People";  
	attack_DiceSides = 6;
	attack_DiceNum = 3;
	defense_DiceSides = 6;
	defense_DiceNum = 1;
	armor = 7;
	strengthPoints = 18;
	achilles = 1;
	shadow = 1;

}
