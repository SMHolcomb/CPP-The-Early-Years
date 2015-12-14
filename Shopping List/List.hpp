/*************************************************************************************************
 ** Program Filename:	List.hpp
 ** Author:				Stephanie Holcomb
 ** Date:				October 22, 2015
 ** Description:		Class specification file for the List class 
 ** Input:				None
 ** Output:				None
 ***************************************************************************************************/
 
#ifndef _LIST_
#define _LIST_

#include <iostream>
#include <vector>
#include <string>
#include "Item.hpp"

class List {

	private:
	
		std::vector<Item> shoppingList;
	
	public:
	
		List();  
		void itemAdd(Item);
		void itemDelete();
		std::vector<Item> getList();
		void displayList(List list);
		bool checkItemDuplicate(std::string item_name);
		void updateQuantity(std::string item_nm, int qty);

};

#endif
