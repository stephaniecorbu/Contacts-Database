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

int searchContacts (char * fileName, int keyId){

    FILE *fptr;
    fptr =fopen (fileName, "rb");
    //if file is empty return -1
    if (fptr == NULL){
        return - 1;
    }
    //struct variable
    struct contact empRecords;
    //move to the end of the file
    fseek(fptr, 0, SEEK_END);
    //store this postion at in a variable
    long int endPosition=ftell(fptr);
    //move back to the begining of the file
    fseek(fptr, 0, SEEK_SET);
    long int currentPosition=0;

    int id;
    char * lastName;
    char * firstName;
    char * email;

    //this for loop works until the end of the file is reached
    while (currentPosition != endPosition) {
        fread(&empRecords,sizeof(empRecords),1,fptr);
        int firstNameSize;
        int lastNameSize;
        int emailSize;

        //find size of arrays
        lastNameSize = empRecords.emailPosn-empRecords.lastNamePosn;
        firstNameSize = empRecords.lastNamePosn-empRecords.firstNamePosn;
        emailSize = empRecords.next-empRecords.emailPosn;

        //dynamically allocate arrays based on previous size calulations
        lastName = malloc(sizeof(char)*lastNameSize);
        firstName = malloc(sizeof(char)*firstNameSize);
        email = malloc(sizeof(char)*emailSize);


       // Read Employee ID
       fseek(fptr, empRecords.empIdPosn, SEEK_SET);  // Move to position of empId
       fread(&id, sizeof(int), 1, fptr);  // Read employee ID
       //if id is equal to keyId then print user information
       if (id==keyId){
           fread(firstName, sizeof(char), firstNameSize, fptr);  // Read first name string
           fread(lastName, sizeof(char), lastNameSize, fptr);  // Read last name string
           fread(email, sizeof(char), emailSize, fptr);  // Read email string

           printf("\n************************************************************\n");
           printf("Employee ID: %d\n", id);
           printf("First Name: %s\n", firstName);
           printf("Last Name: %s\n", lastName);
           printf("Email: %s\n", email);
           printf("************************************************************\n");

           //free memory
           free(lastName);
           free(firstName);
           free(email);

           // close the file
           fclose(fptr);
           return 1;
       }
       //otherwise go to the next struct
       else{
           fseek(fptr, empRecords.next, SEEK_SET);
           currentPosition=ftell(fptr);
       }
    }
    return 0;
}
