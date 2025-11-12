#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char name[50];
    char ID[50];
    char subject[50];
//storing info into info.txt
    FILE *pF = fopen("info.txt", "a");
    printf("Enter name here: ");
        fgets(name, sizeof(name), stdin);
    printf("Enter here ID number: ");
        scanf("%s", ID);
    printf("Enter here subject: ");
        scanf("%s", subject);
    printf("\nName: %sID: %s \nSubject: %s", name, ID, subject);

    float quiz, assignment, exam, total;

    if(strcmp(subject, "math")==0){
        printf("\nInput here quiz score: ");
            scanf("%f", &quiz);
        printf("\nInput here assignment score: ");
            scanf("%f", &assignment);
        printf("\nInput here exam score: ");
            scanf("%f", &exam); 
        //placeholder calculation

        total = quiz + assignment + exam;
        printf("Total scores: %.2f", total);
    }
    fprintf(pF,"\nName: %sID: %s \nSubject: %s", name, ID, subject); //might move this if mid and finals lec and lab are added.
    fprintf(pF, "\nTotal scores: %f", total);
    fclose(pF);
    printf("\n ");
    system("pause");
    return 0;
}