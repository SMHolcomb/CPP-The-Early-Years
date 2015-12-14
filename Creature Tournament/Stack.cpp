/*************************************************************************************************
 ** Program Filename:	Stack.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 20, 2015
 ** Description:		Methods for Stack Class/StackNode Struct
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/
 
#include "Stack.hpp"


/*************************************************************************************************
 ** Function:			Stack::Stack
 ** Description:		Default constructor for Stack object			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Stack::Stack() {

	head = NULL;

}

/*************************************************************************************************
 ** Function:			Stack::~Stack
 ** Description:		Default deconstructor for Stack object			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
Stack::~Stack() {

	while(head!=NULL)
    {
		StackNode *temp = head;
        head = head->next;
        delete temp;
    }
}



/*************************************************************************************************
 ** Function:			Stack::add
 ** Description:		Add a creature to the Stack (Dead pile)			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/


void Stack::add(Creature* creature) {
    
		head = new StackNode(creature, head);
		//std::cout <<  "\nAdded " << head->creature->name << " to the dead pile\n" << std::endl;
		head->creature->alive_flag = 0;


}


/*************************************************************************************************
 ** Function:			Stack::showList
 ** Description:		Print the current Stack list to the console	 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Stack::showList() {
    
	StackNode *nodePtr = head;  // start at head of list
	if (nodePtr == NULL) {
	
	std::cout << "\nThere is no stack left to show!" << std::endl;
	
	}
    else {
		std::cout << "\n****************************" << std::endl; 
		std::cout << "Currently in the Dead Stack:" << std::endl;
		std::cout << "****************************\n" << std::endl;

	while (nodePtr) {
	
		//Print the number in the current node - vertically like a stack
		std::cout << nodePtr->creature->type << " " << nodePtr->creature->name << std::endl;
		//Move on to the next node
		nodePtr = nodePtr->next;
	}
		std::cout << std::endl;
		
    }
}


/*************************************************************************************************
 ** Function:			Stack::showListDev
 ** Description:		Print the current Stack list to the console	 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Stack::showListDev() {
    
	StackNode *nodePtr = head;  // start at head of list
	if (nodePtr == NULL) {
	
	std::cout << "\nThere is no stack left to show!" << std::endl;
	
	}
    else {
		std::cout << "\n****************************" << std::endl; 
		std::cout << "Currently in the Dead Stack:" << std::endl;
		std::cout << "****************************\n" << std::endl;

	while (nodePtr) {
	
		//Print the number in the current node - vertically like a stack
		std::cout << nodePtr->creature->type << " " << nodePtr->creature->name << std::endl;
		//Move on to the next node
		nodePtr = nodePtr->next;
	}
		std::cout << std::endl;
		
    }
}

/*************************************************************************************************
 ** Function:			Stack::addDev
 ** Description:		Add a creature to the Stack (Dead pile)			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/


void Stack::addDev(Creature* creature) {
    
		head = new StackNode(creature, head);
		std::cout <<  "\nAdded " << head->creature->name << " to the dead pile\n" << std::endl;
		head->creature->alive_flag = 0;
	
}



