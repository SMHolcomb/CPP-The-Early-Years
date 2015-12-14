/*************************************************************************************************
 ** Program Filename:	Item.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				October 22, 2015
 ** Description:		Class specification file for the Item class
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/

#ifndef _ITEM_
#define _ITEM_

#include <string>


class Item {

	public:
		
		std::string item_nm;
		std::string item_unit;
		int quantity;
		double unit_price;
		
	public:
	
		Item();  //constructor
		Item(std::string, std::string, int, double);
		
		
};



#endif
