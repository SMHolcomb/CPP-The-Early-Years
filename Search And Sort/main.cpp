/*************************************************************************************************
 ** Program Filename:	main.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				November 11, 2015
 ** Description:		main implementation file for Lab 7 - Search and Sort 
 ** Input:				[input] .txt file
 ** Output:				[output] .txt file
 ***************************************************************************************************/
 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>


void sort();
void linearSearch();
void binarySearch();
void compareSort();

/*************************************************************************************************
 ** Function:			main
 ** Description:		Contains main program flow and menus			 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ***************************************************************************************************/

int main()
{

  int choice;

  //user menu
  while (choice!=5) {
  
  std::cout << "\n\n-- Search and Sort Demonstrations -- " << std::endl;
  std::cout << "\nPlease choose an option: " << std::endl;
  std::cout << "1. Search for value 0 in a .txt file" << std::endl;
  std::cout << "2. Sort values in a .txt file" << std::endl;
  std::cout << "3. Conduct a binary search in a list of sorted values" << std::endl;
  std::cout << "4. Compare sort results of 4 pre-created files" << std::endl;
  std::cout << "5. Quit" << std::endl;
  
  std::cin >> choice;
  
  switch(choice) {
  
		case 1:
		
			linearSearch();
			break;
			
		case 2:
			
			sort();
			break;
			
		case 3:
			
			binarySearch();
			break;
			
		case 4:
		
			compareSort();
			break;
		
		case 5:
		
			std::cout << "Good-bye!" << std::endl;
			break;
		
		default:
			break;

		} 
  
	}

    return 0;
}


/*************************************************************************************************
 ** Function:			sort
 ** Description:		reads in file provided by user, sorts the integers, and outputs to a filename
 **						   provided by the user.
 ** Parameters:			None
 ** Pre-Conditions:		(assumes a .txt file exists and it is space or new-line delimited)
 ** Post-Conditions:	None
 ***************************************************************************************************/

void sort() {
	

	std::string sortFilename;
	std::string outfileSort;
	std::ifstream infile;
	std::ofstream outfile;
	std::vector <int> sortNums;
	int number;
	std::string file;
	int minimumIndex;
	int minimumValue;
	 
	 // user dialogue and accept in and out filenames
	 std::cout << "This option will read in a file of integers and write out a file containing the sorted values." << std::endl;
	 std::cout << "Enter a filename to read in (in format'[filename].txt')" << std::endl;
	 std::cout << "File should be space or new-line delimited only" << std::endl;
	 std::cout << "You may also use a default file: beginning.txt, middle.txt, end.txt, or nozero.txt" << std::endl;
	 std::cout << std::endl;
	 
	 std::cin >> file;
	 
		 /* // for testing
		 std::string file = "beginning.txt";
		 std::string file = "middle.txt";
		 std::string file = "end.txt";
		 std::string file = "nozero.txt";
		 outfile.open("sortedText.txt"); */
		
		
	 infile.open(file.c_str(),std::ios::in);
	 
	 std::cout << "Now, please enter a name to save the sorted file to [filename].txt\n" << std::endl;
	 
	 std::cin >> sortFilename;
	 outfile.open(sortFilename.c_str(), std::ios::out);

	// read in .txt file
	if(!infile) {
		std::cout << "Error: File not found or error opening file" << std::endl;
		}
		
	else {
	
		std::cout << "\nHere are the original numbers in " << file << ":" << std::endl;
		
		while (infile >> number) {
		
			std::cout << number << " " ;
			sortNums.push_back(number);
		
		}

		// start sort
		
		for(int i = 0; i < sortNums.size(); i++) {
			
			minimumIndex = i;
			minimumValue = sortNums[i];
		
			for (int index = i; index < sortNums.size() ; index++) {
			
				if(sortNums[index] < minimumValue) {
				
					minimumValue = sortNums[index];
					minimumIndex = index;
				}
		}
		
			sortNums[minimumIndex] = sortNums[i];
			sortNums[i] = minimumValue;
			
		}
		
			// write out to export file and print results to console for user
			std::cout << "\n\nHere are the sorted numbers that have been saved to " << sortFilename << "\n" << std::endl;
			
			for (int i = 0; i < sortNums.size(); i++) {
			
				outfile << sortNums[i] << " ";
				std::cout << sortNums[i] << " ";
				
			}
			
			std::cout << "\n\n" << std::endl;
			
			
		// close files
		infile.close();
		outfile.close();
		
	} 
	 
}

