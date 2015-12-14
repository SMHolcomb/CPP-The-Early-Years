/******************************************************************************
 ** Program Filename:	GameOfLife.cpp
 ** Author:				Stephanie Holcomb
 ** Date:				October 1, 2015
 ** Description:		GameOfLife.cpp Demonstrates Conway's Game of Life.  
 **							User is asked to choose from three sample patterns,
 **							provide a starting location, and specify the 
 **							number of generations. 
 ** Input:				None
 ** Output:				Prints to console
 ******************************************************************************/
 
#include <iostream>
#include <unistd.h>
#include <cstdlib>

int menuMain();
int getCol();
void generateOscillator(char array [40][80], int, int, char);
void generateGlider(char array [40][80], int, int, char);
void generateGun(char array [40][80], int, int, char);
bool validateInput(int, int, int);


/******************************************************************************
 ** Function:			main
 ** Description:		Prints menu to console, accepts user parameters, 
 **						 calls additional functions to calculate and 
 **						 generate oscillator, glider, and gun patterns. 
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ******************************************************************************/


int main() {

    // define array size (2x viewable area)
	const int ROWS = 40;
	const int COLUMNS = 80;
	
			
	int col = 0;
	int row = 0;
	int pattern;
	int generations = 1;
	int colOffset = 19;
	int rowOffset = 9;
	bool valid = false;
	char chrAlive = 'X';
	char chrDead = '-';
	char arrayWorld[ROWS][COLUMNS];
	char arrayWorldTemp[ROWS][COLUMNS];
	   

	do {
	  // clear screen and call print instructions/menu to console.
	  system("clear");
	  
	  pattern = menuMain();
	  std::cout << pattern;
	  
	   // if user choice != Quit
	  if (pattern!=4) {
          		  
		  std::cout << "\n\nNow you will get to choose the location and number" << std::endl;
		  std::cout << "of generations.  To best see the larger patterns, you will be limited" << std::endl;
		  std::cout << "to choosing a location in the upper left quadrant." << std::endl;
		  
		  // give user choice, but restrict col to max 20 for better visibility
		  std::cout << "\nEnter the column to start in (1 to 20): " << std::endl;
		  std::cin >> col;
		  
		  valid = validateInput(col,1,20);
		 		  
		  while (!valid){
					std::cout << "\nTry Again. Number must be between 1 and 20. : " << std::endl;
					std::cin >> col;
					valid = validateInput(col,1,20);
				}
	     
		  // give user choice, but restrict row to max 10 for better visibility
		  std::cout << "\nEnter the row to start in (1 to 10): " << std::endl;
		  std::cin >> row;
		  valid = validateInput(row,1,10);
		 		  
		  while (!valid){
					std::cout << "\nTry Again. Number must be between 1 and 10. : " << std::endl;
					std::cin >> row;
					valid = validateInput(row,1,10);
				}
		  
		  std::cout << "\nHow many generations do you want to see? (1 to 9999):" << std::endl;
		  std::cin >> generations;
		  valid = validateInput(generations, 1, 10000);
	
		  while (!valid) {
					std::cout << "\nTry Again. Number must be between 1 and 9999. : " << std::endl;
					std::cin >> generations;
					valid = validateInput(generations, 1, 10000);
				}
		}
		
	
	col = col+=colOffset;
	row = row+=rowOffset;

	// initialize all values in array to 'dead'
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			arrayWorld[i][j] = chrDead;
		}
	}

	switch (pattern) {
			
		case 1:
			generateOscillator(arrayWorld, row, col, chrAlive);
			break;
		case 2:
			generateGlider(arrayWorld, row, col, chrAlive);
			break;
		case 3:
			generateGun(arrayWorld, row, col, chrAlive);
			break;
		case 4:
			std::cout << "\nThanks for playing!" << std::endl;
			return 0;
		default:
			break;
	}

	// Print out all-dead world first
	for (int i = 10; i < 30; i++) {  
		for (int j = 20; j < 60; j++) {  
			std::cout << arrayWorld[i][j];
		}
		std::cout << std::endl;
	}


	//Generate iterations
	for (int genCount = 0; genCount < generations; genCount++) {

	
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				
				// do a neighbor count for each cell
				int neighbors = 0;
				
				if(arrayWorld[i-1][j-1] ==chrAlive)
					neighbors +=1;
				if(arrayWorld[i-1][j] ==chrAlive)
					neighbors +=1;
				if(arrayWorld[i-1][j+1] ==chrAlive)
					neighbors +=1;
				if(arrayWorld[i][j-1] ==chrAlive)
					neighbors +=1;
				if(arrayWorld[i][j+1] ==chrAlive)
					neighbors +=1;
				if(arrayWorld[i+1][j-1] ==chrAlive)
					neighbors +=1;
				if(arrayWorld[i+1][j] ==chrAlive)
					neighbors +=1;
				if(arrayWorld[i+1][j+1] ==chrAlive)
					neighbors +=1;
				
				
				if (neighbors < 2 || neighbors > 3) {
					arrayWorldTemp[i][j] = chrDead;
				}
				else if (neighbors == 3) {
					arrayWorldTemp[i][j]=chrAlive;
				}
				else {
					arrayWorldTemp[i][j] = arrayWorld[i][j];
				}
				
			}
		}
		
		// Copy temporary next generation array to current generation array
		for (int i = 0; i < ROWS; i++) {  // rows
			for (int j = 0; j < COLUMNS; j++) {  // columns
				arrayWorld[i][j] = arrayWorldTemp[i][j];
			}
		}
		
		//clear screen and print new generation
		system("clear");
		
		for (int i = 10; i < 30; i++) {
			for (int j = 20; j < 60; j++) {
				std::cout << arrayWorld[i][j];
			}
			std::cout << std::endl;
		}
		
		usleep(250000);
		
		
		}
	
	} while (pattern!=4);// end menu
 
  return 0;

}

