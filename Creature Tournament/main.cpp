/*************************************************************************************************
 ** Program Filename:	Main.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 18, 2015
 ** Description:		Main implementation file for Creature Game
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "ReptilePeople.hpp"
#include "BlueMen.hpp"
#include "Goblin.hpp"
#include "Shadow.hpp"
#include "Queue.hpp"
#include "Stack.hpp"


void playTournament(Queue, Queue);
void playTournamentDevCopy(Queue, Queue); //for testing once complete


/*************************************************************************************************
 ** Function:			main
 ** Description:		main driver script for testing.
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int main() {
	
	int choose;
	int numCreatures;
	int creatureType;
	std::string creatureName;
	Queue teamRed;
	Queue teamBlue;
	Stack teamDead;
	std::vector<Creature*> tournament;
	
	Creature *p1; //pointer to creature 1
	Creature *p2; //pointer to creature 2
	
	// seed random for dice rolls
	srand((unsigned)time(0));
	
while (choose!=2) {
	
	   std::cout << "\n\nWelcome to the Creature Tournament Game:\n" << std::endl;
	   std::cout << "What would you like to do?\n" << std::endl;
	   std::cout << "1. Choose your teams and Play" << std::endl;
	   std::cout << "2. Quit" << std::endl;
	   std::cin >> choose;

	switch(choose) {
	
	case 1: {
	   std::cout << "Please enter the number of Creatures for each team: " << std::endl;
	   
	    std::cin >> numCreatures;
			
		// loop here twice to display menu for each player
		for (int i = 1; i <= 2; i++) {
			std::cout << "****************************" << std::endl;
			std::cout << "\n    Player " << i << ": " << std::endl << std::endl;
			std::cout << "****************************" << std::endl;
			
			// get type of creature
			std::cout << "For reference here are the characters you can choose from" << std::endl;
			std::cout << "1. Barbarian " << std::endl;
			std::cout << "2. Goblin" << std::endl;
			std::cout << "3. Reptile People" << std::endl;
			std::cout << "4. Blue Men" << std::endl;
			std::cout << "5. The Shadow" << std::endl;
							
			//now loop here and get user 1's characters and user 2 characters
			for (int j = 0; j < numCreatures; j++) {
			  std::cout << "\nPlease enter a creature and name for fighter #" << j + 1 << std::endl;
			  std::cout << "Creature Type (number from above): ";
			  std::cin >> creatureType; // integer
			  std::cout << "\nCreature Name: ";
			  std::cin.ignore(1000, '\n');
			  std::getline(std::cin,creatureName);
		
			  std::cout << std::endl;


				
		if (i == 1) {
			switch(creatureType) {
				case 1:
					p1= new Barbarian(creatureName, "Red");
					
					break;
				case 2:
					p1 = new Goblin(creatureName, "Red");
					
					break;
				case 3:
					p1 = new ReptilePeople(creatureName, "Red");
					
					break;
				case 4:
					p1 = new BlueMen(creatureName, "Red");
					
					break;
				case 5:
					p1 = new Shadow(creatureName, "Red");
				
					break;
				default:
				    std::cout << "try again" << std::endl;
					break;
			
				} // end switch
				
				teamRed.addBack(p1);
				tournament.push_back(p1);
			} // end if team 1
			
			
		if (i == 2) {
			switch(creatureType) {
				case 1:
					p2= new Barbarian(creatureName, "Blue");
				
					break;
				case 2:
					p2 = new Goblin(creatureName, "Blue");
				
					break;
				case 3:
					p2 = new ReptilePeople(creatureName, "Blue");
				
					break;
				case 4:
					p2 = new BlueMen(creatureName, "Blue");
				
					break;
				case 5:
					p2 = new Shadow(creatureName, "Blue");
				
					break;
				default:
				    std::cout << "try again" << std::endl;
				
					break;
			
				} // end switch
				teamBlue.addBack(p2);
				tournament.push_back(p2);
			} // end if team 2
			
			} // end loop for one player
		}  // end loop to get both players
						
			
			// Display both team's rosters to user
			QueueNode *temp = teamRed.front;
			QueueNode *temp2 = teamBlue.front;
			
			if (temp == NULL) {
					
				std::cout << "There is no lineup available!" << std::endl;
		
				}
			 else {
			std::cout << "****************************" << std::endl; 
			std::cout << "Here is the current lineup:" << std::endl;
			std::cout << "****************************" << std::endl;
			std::cout << std::setw(20) << std::left << "Team Red:            " << std::setw(10) << std::left << "Team Blue: \n" << std::endl;
			
			while (temp!=NULL) {
			    std::string creat = temp->creature->type + " " + temp->creature->name;
				std::string creat2 = temp2->creature->type + " " + temp2->creature->name;
				std::cout << std::setw(20) << std::left << creat << std::setw(20) << std::left << creat2 << std::endl;
				
				temp = temp->next;
				temp2 = temp2->next;
			 }
			 
			 std::cout << std::endl;
			}
			
			 
			  // send Players to battle
			  
			  playTournament(teamRed,teamBlue);
			  //playTournamentDevCopy(teamRed,teamBlue); // for testing - prints couts of all steps
			  
			  
			  // output results to user
			  std::cout << " **** FINAL SCORES AND RESULTS ***** \n" << std::endl;
			  
			  std::cout << " Top 3 winners are the last 3 creatures standing! " << std::endl;
			  std::cout << "(in the event two creatures from the same team are left alive and thus no final battle is conducted, placement for first and second will be based on final strength points)" << std::endl;
			  std::cout << " Winning Team is the one with the most Strength Points, regardless of outcome of fighters" << std::endl;
			  std::cout << std::endl;

			 
				// winning team is team with most points, regardless of survivors
				int blueCount = 0;
				double bluePoints = 0;
				int redCount = 0;
				double redPoints = 0;
			
				std::cout << std::setw(8) << "Team" << std::setw(8) << "Score     Name" << std::endl;
				
			 //sort winners by score
		
			 std::vector<double> sortNums;
			 // copy to vector for sorting
			 for (int g = 0; g < tournament.size() ; g++) {
			   sortNums.push_back(((tournament.at(g)->alive_flag * 100) + tournament.at(g)->strengthPoints));
			 }
			//bubble sort
			for(int i = 0; i < sortNums.size(); i++) {
			
				double maximumIndex = i;
				double maximumValue = sortNums[i];
		
			for (int index = i; index < sortNums.size() ; index++) {
			
				if(sortNums[index] > maximumValue) {
				
					maximumValue = sortNums[index];
					maximumIndex = index;
				}
		}
			sortNums[maximumIndex] = sortNums[i];
			sortNums[i] = maximumValue;
		}
		//search for match and bring back creature name and team
	   //for (int u = 0; u < sortNums.size(); u++) {
		for (int u = 0; u < 3; u++) {
			 
			 for (int v = 0; v < sortNums.size(); v++) {
			     if (sortNums[u] == ((tournament.at(v)->alive_flag * 100) + tournament.at(v)->strengthPoints)) {
					std::cout << std::setw(8) << tournament.at(v)->team << std::setw(8) << ((tournament.at(v)->alive_flag * 100) + tournament.at(v)->strengthPoints) << "     " << tournament.at(v)->name << std::endl;
				  //tally team scores
				 if (tournament.at(v)->team == "Red") {
						redCount +=1;
						redPoints += tournament.at(v)->strengthPoints;
						}
					if (tournament.at(v)->team == "Blue") {
					blueCount +=1;
					bluePoints += tournament.at(v)->strengthPoints;
					}
				  }
				}
			} // end loop through vector
				std::cout << "\nRed total: " << redPoints << std::endl;
			  
			  std::cout << "Blue total: " << bluePoints << std::endl;
			  if(redPoints > bluePoints)
				std::cout << "The Red Team is the winner!!" << std::endl;
			  else if (bluePoints > redPoints)
				std::cout << "The Blue Team is the winner!!" << std::endl;
			  else
			   std::cout << "It's a Tie Tournament!!" << std::endl;
		break;
		}
     case 2: {
		std::cout << "Good bye" << std::endl;
		break;
		}
	 case 3: {
		std::cout << "try again." << std::endl;
		break;
		}
	} // end switch
	
   } // end main menu loop

    return 0;
}


/*************************************************************************************************
 ** Function:			playTournament
 ** Description:		functions for actual fighting and score calculation - includes console 
 **						 messaging for all actions for debugging
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

void playTournament(Queue teamRed, Queue teamBlue) {

	int count;
	int attack;
	int ord;
	double defense;
	double damage;
	
	Stack teamDead;
	
      //Begin loop of ALL creatures in lineup
while (teamRed.front !=NULL && teamBlue.front !=NULL) {
	  count = 0;
	  Creature *red = teamRed.front->creature;
      Creature *blue = teamBlue.front->creature;

	 
	   //begin individual round here
	      std::cout << "********************************" << std::endl;
	      std::cout << "Matchup: " << red->name << " vs " << blue->name << std::endl;
		  std::cout << "********************************" << std::endl;
		  
	   do {
			count+=1;
			std::cout<<"\n\nRound " << count << std::endl;
			
			std::cout << red->name << " is attacking " << blue->name << std::endl;

			std::cout << std::endl;
			// call specific rolls - overload for Goblin/Shadow
			attack = red->attackRoll(red,blue);
			defense = blue->defenseRoll(red,blue);
			
			// defense = defense / achilles value determined in Goblins attack roll
			defense = defense/red->getAchilles();

			// damage = adjusted by Shadow factor determined in Shadow' defense roll
			damage = ((attack - defense) - blue->armor) * blue->getShadow();
			
			//std::cout << "Achilles factor is: " << achilles << std::endl;
			std::cout << blue->name << "'s armor: " << blue->armor << std::endl;
			std::cout << "Damage to " << blue->name << ": " << damage << std::endl;
			
			// if damage is 0 or negative, don't change defender's strength points
			if(damage < 0) {
			
				// don't do anything with defenders armor or Strength Points
				std::cout << "Strength Points remain the same: " << blue->strengthPoints << std::endl;
			 }
						 
			 else {
			 
				 std::cout << "Previous strength Points: " << blue->strengthPoints << std::endl;
				 blue->strengthPoints -= damage;
				 std::cout << "Current strength Points: " << blue->strengthPoints << std::endl;
				 
				 }
	
		// blue = dead and red is the winner
	if (blue->strengthPoints <=0) {
			std::cout << "\n************************************" << std::endl;
			std::cout << "*** " << red->name << " is the winner in " << count << " rounds ***\n\n" << std::endl;
			teamDead.add(blue); // add blue to the dead stack
			teamBlue.removeFront();  // blue  lost so remove
			
			teamRed.addBack(red);   // red won so add red back to end of lineup then
			teamRed.removeFront();  // remove red from front of queue
			std::cout << red->name << "'s strength points after this round: " << red->strengthPoints << std::endl;
			
			// give red winner some strengthpoints back
			
			std::cout << red->name << " has been healed! " << std::endl;
			red->setDamageRestore();
			std::cout << "\n************************************" << std::endl;
			}


		//start reverse attack here
			//check if one already has lost mid-round
		    if (red->strengthPoints <= 0 || blue->strengthPoints <= 0) {
  
				std::cout << "\n\n This game was over mid-round." << std::endl;
	
			}
			
			
			
	

		else { //continue on
		
			std::cout << "\n" << blue->name << " is attacking " << red->name << std::endl;
			std::cout << std::endl;
			// call specific rolls - overload for Goblin/Shadow
			attack = blue->attackRoll(blue,red);
			defense = red->defenseRoll(blue,red);
			
			// defense = defense / achilles value determined in Goblins attack roll
			defense = defense/blue->getAchilles();

			// damage = adjusted by Shadow factor determined in Shadow' defense roll
			damage = ((attack - defense) - red->armor) * red->getShadow();
			
			//std::cout << "Achilles factor is: " << achilles << std::endl;
			std::cout << red->name << "'s armor: " << red->armor << std::endl;
			std::cout << "Damage to " << red->name << ": " << damage << std::endl;
			
			// if damage is 0 or negative, don't change defender's strength points
			if(damage < 0) {
			
				// don't do anything with defenders armor or Strength Points
				std::cout << "Strength Points remain the same: " << red->strengthPoints << std::endl;
			 }
			 
			 else {
			 
				 std::cout << "Previous strength Points: " << red->strengthPoints << std::endl;
				 red->strengthPoints -= damage;
				 std::cout << "Current strength Points: " << red->strengthPoints << std::endl;
				 
				 }
			} // end midpoint check if anyone's dead
			
	 /// red = dead and blue is the winner
	 	if (red->strengthPoints <=0) {
			std::cout << "\n************************************" << std::endl;
			std::cout << "\n*** " << blue->name << " is the winner in " << count << " rounds ***\n\n" << std::endl;
			teamDead.add(red); // add red to stack because they're dead
			//std::cout << "\nHere is the current dead pile:" << std::endl;
			//teamDead.showList();
			teamRed.removeFront();  //remove dead red from front of lineup
			teamBlue.addBack(blue);   // add blue to end of queue because they won
			teamBlue.removeFront();  // remove blue from front of queue
			
			std::cout << blue->name << "'s strength points after this round: " << blue->strengthPoints << std::endl;
			
			// give blue winner some strengthpoints back
			
			std::cout << blue->name << " has been healed! " << std::endl;
			blue->setDamageRestore();
			std::cout << "\n************************************" << std::endl;
			
			}
		
		} while (red->strengthPoints > 0 && blue->strengthPoints > 0);

	}
	
	std::cout << "\n **** FINAL SCORES AND RESULTS ***** \n" << std::endl;
			  
			  std::cout << " Top 3 winners are the last 3 creatures standing! " << std::endl;
			  std::cout << "(in the event two creatures from the same team are left alive and thus no final battle is conducted, placement for first and second will be based on final strength points)" << std::endl;
			  std::cout << "\nThe Winning Team is the one with the most Strength Points, regardless of outcome of fighters" << std::endl;
	
		//std::cout << "Here are the final results: " << std::endl;
		teamDead.showList();
		std::cout << std::endl;

	
	  // return to main function here

}



/*************************************************************************************************
 ** Function:			playTournamentDevCopy
 ** Description:		functions for actual fighting and score calculation - includes console 
 **						 messaging for all actions for debugging
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

void playTournamentDevCopy(Queue teamRed, Queue teamBlue) {

	int count;
	int attack;
	double defense;
	double damage;
	
	Stack teamDead;
	
      //Begin loop of ALL creatures in lineup
while (teamRed.front !=NULL && teamBlue.front !=NULL) {
	  count = 0;
	  Creature *red = teamRed.front->creature;
      Creature *blue = teamBlue.front->creature;

	 
	   //begin individual round here
	      std::cout << "********************************" << std::endl;
	      std::cout << "Matchup: " << red->name << " vs " << blue->name << std::endl;
		  std::cout << "********************************\n" << std::endl;
		  
	   do {
			count+=1;
			std::cout<<"\nRound " << count << std::endl;
			
			std::cout << red->name << " is attacking " << blue->name << std::endl;

			std::cout << std::endl;
			// call specific rolls - overload for Goblin/Shadow
			attack = red->attackRoll(red,blue);
			defense = blue->defenseRoll(red,blue);
			
			// defense = defense / achilles value determined in Goblins attack roll
			defense = defense/red->getAchilles();
			std::cout << "current defense roll: " << defense << std::endl;

			// damage = adjusted by Shadow factor determined in Shadow' defense roll
			damage = ((attack - defense) - blue->armor) * blue->getShadow();
			
			//std::cout << "Achilles factor is: " << achilles << std::endl;
			std::cout << blue->getType() << "'s armor: " << blue->armor << std::endl;
			std::cout << "Damage is: " << damage << std::endl;
			
			// if damage is 0 or negative, don't change defender's strength points
			if(damage < 0) {
			
				// don't do anything with defenders armor or Strength Points
				std::cout << "Strength Points remain the same " << blue->strengthPoints << std::endl;
			 }
						 
			 else {
			 
				 std::cout << "previous strength Points: " << blue->strengthPoints << std::endl;
				 blue->strengthPoints -= damage;
				 std::cout << "Current strength Points: " << blue->strengthPoints << std::endl;
				 
				 }
	
		// blue = dead and red is the winner
	if (blue->strengthPoints <=0) {
			std::cout << "*** " << red->name << " is the winner in " << count << " rounds ***\n\n" << std::endl;
			teamDead.add(blue); // add blue to the dead stack
			std::cout << "team blue queue before adjustment is: " << std::endl;
			teamBlue.showList();
			teamBlue.removeFront();  // blue  lost so remove
			std::cout << "team blue queue after removing front is: " << std::endl;
			teamBlue.showList();
	
			std::cout << "\nNow adding red winner to back of current lineup" << std::endl;
			teamRed.addBack(red);   // red won so add red back to end of lineup then
			std::cout << std::endl;
			teamRed.showList();
			
			std::cout <<"\nNow removing red winner from front of lineup" << std::endl;
			teamRed.showList();

			teamRed.removeFront();  // remove red from front of queue
			std::cout << "team red queue is now " << std::endl;
			teamRed.showList();
			
			std::cout << "red strength before healing: " << red->strengthPoints << std::endl;
			// give red winner some strengthpoints back
			red->strengthPoints = red->strengthPoints * 1.5;
			std::cout << "red strength after healing: " << red->strengthPoints << std::endl;
			
			}


		//start reverse attack here
			//check if one already has lost mid-round
		    if (red->strengthPoints <= 0 || blue->strengthPoints <= 0) {
  
				std::cout << "\n\n This game was over mid-round." << std::endl;
	
			}
	

		else { //continue on
		
			std::cout << "\n" << blue->name << " is attacking " << red->name << std::endl;
			std::cout << std::endl;
			// call specific rolls - overload for Goblin/Shadow
			attack = blue->attackRoll(blue,red);
			defense = red->defenseRoll(blue,red);
			
			// defense = defense / achilles value determined in Goblins attack roll
			defense = defense/blue->getAchilles();
			std::cout << "current defense roll: " << defense << std::endl;

			// damage = adjusted by Shadow factor determined in Shadow' defense roll
			damage = ((attack - defense) - red->armor) * red->getShadow();
			
			//std::cout << "Achilles factor is: " << achilles << std::endl;
			std::cout << red->getType() << "'s armor: " << red->armor << std::endl;
			std::cout << "Damage is: " << damage << std::endl;
			
			// if damage is 0 or negative, don't change defender's strength points
			if(damage < 0) {
			
				// don't do anything with defenders armor or Strength Points
				std::cout << "Strength Points remain the same " << red->strengthPoints << std::endl;
			 }
			 
			 else {
			 
				 std::cout << "previous strength Points: " << red->strengthPoints << std::endl;
				 red->strengthPoints -= damage;
				 std::cout << "Current strength Points: " << red->strengthPoints << std::endl;
				 
				 }
			} // end midpoint check if anyone's dead
			
	 // ******************
	   //check red's strength points. if <=0 then they are dead. Add to stack and remove from
					// lineup
	// ***********************


	if (red->strengthPoints <=0) {
			std::cout << "*** " << blue->name << " is the winner in " << count << " rounds ***\n\n" << std::endl;
			teamDead.add(red); // add red to stack because they're dead
			std::cout << "\nHere is the current dead pile:" << std::endl;
			teamDead.showList();
			std::cout << "\nteam red queue before adjustment is: " << std::endl;
			teamRed.showList();
			std::cout << std::endl;
			teamRed.removeFront();  
			std::cout << "team red queue after removing front is: " << std::endl;
			teamRed.showList();
			std::cout << "\nNow adding blue winner to back of current lineup" << std::endl;
			teamBlue.addBack(blue);   // add blue to end of queue because they won
			std::cout << std::endl;
			teamBlue.showList();
			std::cout << "\nNow removing blue winner from front of current lineup" << std::endl;
			teamBlue.removeFront();  // remove blue from front of queue
			std::cout << "team blue queue is now " << std::endl;
			teamBlue.showList();
			
			std::cout << "blue strength before healing: " << blue->strengthPoints << std::endl;
			// give blue winner some strengthpoints back
			blue->strengthPoints = blue->strengthPoints * 1.5;
			std::cout << "blue strength after healing: " << blue->strengthPoints << std::endl;
			//teamDefend.front = teamDefend.front->next;
			}
			
	      
			
		} while (red->strengthPoints > 0 && blue->strengthPoints > 0);

	}
	
	

}

