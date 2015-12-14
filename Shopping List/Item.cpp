/*************************************************************************************************
 ** Program Filename:	Item.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				October 22, 2015
 ** Description:		Item.cpp Methods for Item class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/
 
#include "Item.hpp"
#include "List.hpp"

/*************************************************************************************************
 ** Function:			Item:Item
 ** Description:		Default constructor for Item object			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
Item::Item() {

	item_nm = "";
	item_unit = "";
	quantity = 0;
	unit_price = 0;

}

/*************************************************************************************************
 ** Function:			Item::Item(std::string, std::string, int, double)
 ** Description:		constructor for Item object from user input
 **						 
 ** Parameters:			item name, unit, qty, and price
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/
 
Item::Item(std::string name, std::string unit, int qty, double price) {

	 item_nm = name;
	 item_unit = unit;
	 quantity = qty;
	 unit_price = price;
 
}
