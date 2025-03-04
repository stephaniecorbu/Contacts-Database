/*
Student Name: Stephanie Corbu
Student ID: 1317931
Due Date: March 3erd, 2025
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
   1) I have read and understood the policy on academic integrity.
   2) I have completed Moodle's module on academic integrity.
   3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/givenA2.h"

int main (int argc, char *argv[]){

    char userChoice[3];
    int readFunction;
    int employeeId;

    //call createContacts
    createContacts(argv[1]);


    do{
        printf("Enter a choice:\n");
        printf("1 to print, 2 to search, 3 to create more, -1 to exit: ");

        // Read the user choice
        scanf("%s", userChoice);

        if (strcmp (userChoice, "1") == 0) {
            readFunction = readContacts(argv[1]);
            if (readFunction == -1) {
                printf("File cannot be opened\n");
            }
        }
        else if (strcmp (userChoice, "2") == 0) {
            do{
                printf("Enter the Search for Id? ");
                scanf("%d", &employeeId);  // Read the employee ID
            }while(employeeId<1 || employeeId>9999);
            readFunction = searchContacts(argv[1], employeeId); //call searchContacts funtion
            if (readFunction == -1) {
                printf("File cannot be opened\n");
            }
            else if (readFunction ==0){
                printf("No match found\n");
            }
        }
        else if (strcmp (userChoice, "3") == 0) {
            createContacts(argv[1]);  // Call createContacts function
        }
        else if (strcmp (userChoice, "-1") == 0) {
            // If user chooses to exit, break the loop
            printf("Exiting the program.\n");
        }
    }while (strcmp (userChoice, "-1") != 0);
}
