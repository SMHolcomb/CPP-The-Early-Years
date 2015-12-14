/*************************************************************************************************
 ** Program Filename:	Creature.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Class specification file for Creature Class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#ifndef __Creature
#define __Creature

//#include <iostream>
#include <string>


// specifications for Creature class
class Creature {

	public:
	
		std::string type;
		std::string name;
		std::string team;
		int alive_flag;
		int attack_DiceNum;
		int attack_DiceSides;
		int defense_DiceNum;
		int defense_DiceSides;
		int armor;
		double strengthPoints;  //changed to double to handle halving from achilles
		double maxStrengthPoints; // for calculating Damage restore
		int order;
		int achilles;
		int shadow;

		virtual std::string getType();
		virtual int attackRoll(Creature *a, Creature *d);
		virtual int defenseRoll(Creature *a, Creature *d);
		virtual int getAttack_DiceNum();
		virtual int getAttack_DiceSides();
		virtual int getDefense_DiceNum();
		virtual int getDefense_DiceSides();
		virtual int getStrengthPoints();
		virtual void setType(std::string);
		virtual void setAchilles(int);
		virtual int getAchilles();
		virtual void setShadow(int);
		virtual int getShadow();
		virtual void setDamageRestore();
		
};







#endif 
