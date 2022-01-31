/* CS2211a 2021 */
/* Assignment 05 */
/* Jai Sharma */
/* 251172876 */
/* jsharm45 */
/* 2021 12 01*/ 

// This line ensures the entire program links together correctly, since each file has been split into functions.
#include "headers.h"

// Function that will allocate memory to a singe linked list and create it with a head and count.
LIST* createList(void) {

    // Creating pointer variable of type LIST that will be used to allocate memory.
    LIST* list;
    
    // Allocating memoory
    list = (LIST*)malloc(sizeof(LIST));
    if (list) {
        
        // Setting the head to null and the count to 0 to initialize the list.
        list->head = NULL;
        list->count = 0;
    }
    return list;
}


// Function that inserts a node to the head of the list, which is required in several conditions.
void insertListToHead(LIST* list, void* itemPtr) {

    // Creating pointer variable of type LIST that will be used to point to other nodes and set data items.
    LIST_NODE* newPtr;
    
    // Allocating memory.
    newPtr = (LIST_NODE*)malloc(sizeof(LIST_NODE));

    newPtr->dataPtr = itemPtr;
    newPtr->next = list->head;
    
    // Incrementing count of the list.
    (list->count)++;
    
    // Making the head be the new node sent in.
    list->head = newPtr;

}

// Helper method that calls the function above if the count of the list is 0.
void insertRequirements(LIST* list, void* itemPtr) {
    if (list->count == 0) {
        insertListToHead(list, itemPtr);
        return;
    }


    //Now with a  linked list that has atleast 1 node, we need to determine where this 2nd node will go, either to the head or to the tail.  Will compare the priority number first.
    if (list->count == 1) {
        
        // Having a variable for the head of the list.
        LIST_NODE* tempHead = list->head;
        
        // Getting the priority of the head.
        int priorityOfHead = ((DOCUMENT*)(tempHead->dataPtr))->priority_number;
        
        // Getting the page count of the head.
        int pagesOfHead = ((DOCUMENT*)(tempHead->dataPtr))->page_count;
       
       // If the priority number is smaller than the priority number of the head it will go first.
        if (((DOCUMENT*)(itemPtr))->priority_number < priorityOfHead) {
            
            //Inserting to the head
            insertListToHead(list, itemPtr);
            return;
        }
        
        // Else if the priority numbers are the same but the page count is less than that of the head node.
        else if ((((DOCUMENT*)(itemPtr))->priority_number == priorityOfHead) && (((DOCUMENT*)(itemPtr))->page_count < pagesOfHead)) {
           
            // Inserting to the head since it's less.
            insertListToHead(list, itemPtr);
            return;
            
        }
        
        // Else in this case we consider that the linkedlist has only 1 node, this new node will be inserted right after the head and this node basically becomes the rear of the linked list.
        else {
            
            // Creating pointer variable of type LIST that will be used to point to other nodes and set data items.
            LIST_NODE* newPtr;
            
            // Allocating memory.
            newPtr = (LIST_NODE*)malloc(sizeof(LIST_NODE));
            
            // Setting data.
            newPtr->dataPtr = itemPtr;
            
            // Setting the next node to null.
            newPtr->next = NULL;
            
            // Setting the next of the head node to the new pointer.
            ((LIST_NODE*)(list->head))->next = newPtr;
            
            // Incrementing the count.
            (list->count)++;
            return;
        }
    }



    // Variable to access the head.
    LIST_NODE* node;
    node = list->head;
    
    // Accounting for another condition.  If the priority number is less or the priority number's are the same but he page count is less we will insert to the head.
    if (((DOCUMENT*)(itemPtr))->priority_number < ((DOCUMENT*)(node->dataPtr))->priority_number ||
        (((DOCUMENT*)(itemPtr))->priority_number == ((DOCUMENT*)(node->dataPtr))->priority_number &&
            ((DOCUMENT*)(itemPtr))->page_count < ((DOCUMENT*)(node->dataPtr))->page_count)) {
                
        // Will insert to the head.
        insertListToHead(list, itemPtr);
        return;
    }

    
    // Variable for the tail node.
    LIST_NODE* tailNode = node;
    
    // Will iterate through the entire linked list.
    while (node != NULL) {
        
        // If the priority number is less.
        if (((DOCUMENT*)(itemPtr))->priority_number < ((DOCUMENT*)(node->dataPtr))->priority_number) {
           
            // Creating pointer variable of type LIST that will be used to point to other nodes and set data items.
            LIST_NODE* newPtr;
            
            // Allocating memory.
            newPtr = (LIST_NODE*)malloc(sizeof(LIST_NODE));
            
            // Setting data.
            newPtr->dataPtr = itemPtr;
            
            //The predecessor in this case is the variable node and the successor is the variable tail.
            tailNode->next = newPtr;
            newPtr->next = node;
            (list->count)++;
            return;
        }

        // If the priority numbers equal.
        if (((DOCUMENT*)(itemPtr))->priority_number == ((DOCUMENT*)(node->dataPtr))->priority_number) {
            
            // If the page count is less.
            if (((DOCUMENT*)(itemPtr))->page_count < ((DOCUMENT*)(node->dataPtr))->page_count) {
                
                 //Creating pointer variable of type LIST that will be used to point to other nodes and set data items.
                LIST_NODE* newPtr;
                
                // Allocating memory.
                newPtr = (LIST_NODE*)malloc(sizeof(LIST_NODE));
                
                newPtr->dataPtr = itemPtr;
                // your predecessor in this case is variable node
                 tailNode->next = newPtr;
                newPtr->next = node;

                //Incrementing count.
                (list->count)++;
                return;
            }
        }

        // Setting the tail and next.
        tailNode = node;
        node = node->next;
    }

     // Creating pointer variable of type LIST that will be used to point to other nodes and set data items.
    LIST_NODE* newPtr;
    
    // Allocating memory.
    newPtr = (LIST_NODE*)malloc(sizeof(LIST_NODE));
    
    // Fixing connections.
    newPtr->dataPtr = itemPtr;
    newPtr->next = NULL;
    tailNode->next = newPtr;
    
    // Incrementing count.
    (list->count)++;


}

