#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "gradelib.h"

int is_numeric(const char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!isdigit(str[i])) {
        return 0;
        }
    }
    return 1;
}

int is_valid_name(const char *str) {
    if(strlen(str) == 0) return 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(!isalpha(str[i]) && str[i] != ' ' && str[i] != '.') {
            return 0;
        }
    }
    return 1;    
}

int main(){
    int continue_program = 1;

    while(continue_program){

    char name[50];
    char ID[11];
    char choice[2];
    char subjects[2][8] = {"Midterm", "Finals"};
    float midterm_grade = 0.0f;
    float finals_grade = 0.0f;
    printf("  _____   _____   _____ \n");
    printf(" / ____| / ____| / ____| \n");
    printf("| |     | |     | (___   \n");
    printf("| |     | |      \\___ \\  \n");
    printf("| |____ | |____  ____) | \n");
    printf(" \\_____| \\_____| |____/  \n");
    printf("*****************************************\n");
    printf("*     Grade Calculator for CCS          *\n");
    printf("*****************************************\n");

    for(;;) {
        printf("\nEnter name here: ");
        fgets(name, sizeof(name), stdin);
    
        if(strchr(name, '\n')== NULL) {
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }

        name[strcspn(name, "\n")] = '\0';

        if(strlen(name) == 0) {
            printf("\nName cannot be empty!\n");
        } else if(!is_valid_name(name)) {
            printf("\nInvalid name! Only letters and spaces are allowed!\n");
        } else {
            break;
        }
    }

    for(;;){
        printf("Enter here id number (9 digits): ");
        fgets(ID, sizeof(ID), stdin);
        
        if(strchr(ID, '\n')== NULL){
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }

        ID[strcspn(ID, "\n")] = '\0';

        if(strlen(ID) == 0){
            printf("\nID cannot be empty!\n");
        } else if(strlen(ID) != 9) {
            printf("\nInvalid ID number! Must be exactly 9 digits\n");
        } else if(!is_numeric(ID)) {
            printf("\nInvalid ID! Must only contain numbers.\n");
        } else {    
            break;
        }
    }

    printf("\nSelect subject calculation from the selection:\n");
    printf("\n1.) %s\n", subjects[0]);
    printf("\n2.) %s\n", subjects[1]);

    for(;;){
        printf("\nChoose by number 1 or 2: ");

        if(scanf("%1s", choice) != 1) {
            printf("Invalid input!\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');

        if(strcmp(choice, "1") == 0 || strcmp(choice, "2") == 0){
                break;
            } else {
                printf("Invalid choice! Please enter 1 or 2 only.\n");
            }
    }
    printf("\nName: %s\n", name);
    printf("ID: %s\n", ID);
    printf("Choice: %s\n", (strcmp(choice, "1") == 0) ? subjects[0] : subjects[1]);
    

    FILE *pF = fopen("info.txt", "a");
    if(pF == NULL){
        printf("ERROR: could not open the file!");
        pF = NULL;
        } else {
                fprintf(pF, "=======================================================\n");
                fprintf(pF, "Name: %s\nID: %s\nChoice: %s\n", 
                    name, ID, (strcmp(choice, "1") == 0) ? subjects[0] : subjects[1]);

        if(strcmp(choice, "1")==0){
            midterm_grade = midterm(pF);
        } else if(strcmp(choice, "2")==0){
            finals_grade = finals(pF);
        }

        fclose(pF);
    }
    
    printf("\n*******************************\n");
    printf("* What would you like to do?  *\n");
    printf("*******************************\n");
    printf("1. Enter another student's grade\n");
    printf("2. Exit the program\n");

    for(;;){
        printf("Choice: ");

        char next_choice[5];
        if(scanf("%s", next_choice) != 1) {
            while(getchar() != '\n');
            printf("Invalid input! Please enter 1 or 2.\n");
            continue;
        }
        while(getchar() != '\n');
        if(strcmp(next_choice, "1") == 0){
            printf("\n");
            break;
        } else if(strcmp(next_choice, "2") == 0){
            continue_program = 0;
            break;
        } else {
            printf("Invalid choice! Please enter 1 or 2.\n");
        }
        
    }   
    
    }

    return 0;    
}   