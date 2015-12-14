/*************************************************************************************************
 ** Program Filename:	Shadow.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Methods and functions for Shadow class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/
 
#include <cstdlib>
#include "Shadow.hpp"


/*************************************************************************************************
 ** Function:			Shadow::Shadow(std::string)
 ** Description:		constructor for Shadow Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Shadow::Shadow(std::string name2, std::string team1) {

	type = "Shadow";
	name = name2;
	team = team1;
	alive_flag = 1;
	attack_DiceSides = 10;
	attack_DiceNum = 2;
	defense_DiceSides = 6;
	defense_DiceNum = 1;
	armor = 0;  //********armor for the shadow = special
	strengthPoints = 12;
	maxStrengthPoints = 12;
    achilles = 1;
	shadow = 1;
	order = 1;
}


/*************************************************************************************************
 ** Function:			Shadow::Shadow()
 ** Description:		constructor for Shadow Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Shadow::Shadow() {

	type = "Shadow";  
	attack_DiceSides = 10;
	attack_DiceNum = 2;
	defense_DiceSides = 6;
	defense_DiceNum = 1;
	armor = 0;  //********armor for the shadow = special
	strengthPoints = 12;
    achilles = 1;
	shadow = 1;
}

/*************************************************************************************************
 ** Function:			Shadow::setShadow()
 ** Description:		sets shadow factor - called from Shadow::defenseRoll()
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Shadow::setShadow(int x) {

	this->shadow = x;
 
}

/*************************************************************************************************
 ** Function:			Shadow::defenseRoll()
 ** Description:		overloaded defenseRoll function for Shadow class - rolls defense as usual
 **						    but calls setShadow function based on random damage function
 ** Parameters:			attacker and defender (Creatures)
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/


int Shadow::defenseRoll(Creature *a, Creature *d) {

  std::cout << "[Entering shadow defense roll function]\n" << std::endl;
  
	int defense= 0;
	int number = this->getDefense_DiceNum();
	int sides = this->getDefense_DiceSides();

	for (int i = 1; i <= number; i++) {
	
		int roll =  ((rand() % sides) + 1);
		defense += roll;

	  //std::cout << "roll " << i << ": " << roll << std::endl;
	  }
	 
	std::cout << d->getType() << "'s Defense roll: " << defense << std::endl;
	   
	// damage has 50% chance of being 0 d->setShadow(0);
	int shadowDamage = rand() % 2;
	std::cout << "Random Shadow damage should be: " << shadowDamage << std::endl;
		
	if (shadowDamage==0) {
		//set shadow multiply factor to 0 for no damage
		d->setShadow(0);
		std::cout << "Shadow is set to " << d->getShadow() << std::endl;
		}
	else {
		//set shadow multiply factor to 1 for damage calculated as usual
		d->setShadow(1);
		std::cout << "Shadow is set to " << d->getShadow() << std::endl;
		}

	return defense;
	
}
