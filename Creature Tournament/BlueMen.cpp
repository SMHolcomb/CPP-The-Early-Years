/*************************************************************************************************
 ** Program Filename:	BlueMen.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Methods and functions for BlueMen class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#include "BlueMen.hpp"

/*************************************************************************************************
 ** Function:			BlueMen::BlueMen(std::string)
 ** Description:		constructor for BlueMen Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

BlueMen::BlueMen(std::string name2, std::string team1) {

	type = "Blue Men";
	name = name2;
	team = team1;
	alive_flag = 1;
	attack_DiceSides = 10;
	attack_DiceNum = 2;
	defense_DiceSides = 6;
	defense_DiceNum = 3;
	armor = 3;
	strengthPoints = 12;
	maxStrengthPoints = 12;
    achilles = 1;
	shadow = 1;
	order = 1;

}



/*************************************************************************************************
 ** Function:			BlueMen::BlueMen()
 ** Description:		constructor for BlueMen Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

BlueMen::BlueMen() {

	type = "Blue Men";  
	attack_DiceSides = 10;
	attack_DiceNum = 2;
	defense_DiceSides = 6;
	defense_DiceNum = 3;
	armor = 3;
	strengthPoints = 12;
    achilles = 1;
	shadow = 1;

}

