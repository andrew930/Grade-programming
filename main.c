#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "midterm.h"

int main(){
    char name[50];
    char ID[10];
    char choice[2];
    char subjects[2][10] = {"MIDTERMS", "FINALS"};

    float final_grade = 0.0f;
    char status[15];

    FILE *pF = fopen("info.txt", "a");
    printf("========================================================================================================================");
    printf("\nGrade Calculator for CCS");
    printf("\nEnter name here: ");
        fgets(name, sizeof(name), stdin);
    printf("\nEnter here ID number: ");
        scanf("%s", ID);
    printf("\nSelect subject calculation from the selection:");
    printf("\n1.) %s", subjects[0]);
    printf("\n2.) %s", subjects[1]);
    printf("\nChoose by number 1 or 2: ");
        scanf("%s", choice);
    printf("\nName: %sID: %s \nSubject: %s", name, ID, subjects);

    if(strcmp(choice, "1")==0){
        final_grade = midterm();

         if (final_grade >= 75) {
            strcpy(status, "PASSED");
        } else {
            strcpy(status, "FAILED");
        }
    }
    fprintf(pF,"\nName: %sID: %s \nSubject: %s", name, ID, subjects);
    fprintf(pF, "\nTotal grade: %.2f%%", final_grade);
    fprintf(pF, "\nSTATUS: %s\n", status);
    fclose(pF);
    printf("\n ");
    system("pause");
}