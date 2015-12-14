/*************************************************************************************************
 ** Program Filename:	Queue.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 3, 2015
 ** Description:		Methods for Queue Class/QueueNode Struct
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#include "Queue.hpp"


/*************************************************************************************************
 ** Function:			Queue::Queue
 ** Description:		Default constructor for Queue object			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Queue::Queue() {

	head = NULL;
	tail = NULL;
}

/*************************************************************************************************
 ** Function:			Queue::~Queue
 ** Description:		Default deconstructor for Queue object			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

Queue::~Queue() {

	while(head!=NULL)
		{
			QueueNode *temp = head;
			head = head->next;
			delete temp;
		}
}

/*************************************************************************************************
 ** Function:			Queue::add
 ** Description:		Create a Node, set the value to the data part, and adjust pointers			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

void Queue::add(int number) {

	if(head == NULL) {
		head = new QueueNode(number, head);
		tail = head;
		
		}
	else {

		tail->next = new QueueNode(number);
		tail = tail->next;
	
		}

}

/*************************************************************************************************
 ** Function:			Queue::remove
 ** Description:		Remove first number from the Queue list
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void Queue::remove() {

	// if there's no queue found
	if (head == NULL) {
	
		std::cout << "\nThere is nothing in the queue to remove!" << std::endl;

		}
	
	else {
		// set a temp pointer to the head of the list, move the pointer, then delete head
		std::cout << "\n\nThe first item in your queue, " << head->number << ", will now be removed." << std::endl;
		QueueNode *temp;
		temp = head;
		head = head->next;
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
		//start at head of list, print the current node, move pointer to next, print etc.. 
		QueueNode *nodePtr = head;
		
		if (nodePtr == NULL) {
	
			std::cout << "There is no queue left to show!" << std::endl;
	
			}
		 else {
		std::cout << "\nHere is the current queue:\n" << std::endl;
			
		while (nodePtr) {
		
			std::cout << nodePtr->number << " ";
			nodePtr = nodePtr->next;
		 }
		 std::cout << std::endl;
		 
		}
 
		 
}