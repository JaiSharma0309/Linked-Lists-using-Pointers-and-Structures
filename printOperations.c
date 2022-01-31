/* CS2211a 2021 */
/* Assignment 05 */
/* Jai Sharma */
/* 251172876 */
/* jsharm45 */
/* 2021 12 01 */

// This line ensures the entire program links together correctly, since each file has been split into functions.
#include "headers.h"


// Function that makes sure the job is sent to the pointer with the correct connections.
void* sendJobToPrinter(LIST* list) {
    LIST_NODE* node;
    
    // Setting the head.
    node = list->head;
    
    // Making the job be the data pointer.
    DOCUMENT* printJob = node->dataPtr;
    
    // Making the head the next node.
    list->head = node->next;
    
    //Decrementing count.
    (list->count)--;
    
    // Freeing memory.
    freeListNode(node);
    return printJob;
}

// Function that deals with the bonus, so it repositions a printer job if the cycle count has exceeded the specified number of maximum cycles.
void bonusSwapPrintJobPriority(LIST* list) {
    
    // Setting the node's head.
    LIST_NODE* node;
    node = list->head;
   
    // Accessing the previous node.
    LIST_NODE* previousNode = node;
    
    // Creating a boolean and initializing it with false.
    bool isFound = false;
    
    
    while (node != NULL) {
        
        // Looking through the nodes and checking it fits the bonus. 
        isFound = false;


        // Firstly identifying the new job that has priority zero.
        if (((DOCUMENT*)node->dataPtr)->priority_number == 0 && ((DOCUMENT*)node->dataPtr)->bonus != true && previousNode != node) {
            
            // Setting the next node in the list.
            LIST_NODE* nextNode = node->next;
            
            // So if it's the last node the linked list.
            if (nextNode == NULL) { 
                
                // Setting the next node to null.
                previousNode->next = NULL;
                
                // Decrementing count.
                (list->count)--;
                
                // Calling the insertRequirements functions because we are inserting over here.
                insertRequirements(list, (DOCUMENT*)node->dataPtr);
                return;
                
            }
            
            // So if it's not the last node in the list.
            if (nextNode != NULL) {
                
                // Setting the next node.
                previousNode->next = nextNode;
                
                // Decreming the count.
                (list->count)--;
                
                // Found a node that fits the description.
                ((DOCUMENT*)node->dataPtr)->bonus = true;
                
                // Calling insertRequirements function.
                insertRequirements(list, (void*)node->dataPtr);
                
                isFound = true;
                
                // Making the previous node the next node.
                previousNode = nextNode;
                node = nextNode->next;
            }

        }

        // If it doesn't fit the desciption we set the previous node to the current one.
        if (isFound == false) {
            previousNode = node;
            node = node->next;
        }
    }

}


// This function will ensure the number of cycles remains accurate throughout the program.
void updateCycles(LIST* list) {
    
    // Getting the head node.
    LIST_NODE* node;
    node = list->head;
    
    // If the node is not empty.
    if (node != NULL) {
        
        // Looping through all the nodes.
        while (node != NULL) {
         
            ((DOCUMENT*)node->dataPtr)->cycle_number = ((DOCUMENT*)node->dataPtr)->cycle_number + 1;
   
            // If the cycle number has reached max.
            if (((DOCUMENT*)node->dataPtr)->cycle_number == MAXCYCLES) {
                
                // Setting priority number to 0.
                ((DOCUMENT*)node->dataPtr)->priority_number = 0;
                
                // Calling the function above.
                bonusSwapPrintJobPriority(list);
                
                // Printing out the contents if the cycle has exceeded it's max.
                if (DEBUG_SHOW_EXCEEDED == true)
                    printf("EXCEEDED CYCLE COUNT - Document:    %3d    Pages : %4d    Priority : %2d    Cycle Count : %3d\n", ((DOCUMENT*)node->dataPtr)->document_number, ((DOCUMENT*)node->dataPtr)->page_count, ((DOCUMENT*)node->dataPtr)->priority_number, ((DOCUMENT*)node->dataPtr)->cycle_number);
            }


            if (DEBUG_SHOW_CYCLES == true)
                printf("Increment Cycle - Document:    %3d    Pages:  %4d    Priority: %2d    Cycle Count:   %3d\n", ((DOCUMENT*)node->dataPtr)->document_number, ((DOCUMENT*)node->dataPtr)->page_count, ((DOCUMENT*)node->dataPtr)->priority_number, ((DOCUMENT*)node->dataPtr)->cycle_number);
            node = node->next;
        }
    }
}


