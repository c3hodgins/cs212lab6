#include "HodginsC_Lab6.h"
//-----------------------------------------------------------------------------
// Function Name: void push(nodeType* pTop, nodeType* newElement)
// Description:
//   This function takes in the current linked list denoted by nodeType* pTop,
// and a new node to add to the linked list, and adds the new element to the 
// top of the list
//
//-----------------------------------------------------------------------------
void push(nodeType* pTop, nodeType* newElement){
    if (pTop == NULL){
        pTop = newElement;
        pTop->pNext = NULL;
    }else{
        newElement->pNext = pTop;
        pTop = newElement;
    }
}

//-----------------------------------------------------------------------------
// Function Name: void pop(nodeType* pTop)
// Description:
//   This function takes the input of the current linked list/stack and removes 
// the top element from the list
//
//-----------------------------------------------------------------------------
void pop(nodeType* pTop){
}
//FOOS FUNCTIONS
//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   This function will call the functions needed to print a header to the 
//  screen. 
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE* pOutput)
{
	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

	// Call functions to print three strings to center to the screen
	CenterString(pOutput, (char*)SCHOOL, SCREEN_WIDTH);
	CenterString(pOutput, (char*)PROGRAMMER, SCREEN_WIDTH);
	CenterString(pOutput, (char*)LAB, SCREEN_WIDTH);

	// Call function to print a divider to the screen
	PrintDivider(pOutput, STAR, SCREEN_WIDTH);

} // End PrintHeader

//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void PrintDivider(FILE* pOutput, char symbol, int numberOf)
{
	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print a bunch of symbols across the screen
	while (counter < numberOf)
	{
		// Print one character to the screen
		fprintf(pOutput, "%c", symbol);

		// Increment counter
		counter++;
	}

	// Move the cursor down to the next line
	fprintf(pOutput, "\n");

} // END PrintDivider

//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross)
{
	// Capture how long the string is
	// Cast to an integer because strlen technically returns size_t
	int stringLength = (int)strlen(string);

	// Calculate the width to print the string in
	int width = (lengthToCenterAcross + stringLength) / 2;

	// Calculate how many blank spaces are needed before printing the string
	int numberOfBlankSpaces = width - stringLength;

	// Initialize LCV (Loop Control Variable) to 0
	int counter = 0;

	// Print the spaces needed to center the string
	while (counter < numberOfBlankSpaces)
	{
		// Print one space
		fprintf(pOutput, " ");

		// Increment counter
		counter++;
	}

	// Print the string
	fprintf(pOutput, "%s\n", string);

} // END CenterString