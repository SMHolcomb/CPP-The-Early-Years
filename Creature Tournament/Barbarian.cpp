/*************************************************************************************************
 ** Program Filename:	Barbarian.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Methods and functions for Barbarian class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#include <string>
#include "Barbarian.hpp"

/*************************************************************************************************
 ** Function:			Barbarian::Barbarian(std::string)
 ** Description:		constructor for Barbarian Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Barbarian::Barbarian(std::string name2, std::string team1) {

	type = "Barbarian";
	name = name2;
	team = team1;
	alive_flag = 1;
	attack_DiceSides = 6;
	attack_DiceNum = 2;
	defense_DiceSides = 6;
	defense_DiceNum = 2;
	armor = 0;
	strengthPoints = 12;
	maxStrengthPoints = 12;
    achilles = 1;
	shadow = 1;
	order = 1;
}



/*************************************************************************************************
 ** Function:			Barbarian::Barbarian()
 ** Description:		constructor for Barbarian Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Barbarian::Barbarian() {

	type = "Barbarian";
	attack_DiceSides = 6;
	attack_DiceNum = 2;
	defense_DiceSides = 6;
	defense_DiceNum = 2;
	armor = 0;
	strengthPoints = 12;
    achilles = 1;
	shadow = 1;

}
