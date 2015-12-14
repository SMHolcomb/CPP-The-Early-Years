/*************************************************************************************************
 ** Program Filename:	Stack.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 20, 2015
 ** Description:		Class specification file for the Stack class 
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/


#ifndef __Stack__
#define __Stack__

#include <iostream>
#include "Creature.hpp"

struct StackNode {  // StackNode structure
		
			Creature* creature;
			StackNode *next;
			StackNode(Creature* creature1, StackNode *next1 = 0) {
					creature = creature1;
					next = next1;
				}
};

class Stack {

		public:
	
		StackNode *head;  // list head point
	
		Stack();
		~Stack();
		void add(Creature* creature);
		void remove();
		void showList();
		
		//for Dev testing
		void showListDev();
		void addDev(Creature* creature);

};

#endif 