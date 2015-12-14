/*************************************************************************************************
 ** Program Filename:	List.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				October 22, 2015
 ** Description:		List.cpp Methods for List class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#include <vector>
#include <iomanip>
#include "List.hpp"


/*************************************************************************************************
 ** Function:			List::List
 ** Description:		Default constructor for List object
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
List::List() {

  
}

/*************************************************************************************************
 ** Function:			List::checkItemDuplicate(std::string)
 ** Description:		Checks if item already exists on list. Returns bool value to main.
 **						 
 ** Parameters:			item_name
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

bool List::checkItemDuplicate(std::string item_name) {
  
   for(int i = 0; i < shoppingList.size();i++) {
   
		if(shoppingList.at(i).item_nm == item_name) {

			std::cout << "Item already exists. Quantity will be added to previous entry." << std::endl;
			return true;

		}

		else {

			return false;
	  
		}
	}
}

/*************************************************************************************************
 ** Function:			List::itemAdd(Item)
 ** Description:		Adds item to ShoppingList vector
 **						 
 ** Parameters:			Item object
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void List::itemAdd(Item item) {
	
	shoppingList.push_back(item);
	std::cout << "\nAdded " << item.item_nm << " (" << item.quantity << ")\n" << std::endl;
 
}

/*************************************************************************************************
 ** Function:			List::getList()
 ** Description:		returns ShoppingList
 **						 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
std::vector<Item> List::getList() {

	return shoppingList;

}

/*************************************************************************************************
 ** Function:			List::displayList(List)
 ** Description:		Displays current Shopping List
 **						 
 ** Parameters:			List object
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
void List::displayList(List list) {
	double item_total = 0;
	int total_items = 0;
	int total_quantity = 0;
	double total_price = 0;
	
	std::cout << "\n" << std::setw(10) << std::left << "Item" << std::setw(9) << "Unit" << std::setw(5) << "Qty" << std::setw(6) << "Price" << std::setw(6) << "Total" << std::endl;
	
	for (int i = 0 ; i < list.getList().size(); i++) {
	   
	  std::cout << std::setw(10) << std::left << list.getList().at(i).item_nm << std::setw(9) << list.getList().at(i).item_unit << std::setw(5) << list.getList().at(i).quantity << std::setw(6) << list.getList().at(i).unit_price;
	  item_total = ((list.getList().at(i).unit_price) * (list.getList().at(i).quantity));
	  std::cout << std::setw(1) << "$" << std::fixed << std::setprecision(2) << item_total << std::endl;
	  total_items += 1;
	  total_quantity += list.getList().at(i).quantity;
	  total_price += item_total;
	
	}
	std::cout << "------------------------------------" << std::endl;
	
	std::cout << std::setw(19) << std::left << total_items << std::setw(11) << total_quantity << std::setw(1) << "$" << std::fixed << std::setprecision(2) << total_price << std::endl << std::endl;
	

}

/*************************************************************************************************
 ** Function:			List::itemDelete()
 ** Description:		Checks to see if there are any items on the list. If not, tells
 **							user nothing to delete. Else asks user for item name and then
 **							deletes that item from the Shopping List
 **						 
 ** Parameters:			item_nm
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 

void List::itemDelete() {

	std::string input_delete;
	
	if(shoppingList.size() < 1) {
		std::cout << "You don't appear to have any items to delete yet.\n" << std::endl;
	 }
	 
	 else {
		std::cout << "Enter the name of the item to delete from the list " << std::endl;
		std::cin.ignore(1000, '\n');
		std::getline(std::cin,input_delete);
	 }
	 
	for(int i = 0; i < shoppingList.size(); i++) {
		if(shoppingList.at(i).item_nm == input_delete) {
			shoppingList.erase(shoppingList.begin()+i);
			std::cout << "\n" << input_delete << " has been removed.\n" << std::endl;
		}
		else {
			std::cout << "That item was not found. Please try again.\n" << std::endl;
		}	
 
	}
   
}

/*************************************************************************************************
 ** Function:			List::updateQuantity(std::string, int)
 ** Description:		Updates ShoppingList quantity for an item if it's added again
 **						 
 ** Parameters:			item_nm, qty
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

void List::updateQuantity(std::string item_nm, int qty) {

	for(int i = 0; i < shoppingList.size(); i++) {
		if(shoppingList.at(i).item_nm == item_nm) {
			shoppingList.at(i).quantity += qty;
			std::cout << "New Quantity: " << shoppingList.at(i).quantity << std::endl << std::endl;
		}

	}
}
