#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gradelib.h"

int main(){
    char name[50];

    char ID[11];
    int valid = 0;

    char choice[2];
    char subjects[2][8] = {"Midterm", "Finals"};   

    float midterm_grade = 0.0f;
    float finals_grade = 0.0f;
    char status[15];

    printf("========================================================================================================================");
    printf("\nGrade Calculator for CCS");
    printf("\nEnter name here: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
    while(!valid){
        printf("\nEnter here id number (9 digits): ");
            fgets(ID, sizeof(ID), stdin);
            ID[strcspn(ID, "\n")] = '\0';

        if(strlen(ID) !=9){
            printf("\nInvalid ID number! Must be exactly 9 digits");
            if(strchr(ID, '\n') == NULL){
                int c;
                while(( c = getchar()) != '\n' && c != EOF);
            }
        } else {
            valid = 1;
        }
    }
    printf("\nSelect subject calculation from the selection:");
    printf("\n1.) %s", subjects[0]);
    printf("\n2.) %s", subjects[1]);
    printf("\nChoose by number 1 or 2: ");
        scanf("%s", choice);
    printf("Name: %s\n", name);
    printf("\nID: %s", ID);


    if(strcmp(choice, "1")==0){
        printf("\nChoice: %s\n", subjects[0]);
    }
    else if(strcmp(choice, "2")==0){
        printf("\nChoice: %s\n", subjects[1]);
    }

    FILE *pF = fopen("info.txt", "a");
    if(pF == NULL){
        printf("ERROR: could not open the file!");
    } else {
        fprintf(pF, "\nName: %s\nID; %s \nChoice: %s", name, ID, subjects);
    }

    if(strcmp(choice, "1")==0){
        midterm_grade = midterm(pF);
    }
    
    if(strcmp(choice, "2")==0){
        finals_grade = finals(pF);
    }
    
    fclose(pF);
    printf("\n ");
    system("pause");
}
    