/* CS2211a 2021 */
/* Assignment 05 */
/* Jai Sharma */
/* 251172876 */
/* jsharm45 */
/* 2021 12 01*/ 

// This line ensures the entire program links together correctly, since each file has been split into functions.
#include "headers.h"

// Function that sets all the variables to the needed values so that the print jobs can be executed accurately.
void* generateDocumentPrintJob(int docID, int priority) {
    
    // Allocaintg memory for the printJob.
    DOCUMENT* printJob = (DOCUMENT*)malloc(sizeof(DOCUMENT));
    
    // Setting the document number.
    printJob->document_number = docID;
    
    // Setting the priority number.
    printJob->priority_number = priority;
    
    // Setting the page count to a random number.
    printJob->page_count = (rand() % MAXPAGES) + 1;
    
    // Setting cycles to 0.
    printJob->cycle_number = 0;
    
    // Setting the print job bonus to false.
    printJob->bonus = false;

    // If true the following the syntax will be executed.
    if (DEBUG_ADDING == true) {
        printf("\n");
        
        // Display's different elements of the print job being added to the queue.
        printf("Adding to Queue - Doc: % d NoPages : % 2d Priority : % d", docID, printJob->page_count, priority);
        printf("\n");
    }
    
    return printJob;
}

