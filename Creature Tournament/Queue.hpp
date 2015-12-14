/*************************************************************************************************
 ** Program Filename:	Stack.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 20, 2015
 ** Description:		Class specification file for the Queue class 
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/


#ifndef __Queue__
#define __Queue__

#include <iostream>
#include <string>
#include "Creature.hpp"

// QueueNode struct
struct QueueNode {

 
   Creature* creature;
   
   QueueNode *next;
   QueueNode(Creature* creature1, QueueNode *next1 = 0) {
					creature = creature1;
					next = next1;
				}
   
};


// Queue class
class Queue {

	public :
	  
	   QueueNode *front;
	   QueueNode *back;
	   
	   Queue();
	   ~Queue();
	   void addBack(Creature* creature); //add a creature object to the end of the queue 
	   void removeFront();
	   void showList();
	   void showListFinal(); // include strength points

		//for Dev and testing
	    void removeFrontDev();
};

#endif 