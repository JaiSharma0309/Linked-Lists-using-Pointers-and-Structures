/* CS2211a 2021 */
/* Assignment 05 */
/* Jai Sharma */
/* 251172876 */
/* jsharm45 */
/* 2021 12 01*/ 

// This line ensures the entire program links together correctly, since each file has been split into functions.
#include "headers.h"

//Function that frees all the memory pertaining to the linked list.
void freeLinkedList(LIST* list) {
    
    // Pointer variable.
    LIST_NODE* node;
    
    // While the list is not empty.
    while (list->head != NULL) {
        
        // Creating and assigning variable to free for.
        DOCUMENT* doc = list->head->dataPtr;
        free(doc);
        
        // Setting the head.
        node = list->head;
        list->head = list->head->next;
        free(node);
    }
}

// Freeing memory for the nodes.
void freeListNode(LIST_NODE* node) {
    free(node);
}

