#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char name[50];
    char ID[50];
    char subject[50];

    FILE *pF = fopen("info.txt", "a");
    printf("Enter name here: ");
        fgets(name, sizeof(name), stdin);
    printf("Enter here ID number: ");
        scanf("%s", &ID);
    printf("Enter here subject: ");
        scanf("%s", &subject);
    printf("\nName: %sID: %s \nSubject: %s", name, ID, subject);

    float quiz, assignment, exam, total;
    if(strcmp(subject, "math")==0){
        printf("\nInput here quiz score: ");
            scanf("%f", &quiz);
        printf("Input here assignment score: ");
            scanf("%f", &assignment);
        printf("Input here exam score: ");
            scanf("%f", &exam); 
        //placeholder calculation

        total = quiz + assignment + exam;
        printf("Total scores: %.2f", total);
        fprintf(pF,"\nName: %sID: %s \nSubject: %s", name, ID, subject);
        fprintf(pF, "Total scores: %f", total);
        fclose(pF);
        return 0;
    }
}