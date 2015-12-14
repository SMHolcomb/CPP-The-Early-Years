/*************************************************************************************************
 ** Program Filename:	Queue.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 3, 2015
 ** Description:		Class specification file for the Queue class 
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/
 
#ifndef QUEUE__
#define QUEUE__

#include <iostream>

class Queue {

   protected:
   
		struct QueueNode {  //Quenode structure
		
			int number;
			QueueNode *next;
			QueueNode(int num, QueueNode *next = NULL) {
			
					number = num;
					next = next;
			}
		};
		
		QueueNode *head;  //list head pointer
		QueueNode *tail; // list tail pointer
		
	public:
	
		Queue();
		~Queue();
		void add(int);
		void remove();
		void showList();

		
};


#endif 
