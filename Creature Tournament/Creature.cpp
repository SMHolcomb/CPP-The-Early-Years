/*************************************************************************************************
 ** Program Filename:	Creature.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Methods and functions for Creature class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>
#include "Creature.hpp"

/*************************************************************************************************
 ** Function:			Creature::setType()
 ** Description:		sets Type of creature - i.e. Barbarian etc.  Especially helpful for same type
 **						    battles. i.e. Barbarian vs. Barbarian will be Barbarian vs Barbarian #2
 **						 
 ** Parameters:			attacker and defender (Creatures)
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/


void Creature::setType(std::string t) {

	this->type = t;
}

/*************************************************************************************************
 ** Function:			Creature::getType()
 ** Description:		returns Type of creature - 
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

std::string Creature::getType() {

	return this->type;

}

/*************************************************************************************************
 ** Function:			Creature::getAttack_DiceNum()
 ** Description:		returns number of attack dice to roll 
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Creature::getAttack_DiceNum() {

 return this->attack_DiceNum;

}

/*************************************************************************************************
 ** Function:			Creature::getAttack_DiceSides()
 ** Description:		returns number of sides of attack dice 
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Creature::getAttack_DiceSides() {

	return this->attack_DiceSides;

}

/*************************************************************************************************
 ** Function:			Creature::getDefense_DiceNum()
 ** Description:		returns number of defense dice to roll
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Creature::getDefense_DiceNum() {
 
	return this->defense_DiceNum;

}

/*************************************************************************************************
 ** Function:			Creature::getDefense_DiceSides()
 ** Description:		returns number of sides of defense dice 
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Creature::getDefense_DiceSides() {
 
 return this->defense_DiceSides;

}

/*************************************************************************************************
 ** Function:			Creature::getStrengthPoints)
 ** Description:		returns strengthPoints
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Creature::getStrengthPoints()  {

	return this->strengthPoints;
}

/*************************************************************************************************
 ** Function:			Creature::attackRoll()
 ** Description:		rolls attack dice
 **						  
 **						 
 ** Parameters:			two Creature objects
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Creature::attackRoll(Creature *a, Creature *d) {

	int attack = 0;
	int numb = this->getAttack_DiceNum();
	int side = this->getAttack_DiceSides();

	for (int i = 1; i <= numb; i++) {
		int roll =  ((rand() % side) + 1);
		attack += roll;
		//std::cout << "roll " << i << ": " << roll << std::endl;
		}
	
	std::cout << a->name << "'s Attack roll: " << attack << std::endl;
	
	return attack;
	
}

/*************************************************************************************************
 ** Function:			Creature::defenseRoll()
 ** Description:		rolls defense dice
 **						  
 **						 
 ** Parameters:			two Creature objects
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Creature::defenseRoll(Creature *a, Creature *d) {

	int defense= 0;
	int number = this->getDefense_DiceNum();
	int sides = this->getDefense_DiceSides();


	for (int i = 1; i <= number; i++) {
		int roll =  ((rand() % sides) + 1);
		defense += roll;
		//std::cout << "roll " << i << ": " << roll << std::endl;
		}
	
	std::cout << d->name << "'s Defense roll: " << defense << std::endl;
	
	return defense;
	
}

/*************************************************************************************************
 ** Function:			Creature::setAchilles()
 ** Description:		sets Achilles factor
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

void Creature::setAchilles(int x) {


}

/*************************************************************************************************
 ** Function:			Creature::getAchilles()
 ** Description:		gets Achilles factor
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Creature::getAchilles() {
 
  return this->achilles;
 
}

/*************************************************************************************************
 ** Function:			Creature::setShadow()
 ** Description:		sets shadow factor
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Creature::setShadow(int x) {
 
 this->shadow = x;

}

/*************************************************************************************************
 ** Function:			Creature::getShadow()
 ** Description:		gets shadow factor
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Creature::getShadow() {
 
 return this->shadow;
 
}

/*************************************************************************************************
 ** Function:			Creature::setDamageRestore()
 ** Description:		sets shadow factor
 **						  
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Creature::setDamageRestore() {
 
 // damage restore is calculated as (maximum (starting) Strength points - current strength points) * 0.5
 
 double restore = (this->maxStrengthPoints - this->strengthPoints) * 0.5;
 std::cout << "Current total damage is " << (this->maxStrengthPoints - this->strengthPoints) << "." << std::endl;
 this->strengthPoints = this->strengthPoints + restore;
 std::cout << "Restoring " << restore << " points.  New Strength Points is " << this->strengthPoints << std::endl;
}


