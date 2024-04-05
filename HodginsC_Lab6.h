#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Macros
#define TITLE_SIZE 40
#define AUTHOR_SIZE 30
#define PUBLISHER_SIZE 30
#define ISBN_SIZE 30
#define STAR '*' 
#define SCREEN_WIDTH 65
#define SCHOOL "Binghamton University"
#define PROGRAMMER "Charles Hodgins"
#define LAB "Lab 5"
#define ARRAYSIZE 50 
#define ROW_SIZE 10

// Constants

// Structures
typedef struct {
    // char bookTitle[TITLE_SIZE];
    // char bookAuthor[AUTHOR_SIZE];
    // char bookPublishingCompany[PUBLISHER_SIZE];
    // int yearPublished;
    // char isbn[ISBN_SIZE];
    // double costOfTheBook;
    char symbol
} recordType;
 
typedef struct node{ 
    recordType record;  
    struct node* pNext;
} nodeType;

typedef struct stack{   
    nodeType* pTop;
}stackType;

// Prototypes
void push(stackType** stack, nodeType* element);
void pop(stackType** stack);
void openDataFiles(FILE** inputFile, char* inputName, FILE** outputFile, char* outputName);
void closeDataFiles(FILE** inputFile, FILE** outputFile );

//Foos Function Prototypes
void PrintHeader(FILE* pOutput);
void PrintDivider(FILE* pOutput, char symbol, int numberOf);
void CenterString(FILE* pOutput, char string[], int lengthToCenterAcross);

#endif