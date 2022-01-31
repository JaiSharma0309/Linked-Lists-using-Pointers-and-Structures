/* CS2211a 2021 */
/* Assignment 05 */
/* Jai Sharma */
/* 251172876 */
/* jsharm45 */
/* 2021 12 01 */

// This line ensures the entire program links together correctly, since each file has been split into functions.
#include "headers.h"


// The main function is the central point of the program and will serve as the function that binds everything together.
int main()
{


    // Creating a pointer called jList to be used in the creation of the list.
    LIST* jList = createList();

    srand(time(NULL));
    
    // Following variables will be used to determine when the new print job request will be placed in the queue.
    int r1 = 0, r2 = 0, docID = 0, printingCycle = 0;
    DOCUMENT* printJob;
    DOCUMENT* printingJob = NULL;

    // Will iterate while the for loop counter is less than the number of max iterations.
    for (int i = 0; i < ITERATIONS; i++) {
        
        //Need to check if the jList is not empty
        if (printingJob != NULL && printingJob->page_count == 0) {
            if (jList->count != 0) {
                
                // Sending job to printer.
                printingJob = sendJobToPrinter(jList);
                printingCycle = printingJob->page_count + printingJob->cycle_number;
            }
            else
                printingJob = NULL;
        }

        // Generting random numbers.
        r1 = (rand() % 10) + 1;
        
        // if it hits 10, create a document, could have used any value, regardless 1/10 chance of occuring (10%).
        if (r1 == 10) {
            
            // Increment docID.
            docID++;
            
            // Genereates a random number for job priority
            r2 = (rand() % 10) + 1; 
            
            // The job is high priority
            if (r2 == 1) {
                printJob = generateDocumentPrintJob(docID, 1);
            }
            
              // The job is low priority
            else if (r2 == 2 || r2 == 3) {
                printJob = generateDocumentPrintJob(docID, 3);
            }
            
              // The job is average priority
            else {
                printJob = generateDocumentPrintJob(docID, 2);
            }

            insertRequirements(jList, printJob);
        } // End of document creation


        if (printingJob == NULL) {
            if (jList->count > 0) {
                printingJob = sendJobToPrinter(jList);
                
                // Tracking number of cycles this job took to complete.
                printingCycle = printingJob->page_count + printingJob->cycle_number;
            }
        }

        if (printingJob != NULL) {
            
            //Print page(s) per preproccessor PAGESPERMINUTE.
            printingJob->page_count = printingJob->page_count - PAGESPERMINUTE;
            if (DEBUG_PRINT_PROCESS == true)
                printf("PRINTING - DOCUMENT: %4d  PAGE: %4d  priority:  %3d\n", printingJob->document_number, printingJob->page_count, printingJob->priority_number);
        }

        // If printing job is not null and page count is not 0.
        if (printingJob != NULL && printingJob->page_count == 0) {


            if (DEBUG_PRINT_PROCESS == true)
                printf("Done Printing - document #: %3d\n", printingJob->document_number);
            // Finish the current job

            if (DEBUG == true)
                printf("Print Job Completed - Document Number : %3d   -   Cycle Count : %3d\n", printingJob->document_number, printingCycle);

            //reset cycle count for current print job report
            printingCycle = 0; 
        }

        if (DEBUG_LIST == true) {
            
            // Printing the list.
            printList(jList);
        }

        updateCycles(jList);
    }
    printf("\nEnd of Program - *JSHARM45*\n");
    printf("Number of printer jobs left in queue : %3d\n", jList->count);

    return 0;
}

