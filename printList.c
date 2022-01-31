/* CS2211a 2021 */
/* Assignment 05 */
/* Jai Sharma */
/* 251172876 */
/* jsharm45 */
/* 2021 12 01 */

// This line ensures the entire program links together correctly, since each file has been split into functions.
#include "headers.h"

// Function that serves as all the syntax and techincal requirements to actually print the linked list.
bool printList(LIST* list) {

    // Creating pointer variable of type LIST that will be used to point to other nodes and set data items.
    LIST_NODE* node;
    
    // Setting the head.
    node = list->head;
    
    // If the node is null it is empty.
    if (node == NULL) {
        printf("EMPTY QUEUE - no print jobs currently in queue\n");
        return false;
    }

    printf("\n");
    // Printing out the curret size.
    printf("Current Printer Queue Size: %d\n", list->count);

    // Printing out the different aspects, document number, priority number, etc of the job.
    while (node != NULL) {
        printf("Current Printer Queue : DocNum:   %4d     NumofPages  %4d      PriorityLevel %3d      NumOfCycles   %4d\n",
            ((DOCUMENT*)(node->dataPtr))->document_number, ((DOCUMENT*)(node->dataPtr))->page_count,
            ((DOCUMENT*)(node->dataPtr))->priority_number, ((DOCUMENT*)(node->dataPtr))->cycle_number);
        node = node->next;
    }
    printf("END OF LIST\n\n");
    return true;
}

