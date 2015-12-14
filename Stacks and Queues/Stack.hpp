/*************************************************************************************************
 ** Program Filename:	Stack.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 3, 2015
 ** Description:		Class specification file for the Stack class 
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#ifndef STACK__
#define STACK__

#include <iostream>

class Stack {

   protected:
   
		struct StackNode {  // StackNode structure
		
			int number;
			StackNode *next;
			StackNode(int number1, StackNode *next1 = 0) {
					number = number1;
					next = next1;
				}
		};
		
		StackNode *head;  // list head pointer
		
	public:
	
		Stack();
		~Stack();
		void add(int);
		void remove();
		void showList();

};


#endif 
