/*************************************************************************************************
 ** Program Filename:	Stack.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 3, 2015
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
 ** Description:		Add a number to the Stack list			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/


void Stack::add(int number) {


		head = new StackNode(number, head);

}

/*************************************************************************************************
 ** Function:			Stack::remove
 ** Description:		Remove top number from the Stack list			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Stack::remove() {
	
// return the data in the top node
// Remove the node
// Adjust the pointers
	if (head == NULL)
	{ std::cout << "\nThere is nothing in the stack to remove!" << std::endl;}

	else { std::cout << "\nThe top item in the stack, " << head->number << ", will now be removed!" << std::endl;

	 StackNode *nodePtr;
	 nodePtr = head;
	 head = head->next;
	 delete nodePtr;
	 
	}

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
	
	std::cout << "There is no stack left to show!" << std::endl;
	
	}
    else {
		std::cout << "\nHere is the current stack:\n" << std::endl;
	while (nodePtr) {
	
		//Print the number in the current node - vertically like a stack
		std::cout << nodePtr->number << std::endl;
		//Move on to the next node
		nodePtr = nodePtr->next;
	}
    }
}