/******************************************************************************
 ** Function:			menuMain
 ** Description:		generates initial menu and validates input, returns
 **							selectionto main
 ** Parameters:			None
 ** Pre-Conditions:		None
 ** Post-Conditions:	None
 ******************************************************************************/

int menuMain() {

	int inPattern = 0;
	bool valid = false;
 
	std::cout << "\nWelcome to Conway's Game of life!" << std::endl << std::endl;
	std::cout << "Please pick from one of the three patterns: " << std:: endl;
	std::cout << "	1. Fixed Oscillator" << std::endl;
	std::cout << "	2. Glider" << std::endl;
	std::cout << "	3. Glider Cannon" << std::endl;
	std::cout << "	4. Quit" << std::endl << std::endl;

	while (!valid) {
		std::cout << "Choose (1-4): ";
		std::cin >> inPattern;
	
	
		if(std::cin.fail()) {
			std::cout << "\nNumber must be between 1 and 4:" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			}
		else {
			valid = true;
			}

	}
		
   return inPattern;

}


/******************************************************************************
 ** Function:			validateInput
 ** Description:		validates user inputs for row, col, and generations to 
 **								ensure they are digits and between the min and
 **								max allowed 
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

/******************************************************************************
 ** Function:			generateOscillator
 ** Description:		Updates arrayWorld and sets initial life pattern for
 **								Oscillator based on user selections and row/col 
 **								parameters. 
 ** Parameters:			array arrayWorld, int row, int col, char chrAlive
 ** Pre-Conditions:		array exists and user inputs row, col exist
 ** Post-Conditions:	None
 ******************************************************************************/
 

void generateOscillator(char arrayWorld[40][80], int row, int col, char chrAlive) {
	
	arrayWorld[row][col] = chrAlive;
	arrayWorld[row][col-1] = chrAlive;
	arrayWorld[row][col+1] = chrAlive;

}

/******************************************************************************
 ** Function:			generateGlider
 ** Description:		Updates arrayWorld and sets initial life pattern for
 **								Glider based on user selections and row/col 
 **								parameters. 
 ** Parameters:			array arrayWorld, int row, int col, char chrAlive
 ** Pre-Conditions:		array exists and user inputs row, col exist
 ** Post-Conditions:	None
 ******************************************************************************/

void generateGlider(char arrayWorld[40][80], int row, int col, char chrAlive) {
	
	arrayWorld[row][col] = chrAlive;
	arrayWorld[row-1][col-1] = chrAlive;
	arrayWorld[row+1][col] = chrAlive;
	arrayWorld[row+1][col-1] = chrAlive;
	arrayWorld[row+1][col-2] = chrAlive;

}

/******************************************************************************
 ** Function:			generateGun
 ** Description:		Updates arrayWorld and sets initial life pattern for   
 **							Glider Gun based on user selections and row/col 
 **							parameters.
 ** Parameters:			array arrayWorld, int row, int col, char chrAlive
 ** Pre-Conditions:		array exists and user inputs row, col exist
 ** Post-Conditions:	None
 ******************************************************************************/


void generateGun(char arrayWorld[40][80], int row, int col, char chrAlive) {
	arrayWorld[row][col] = chrAlive;
	arrayWorld[row][col-1] = chrAlive;
	arrayWorld[row][col-3] = chrAlive;
	arrayWorld[row][col-7] = chrAlive;
	arrayWorld[row][col-16] = chrAlive;
	arrayWorld[row][col-17] = chrAlive;
	arrayWorld[row][col+5] = chrAlive;
	arrayWorld[row][col+7] = chrAlive;
	arrayWorld[row+1][col-1] = chrAlive;
	arrayWorld[row+1][col-7] = chrAlive;
	arrayWorld[row+1][col+7] = chrAlive;
	arrayWorld[row+2][col-2] = chrAlive;
	arrayWorld[row+2][col-6] = chrAlive;
	arrayWorld[row+3][col-4] = chrAlive;
	arrayWorld[row+3][col-5] = chrAlive;
	arrayWorld[row-1][col-1] = chrAlive;
	arrayWorld[row-1][col-7] = chrAlive;
	arrayWorld[row-1][col-16] = chrAlive;
	arrayWorld[row-1][col-17] = chrAlive;
	arrayWorld[row-1][col+3] = chrAlive;
	arrayWorld[row-1][col+4] = chrAlive;
	arrayWorld[row-2][col+3] = chrAlive;
	arrayWorld[row-2][col+4] = chrAlive;
	arrayWorld[row-2][col+17] = chrAlive;
	arrayWorld[row-2][col+18] = chrAlive;
	arrayWorld[row-2][col-2] = chrAlive;
	arrayWorld[row-2][col-6] = chrAlive;
	arrayWorld[row-3][col+17] = chrAlive;
	arrayWorld[row-3][col+18] = chrAlive;
	arrayWorld[row-3][col+3] = chrAlive;
	arrayWorld[row-3][col+4] = chrAlive;	
	arrayWorld[row-3][col-4] = chrAlive;
	arrayWorld[row-3][col-5] = chrAlive;
	arrayWorld[row-4][col+5] = chrAlive;
	arrayWorld[row-4][col+7] = chrAlive;
	arrayWorld[row-5][col+7] = chrAlive;

}

