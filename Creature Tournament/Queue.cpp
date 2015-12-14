/*************************************************************************************************
 ** Program Filename:	Queue.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 20, 2015
 ** Description:		Methods for Queue Class/QueueNode Struct
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#include <iostream>
#include "Queue.hpp"

/*************************************************************************************************
 ** Function:			Queue::Queue
 ** Description:		constructor for Queue class			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
Queue::Queue() {

	front = back = NULL;
	
}


/*************************************************************************************************
 ** Function:			Queue::~Queue
 ** Description:		Deconstructor for Queue class			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Queue::~Queue() {


}


/*************************************************************************************************
 ** Function:			Queue::addBack
 ** Description:		adds a new Node to the Queue, sets data value, and adjusts all pointers			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

void Queue::addBack(Creature* creature) {


if(front == NULL) {
		front = new QueueNode(creature, front);
		back = front;
		
		}
	else {

		back->next = new QueueNode(creature);
		back = back->next;
	
		}

}

/*************************************************************************************************
 ** Function:			Queue::removeFront
 ** Description:		Removes front QueueNode
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 

void Queue::removeFront() {

    if (front==NULL) {

		//std::cout << "The queue is empty. There is nothing to delete." << std::endl;
   }
   
	else {
   	
		//std::cout <<  "\nRemoving " << front->creature->name << " from the front of queue.\n" << std::endl;
	  
		QueueNode *temp = front;	
		front = front->next;		
		delete temp;				  
	
		}
}

/*************************************************************************************************
 ** Function:			Queue::showList
 ** Description:		Print the current Queue list to the console	 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Queue::showList() {
    
	QueueNode *nodePtr = front;  
	if (nodePtr == NULL) {
	std::cout << "****************************" << std::endl; 
	std::cout << "Here is the current lineup:" << std::endl;
	std::cout << "****************************" << std::endl;
	std::cout << "There is noone in the lineup!\n" << std::endl;
	
	}
    else {
		std::cout << "****************************" << std::endl; 
		std::cout << "Here is the current lineup:" << std::endl;
		std::cout << "****************************" << std::endl;

	while (nodePtr) {
	
	
		std::cout << nodePtr->creature->type << " " << nodePtr->creature->name << std::endl;
		
		nodePtr = nodePtr->next;
	}
    }
}

/*************************************************************************************************
 ** Function:			Queue::showListFinal
 ** Description:		Print the current Queue list to the console	 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Queue::showListFinal() {
    
	QueueNode *nodePtr = front;  
	if (nodePtr == NULL) {
	std::cout << "****************************" << std::endl; 
	std::cout << "Here is the final lineup:" << std::endl;
	std::cout << "****************************" << std::endl;
	std::cout << "There is noone left in the lineup!\n" << std::endl;
	
	}
    else {
		std::cout << "*************************************" << std::endl; 
		std::cout << "Here is the final lineup with points:" << std::endl;
		std::cout << "*************************************" << std::endl;

	while (nodePtr) {
	
		
		std::cout << nodePtr->creature->type << " " << nodePtr->creature->name << " : " << nodePtr->creature->strengthPoints << " points\n" << std::endl;

		
		nodePtr = nodePtr->next;
	}
    }
}

/*************************************************************************************************
 ** Function:			Queue::removeFrontDev
 ** Description:		Removes front QueueNode
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 

void Queue::removeFrontDev() {

    if (front==NULL) {

		//std::cout << "The queue is empty. There is nothing to delete." << std::endl;
   }
   
	else {
   	
		std::cout <<  "\nRemoving " << front->creature->name << " from the front of queue.\n" << std::endl;
	  
		QueueNode *temp = front;	
		front = front->next;		
		delete temp;				  
	
		if(front==NULL) {
				// don't do anything
			}
		else{
			std::cout <<  "New front is now " << front->creature->name << "\n" << std::endl;
		}
     }
}