/*************************************************************************************************
 ** Function:			binarySearch
 ** Description:		reads in SORTED file provided by user, searches for user-defined integer,
 **						  prints position to console (or not found if not found). Prints message to user
 **						   if file doesn't appear to be pre-sorted and results may be suspect. 
 ** Parameters:			None
 ** Pre-Conditions:		(assumes a .txt file exists and it is space or new-line delimited)
 ** Post-Conditions:	None
 ***************************************************************************************************/

void binarySearch() {



	std::ifstream infile;
	std::vector <int> searchNums;
	int number;
	int searchVal;
	int position = -1;
	int begin = 0;
	int middle;
	int end;
	bool found = false;
	bool sort = true;
	std::string file;
	
	 
	 //user message and get user input
	 std::cout << "This function will search a pre-sorted file for a specific integer." << std::endl;
	 std::cout << "It will use a binary search method and return" << std::endl;
	 std::cout << "the first position where that integer is found" << std::endl;
	 std::cout << "Enter a PRE-SORTED filename in the format'[filename].txt'" << std::endl;
	 std::cout << "(You may also use the default file: sorted.txt" << std::endl;
	 std::cout << std::endl;
	 std::cin >> file;

	 std::cout << "\nEnter an integer between 0 and 9 to search for:" << std::endl;
	 std::cin >> searchVal;
	 
		 /* // for testing
		 //searchVal = 7;
		 input file is hardcoded since binary search requires that it be sorted
		 std::string file = "sorted.txt"; */
	 
	 
	infile.open(file.c_str(),std::ios::in);
	 
	//read in file
	if(!infile) {
	
		std::cout << "Error: File not found or error opening file" << std::endl;
		
		}
		
	else {
	
		std::cout << "\nHere are the contents of " << file << ":" << std::endl;
		
		while(infile >> number) {
		
			std::cout << number << " ";
			searchNums.push_back(number);  // write to vector
		}
		
		// start binary search here
		end = searchNums.size() - 1;
		middle = (begin + end) / 2;
		
		//while the number hasn't been found and we haven't reached the end of the search range
		while(!found && begin <=end) {
		
			middle = (begin + end) / 2;
		  
			 if(searchNums[middle] == searchVal) {
			 
				   found = true;
				   position = middle;  
			   
			 }
			
			 else if (searchNums[middle] > searchVal) {
				
					end = middle - 1;
				
			 }
			 
			 else {
			 
					begin = middle + 1;
			 }
			 
		}
		
	// print position (or not found) to user console
	if (position < 0) {
	
		std::cout << "\n\n" << searchVal << " was not found in " << file << "." << std::endl;
		
	  }
	  
	else {
	
	std::cout << "\n\nThe integer " << searchVal << " was first found at position: " << position + 1 << std::endl;
	
	}
		
		
	// test if the file was not sorted and let the user know that search results may not be accurate.
	
		for (int i = 1; i < searchNums.size(); i++) {
	
			if (searchNums[i] < searchNums[i-1]) {
			
				sort = false;
				
				}
					
		}
		
		if (sort == false) {
			std::cout << "fyi..the file you entered does not appear to have been a pre-sorted file and the search results may be incorrect.  Please try again" << std::endl;
		}
		
		
	}
	// close file
	infile.close();
}

