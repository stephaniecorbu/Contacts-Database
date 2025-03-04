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
#include "../include/givenA2.h"
#include <ctype.h>
void createContacts (char * fileName){

    struct contact empRecords;
    FILE *fptr;
    fptr =fopen (fileName, "a+");
    int id;
    char first [100];
    char last [100];
    char emailAddress [100];
    //go to the end of the file
    fseek(fptr, 0, SEEK_END);
    long currentPosition = ftell(fptr);
    char choice[4];
    int readFunction;

    do{
        printf("Do you wish to enter a new contact (Yes or No)?: ");
        scanf("%s",choice);
        if(strcmp(choice, "No")==0){
            break;
        }
        //this for loop changes the user choice string to all lowercase letters
        for(int i=0; i<strlen(choice); i++){
           choice[i]=tolower(choice[i]);
        }
        //if the input is yes then the function proceds
        if (strcmp(choice, "yes") ==0){
           //take user input
           do{
               printf("Employee Id: ");
               scanf("%d", &id);
           }while(id<1 || id>9999);

           do{
               readFunction=searchContacts(fileName, id);
               if(readFunction==1){
                   printf("ID taken by this user please enter new ID number\n");
                   do{
                       printf("Employee Id: ");
                       scanf("%d", &id);
                       }while(id<1 || id>9999);
               }
           }while(readFunction==1);

           getchar(); //removes newline
           printf("First name: ");
           fgets(first, 100, stdin);
           if (first[strlen(first) - 1] == '\n') {
               first[strlen(first) - 1] = '\0';  // Remove newline
           }

           printf("Last name: ");
           fgets(last, 100, stdin);
           if (last[strlen(last) - 1] == '\n') {
               last[strlen(last) - 1] = '\0';  // Remove newline
           }

           printf("Email: ");
           fgets(emailAddress, 100, stdin);
           if (emailAddress[strlen(emailAddress) - 1] == '\n') {
               emailAddress[strlen(emailAddress) - 1] = '\0';  // Remove newline
           }

           //dynamically allocate arrays
           char *firstName = malloc((strlen(first)+1) * sizeof(char));
           char *lastName = malloc( (strlen(last)+1)* sizeof(char));
           char *email = malloc((strlen(emailAddress)+1) * sizeof(char));

           //assign user input to arrays
           strcpy(firstName, first);
           strcpy(lastName, last);
           strcpy(email, emailAddress);

           //calculates position and stores the position in the struct
           empRecords.empIdPosn=currentPosition+sizeof(empRecords);
           empRecords.firstNamePosn=empRecords.empIdPosn + sizeof(int);
           empRecords.lastNamePosn=empRecords.firstNamePosn + strlen(firstName)+1;
           empRecords.emailPosn=empRecords.lastNamePosn + strlen(lastName)+1;
           empRecords.next=empRecords.emailPosn + strlen(email)+1;

           fwrite ( &empRecords, sizeof (empRecords), 1, fptr );
           fwrite(&id, sizeof(int), 1, fptr);  // Write employee ID
           fwrite(firstName, sizeof(char), strlen(firstName) + 1,fptr);  // Write first name string
           fwrite(lastName, sizeof(char), strlen(lastName) + 1, fptr);  // Write last name string
           fwrite(email, sizeof(char), strlen(email) + 1,fptr);  // Write email string

           // Frees memory
           free(firstName);
           free(lastName);
           free(email);

           // Close the file after writing the record
           fclose(fptr);
        }
    }while(strcmp(choice, "No") != 0);
}
