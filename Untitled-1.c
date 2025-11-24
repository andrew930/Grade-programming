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

    float final_grade = 0.0f;
    char status[15];

    FILE *pF = fopen("info.txt", "a");
    printf("========================================================================================================================");
    printf("\nGrade Calculator for CCS");
    printf("\nEnter name here: ");
        fgets(name, sizeof(name), stdin);
    while(!valid){
        printf("\nEnter here id number (9 digits): ");
            scanf("%10s", ID);

        if(strlen(ID) !=9){
            printf("\nInvalid ID number! Must be exactly 9 digits");
        } else {
            valid = 1;
        }
    }
    printf("\nSelect subject calculation from the selection:");
    printf("\n1.) %s", subjects[0]);
    printf("\n2.) %s", subjects[1]);
    printf("\nChoose by number 1 or 2: ");
        scanf("%s", choice);
    printf("\nName: %s", name);
    printf("\nID: %s", ID);

    while(!valid){
        if(strcmp(choice, "1")!=0 && strcmp(choice, "2")!=0){
            printf("\nINVALID OPTION!");
        }
        else{
            valid = 1;
            if(strcmp(choice, "1")==0){
                printf("\nChoice: %s", subjects[0]);
            }
            else if(strcmp(choice, "2")==0){
                printf("\nChoice: %s", subjects[1]);
            } 
        }
    }
    
    while(!valid){
        if(strcmp(choice, "2")==0){
            printf("\nComing soon");
        }
        else{
            valid = 1;
            if(strcmp(choice, "1")==0){
            final_grade = midterm();

            if (final_grade >= 75) {
               strcpy(status, "PASSED");
            } else {
                  strcpy(status, "FAILED");
                }
            }
        }
    }
    fprintf(pF,"\nName: %sID: %s \nSubject: %s", name, ID, subjects);
    fprintf(pF, "\nTotal grade: %.2f%%", final_grade);
    fprintf(pF, "\nSTATUS: %s\n", status);
    fclose(pF);
    printf("\n ");
    system("pause");
}