/*************************************************************************************************
 ** Function:			linearSearch
 ** Description:		reads in file provided by user, searches for 0,
 **						  prints position to console (or not found if not found). 
 ** Parameters:			None
 ** Pre-Conditions:		(assumes a .txt file exists and it is space or new-line delimited)
 **						(assumes only one 0 exists - or it will return the last position found)
 ** Post-Conditions:	None
 ***************************************************************************************************/

void linearSearch() {

	std::ifstream infile;
	std::vector <int> searchNums;
	std::string file;
	int number;
	int position = 0;
	
	 std::cout << "This option will read in a file and search for the integer '0'" << std::endl;
	 std::cout << "Enter a filename in the format'[filename].txt'" << std::endl;
	 std::cout << "File should be space or new-line delimited only" << std::endl;
	 std::cout << "You may also use a default file: beginning.txt, middle.txt, end.txt, or nozero.txt" << std::endl;
	 std::cout << std::endl;
	 std::cin >> file;
	 
	 infile.open(file.c_str(),std::ios::in);
	 
	if(!infile) {
	
		std::cout << "Error: " << file << " not found or error opening " << file << std::endl;
	
		}
		
	else { 
	     
		int count = 0;
		std::cout << "\nHere are the integers in the file " << file << ":" << std::endl;
		// read in file
		while(infile >> number) {
	
			std::cout << number << " ";
			count=count+1;
		
			if(number == 0) {
				
				position = count;
				
			 }
		}
	
		//report back to user
		if(position>0) {
		
			std::cout << "\n\nZero was found at position " << position << std::endl << std::endl;
		}
	   
		else {
		
			std::cout << "\n\nZero was not found in " << file << std::endl << std::endl;
			
		}
	}
	// close file
	infile.close();
}


/*************************************************************************************************
 ** Function:			compareSort
 ** Description:		reads in four pre-created files: beginning.txt, middle.txt, end.txt,  
 **						  and nozero.txt.  Prints sorted results of all four to console for comparison
 **						  written as standalone function for testing (i.e. doesn't call sort function).   
 ** Parameters:			None
 ** Pre-Conditions:		(assumes four pre-created .txt files exist)
 ** Post-Conditions:	None
 ***************************************************************************************************/

void compareSort() {
	

	std::ifstream infile;
	int number;
	std::string file;
	int minimumIndex;
	int minimumValue;
	std::string fileArray[4] = {"beginning.txt","middle.txt","end.txt","nozero.txt"};
	 
	
	 std::cout << "This option will read in four pre-created files, sort them and print the results to the console for comparison." << std::endl << std::endl;
	
		for (int i = 0; i < 4; i++) {
		     std::vector <int> sortNums;
			//std::cout << fileArray[i] << std::endl;
			
			// read in file
			infile.open(fileArray[i].c_str(),std::ios::in);
			
			if(!infile) {
				std::cout << "Error: File not found or error opening file" << std::endl;
			}
		
			else {
	
				//std::cout << "\nHere are the original numbers in " << file << ":" << std::endl;
		
				while (infile >> number) {
			
					//std::cout << number << " " ;
					sortNums.push_back(number);
			
				}
			}
			
			// start sort
			for(int j = 0; j < sortNums.size(); j++) {
				
				minimumIndex = j;
				minimumValue = sortNums[j];
			
				for (int index = j; index < sortNums.size() ; index++) {
				
					if(sortNums[index] < minimumValue) {
					
						minimumValue = sortNums[index];
						minimumIndex = index;
					}
				}
			
				sortNums[minimumIndex] = sortNums[j];
				sortNums[j] = minimumValue;
				
				
				
				
			}
		   				
			std::cout << "\n" << std::endl;
			
			// print sorted results to console
			std::cout << "Sorted results for " << fileArray[i] << ":\n" << std::endl;
			
			for (int j = 0; j < sortNums.size(); j++) {
					
				std::cout << sortNums[j] << " ";
		
			}

		// close files
		infile.close();

		
	}  
	
	
	
	 
}




