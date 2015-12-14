/*************************************************************************************************
 ** Program Filename:	main.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				October 22, 2015
 ** Description:		main implementation file for Assignment 2 - Shopping List 
 ** Input:				None
 ** Output:				console only
 ***************************************************************************************************/
 

#include <iostream>
#include <cstdlib>
#include <string>
#include "Item.hpp"
#include "List.hpp"

bool validateInput(int, int, int);
bool validateInput_doub(float,float,float);

/*************************************************************************************************
 ** Function:			main
 ** Description:		contains the main user menu and all function calls for ShoppingList program
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
int main()
{
	int input;
	std::string input_name;
	std::string input_unit;
	std::string input_delete;
	int input_quantity;
	float input_price;
	bool duplicate;
	bool valid = false;
	
	// create the Shopping List
	List sl1;
	
	std::cout << "Shoppping List" << std::endl << std::endl;
	
	do {
		std::cout << "Please Choose One: " << std::endl;
		std::cout << "1) Add an item to your list " << std::endl;
		std::cout << "2) Remove an item from your list " << std::endl;
		std::cout << "3) Review your list " << std::endl;
		std::cout << "4) Quit " << std::endl;
		std::cin >> input;
				
		valid = validateInput(input,1,4);
		 		  
		  while (!valid){
					std::cout << "\nTry Again. Number must be between 1 and 4. : " << std::endl;
					std::cin >> input;
					valid = validateInput(input,1,4);
				}
		
		
		switch(input) {
		
			case 1:
			
				std::cout << "Name of Item: " << std::endl;
				std::cin.ignore(1000, '\n'); 
				std::getline(std::cin,input_name);
				
				// check if item already exists (by name, assuming no duplicate names in this program)
				duplicate = sl1.checkItemDuplicate(input_name);
				
				if(duplicate==0) {
					   // item doesn't already exist, so get rest of input and add item to list
						std::cout << "Enter Unit (i.e. can, box, bag, or lb):" << std::endl;
						std::getline(std::cin,input_unit);
						
						std::cout << "How Many? " << std::endl;
						std::cin >> input_quantity;
						
						valid = validateInput(input_quantity,0,999);
		 		  
						while (!valid){
							std::cout << "\nTry Again. Number must be between 1 and 999. : " << std::endl;
							std::cin >> input_quantity;
							valid = validateInput(input_quantity,0,999);
						}
		
						std::cout << "Price of each:" << std::endl;
						std::cin >> input_price;
						
						valid = validateInput_doub(input_price,0.01,999.99);
						
						while (!valid){
							std::cout << "\nTry Again. Price must be between $0.01 and $999.99 : " << std::endl;
							std::cin >> input_price;
							valid = validateInput_doub(input_price,0.01,999.99);
						}
						
						
						sl1.itemAdd(Item(input_name, input_unit, input_quantity, input_price));
						}
					// item already exists, so get quantity and add to previous entry	
				 else { 
						std::cout << "How many do you want to add? " << std::endl;
						std::cin >> input_quantity;
						// update item quantity 
						for(int i = 0; i < sl1.getList().size();i++) {
							if(sl1.getList().at(i).item_nm == input_name) {
							std::cout << "Adding " << input_quantity << " to previous quantity." << std::endl;
					        sl1.updateQuantity(input_name,input_quantity);
							 
							}
					
				         }
				
				    } // end duplicate check
	
				break;
				
			case 2:
			
				// remove item function
				//std::cout << "Enter the name of the item to delete from the list " << std::endl;
				//std::cin.ignore(1000, '\n');
				//std::getline(std::cin,input_delete);
				//sl1.itemDelete(input_delete);
				sl1.itemDelete();
				
				break;
				
			case 3:
			
				// display list function
				sl1.displayList(sl1);
				
				break;
				
			case 4:
			
				std::cout << "Your list will now be deleted. Have a nice day!" << std::endl;
				
				break;
		
		} // end menu input switch
		
	
	} while (input < 4);
	
	
	return 0;
}


/******************************************************************************
 ** Function:			validateInput
 ** Description:		validates user inputs for to ensure they are digits and
 **						 between the min and max allowed 					
 ** Parameters:			user input, min and max allowed values
 ** Pre-Conditions:		user input exists
 ** Post-Conditions:	None
 ******************************************************************************/

bool validateInput(int input, int min, int max) {
	bool valid = false;

	if(input >=min && input <= max) {
		valid = true;
		}
	else {
		valid = false;
		}
	
	return valid;

}

// overloaded function to validate doubles (price)
bool validateInput_doub(float input, float min, float max) {
	bool valid = false;

	if(input >=min && input <= max) {
		valid = true;
		}
	else {
		valid = false;
		}
	
	return valid;

}
