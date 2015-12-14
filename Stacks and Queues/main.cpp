/*************************************************************************************************
 ** Program Filename:	Main.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 3, 2015
 ** Description:		Main implementation file for Stack and Queue Demonstration
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/
 
#include <iostream>
#include <string>
#include "Stack.hpp"
#include "Queue.hpp"

/*************************************************************************************************
 ** Function:			main
 ** Description:		contains the main user menu and all function calls for Stack and Queue demos
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int main()
{
	std::string strInput;
	//int size;
	int inputCount;
	int inputNum;
	int inputChoose;
	
	Stack stackList;
	Queue queueList;
	
	/* add menu instead */
	
		while (inputChoose != 7) {
		std::cout << "\nPlease choose one:\n" << std::endl;
		std::cout << "1. Add a number(s) to a Stack" << std::endl;
		std::cout << "2. Add a number(s) to a Queue" << std::endl;
		std::cout << "3. Remove the top number(s) from the Stack" << std::endl;
		std::cout << "4. Remove the first number(s) from the Queue" << std::endl;
		std::cout << "5. View the current Stack" << std::endl;
		std::cout << "6. View the current Queue" << std::endl;
		std::cout << "7. Quit" << std::endl;
		
		std::cin >> inputChoose;
		
		switch (inputChoose) {
		
			case 1:
				{
				
				 //std::cout << "You chose #1" << std::endl;
				 std::cout << "\nHow many integers do you want to add to the stack list?" << std::endl;
					std::cin >> inputCount;
	
					for(int i = 1; i <=inputCount;i++) {
						std::cout << "Enter an integer" << std::endl;
						std::cin >> inputNum;
						
						stackList.add(inputNum);
					
					}

				 stackList.showList();
				 
				 break;
				}
			case 2:
				{
				
				 //std::cout << "You chose #2" << std::endl;
				  std::cout << "\nHow many integers do you want to add to the queue list?" << std::endl;
					std::cin >> inputCount;
	
					for(int i = 1; i <=inputCount;i++) {
						std::cout << "Enter an integer" << std::endl;
						std::cin >> inputNum;
						
						//stackList.add(inputNum);
						queueList.add(inputNum);
					}
					
					queueList.showList();
				 

				 
				 break;
				}
			case 3:
				{
				
				 //std::cout << "You chose #3" << std::endl;
				  std::cout << "\nHow many integers do you want to remove from the stack list?" << std::endl;
					std::cin >> inputCount;
	
					for(int i = 1; i <=inputCount;i++) {
												
						stackList.remove();
					
					}

				 stackList.showList();

								 
				 break;
				}
			case 4:
				{
				
				 //std::cout << "You chose #4" << std::endl;
				 std::cout << "\nHow many integers do you want to remove from the queue list?" << std::endl;
					std::cin >> inputCount;
	
					for(int i = 1; i <=inputCount;i++) {
												
						queueList.remove();
					
					}

				 queueList.showList();

				 
				 
				 
				 break;
				}
			case 5:
				{
				
				 stackList.showList();
				 break;
				}
			
			case 6:
				{
				
				 queueList.showList();
				 break;
				}
			case 7:
				{
				
				 std::cout << "Good Bye!" << std::endl;
				 break;
				}

		} // end switch
	
	} // end while
	
	
	 /*// INITIAL TESTING - COMMENT OUT USER INPUT SECTION ABOVE
	
		stackList.add(12);
		stackList.add(1);
		stackList.add(8);
		stackList.add(7);
		stackList.add(6);
		stackList.add(7);
		stackList.add(9);
		
		queueList.add(12);
		queueList.add(1);
		queueList.add(8);
		queueList.add(7);
		queueList.add(6);
		queueList.add(7);
		queueList.add(9);
	*/
	
	/* -- Test no stack/queue values
	   -- comment out add function statements above, don't add anything to stack or queue and see what happens
	*/
	
	return 0;
}
