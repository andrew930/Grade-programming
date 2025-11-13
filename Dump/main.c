#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "midterm.h"

int main(){
    char name[50];
    char ID[10];
    char choice[2];
    char status[8];
    char subjects[2][10] = {"MIDTERMS", "FINALS"};]

    float exam_grade = 0.0f;
    float participation = 0.0f;
    float perftask = 0.0f;
    float writtentask = 0.0f;
    float proj = 0.0f;
    float prob = 0.0f;
    float labpt = 0.0f;

    float final_grade = 0.0f;
    float lec_grade = 0.0f;
    float lab_grade = 0.0f;
//storing info into info.txt
    FILE *pF = fopen("info.txt", "a");
    printf("Enter name here: ");
        fgets(name, sizeof(name), stdin);
    printf("Enter here ID number: ");
        scanf("%s", ID);
    printf("Select subject calculation from the selection:");
    printf("\n1.) %s", subjects[0]);
    printf("\n2.) %s", subjects[1]);
    printf("\nChoose by number 1 or 2: ");
        scanf("%s", choice);
    printf("\nName: %sID: %s \nSubject: %s", name, ID, subjects);


    if(strcmp(choice, "1")==0){
        Grade results = midterm();
        final_grade = results.total_midterm_grade;
        lec_grade = results.total_lec_grade;
        lab_grade = results.total_lab_grade;
        
        exam_grade = results.midexam_grade;
        participation = results.parti_grade;
        perftask = results.pt_grade;
        writtentask = results.ww_grade;
        proj = results.proj_grade;
        prob = results.prob_grade;
        labpt = results.prob_grade;

        if (final_grade >= 75) {
            strcpy(status, "PASSED");
        } else {
            strcpy(status, "FAILED");
        }
    }
    fprintf(pF,"\nName: %sID: %s \nSubject: %s", name, ID, subjects); //might move this if mid and finals lec and lab are added.
    fprintf(pF,"\nMidterm Term (LEC) Results\n");
    fprintf(pF,"Midterm Examinations (30%): %.2f%%\n", exam_grade);
    fprintf(pF,"Class Participations (20%): %.2f%%\n", participation);
    fprintf(pF,"Performance Task (30%): %.2f%%\n", perftask);
    fprintf(pF,"Written Works (20%): %.2f%%\n", writtentask);
    fprintf(pF,"Midterm (LEC) Grade: %.2f%%\n", lec_grade);
    
    fprintf(pF,"\nMidterm Term (LAB) Results\n");
    fprintf(pF,"Midterm Project (30%): %.2f%%\n", writtentask);
    fprintf(pF,"Midterm Problems (30%): %.2f%%\n", prob);
    fprintf(pF,"Midterm Performance Task (40%): %.2f%%\n", labpt);
    fprintf(pF,"Midterm (LAB) Grade: %.2f%%\n", lab_grade);
    
    fprintf(pF,"\nMIDTERM GRADE\n");
    fprintf(pF,"Midterm Grade (MG) = %.2f%%\n", final_grade);
    fclose(pF);
    printf("\n ");
    system("pause");
    return 0;
}