/*************************************************************************************************
 ** Program Filename:	Goblin.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Methods and functions for Goblin class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/


#include <string>
#include <cstdlib>
#include "Goblin.hpp"


/*************************************************************************************************
 ** Function:			Goblin::Goblin(std::string)
 ** Description:		constructor for Goblin Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Goblin::Goblin(std::string name2, std::string team1) {

	type = "Goblin";
	name = name2;
	team = team1;
	attack_DiceSides = 6;
	attack_DiceNum = 2;
	defense_DiceSides = 6;
	defense_DiceNum = 1;
	armor = 3;
	strengthPoints = 8;
	maxStrengthPoints = 8;
	achilles = 1;
	shadow = 1;
	order = 1;

}

/*************************************************************************************************
 ** Function:			Goblin::Goblin()
 ** Description:		Default constructor for Goblin Class
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Goblin::Goblin() {

	type = "Goblin";
	name = "";
	alive_flag = 1;
	attack_DiceSides = 6;
	attack_DiceNum = 2;
	defense_DiceSides = 6;
	defense_DiceNum = 1;
	armor = 3;
	strengthPoints = 8;
	achilles = 1;
	shadow = 1;

}



/*************************************************************************************************
 ** Function:			Goblin::setAchilles()
 ** Description:		called by attackRoll. Sets achilles factor
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Goblin::setAchilles(int x) {

 this->achilles = x;
 
}

/*************************************************************************************************
 ** Function:			Goblin::attackRoll()
 ** Description:		overloaded attackRoll function for Goblin class - rolls attack as usual
 **						    but calls setachilles function based on attack roll and opponent type
 **						 
 ** Parameters:			attacker and defender (Creatures)
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int Goblin::attackRoll(Creature *a, Creature *d) {

		/* 
		   // original for testing Goblin Achilles factor from main
			if(a->type == "Goblin") {
				int GoblinAttack = rand() % 2;
				//std::cout << ": " << shadowDamage << std::endl;
			if (GoblinAttack==0) { // then assume a 12 was rolled
				attack = 12;
				}
			else {
				attack = a->attackRoll();
			}	 
		}
		*/
	
	std::cout << "calling Goblin attack roll\n" << std::endl;
	int attack = 0;
	int numb = this->getAttack_DiceNum();
	int side = this->getAttack_DiceSides();

	for (int i = 1; i <= numb; i++) {
	  int roll =  ((rand() % side) + 1);
	  attack += roll;
	  //std::cout << "roll " << i << ": " << roll << std::endl;
	}
	
	std::cout << a->getType() << "'s Attack roll: " << attack << std::endl;
	
	if(attack==12 && d->type!= "Goblin") {
		 
		 a->setAchilles(2);
		   
		std::cout << "Achilles set to " << a->getAchilles() << std::endl;
		   
		}
		  
	 else {
		  
		// leave achilles as 1
		std::cout << "Achilles is still " << a->getAchilles() << std::endl;

		}

	return attack;
	
}



