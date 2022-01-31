/* CS2211a 2021 */
/* Assignment 05 */
/* Jai Sharma */
/* 251172876 */
/* jsharm45 */
/* 2021 12 01*/ 

#ifndef DEFINITIONS_H_INCLUDE
#define DEFINITIONS_H_INCLUDE

// All required preprocessor definitions.
#define PAGESPERMINUTE 1
#define MAXCYCLES 200
#define MAXPAGES 30
#define ITERATIONS 1000

#define DEBUG_LIST 1
#define DEBUG_ADDING 1
#define DEBUG_PRINT_PROCESS 1
#define DEBUG_SHOW_EXCEEDED 1
#define DEBUG_SHOW_CYCLES 1
#define DEBUG 0


// Structure that holds all the information pertaining to the different aspects of the document.
typedef struct document
{
    int document_number;
    int page_count;
    int priority_number;
    int cycle_number;
    bool bonus;
} DOCUMENT;

// Structure that holds all the information pertaining to the nodes.
typedef struct node
{
    // pointer to document structure
    void* dataPtr; 
    
    // must be a singly linked list
    struct node* next; 
} LIST_NODE;


// Structure that holds all the information pertaining to the list.
typedef struct list
{
    struct node* head;
    
    // Variable to keep track of the count of the nodes in the list.
    int count;
} LIST;

// The following are all the function prototypes used in the assignment.
void freeLinkedList(LIST* list);
void freeListNode(LIST_NODE* node);

bool printList(LIST* list);

void* generateDocumentPrintJob(int docID, int priority);

LIST* createList(void);
void insertListToHead(LIST* list, void* itemPtr);
void insertRequirements(LIST* list, void* itemPtr);


void* sendJobToPrinter(LIST* list);
void bonusSwapPrintJobPriority(LIST* list);
void updateCycles(LIST* list);

//DEFINITIONS_H_INCLUDE
#endif 
