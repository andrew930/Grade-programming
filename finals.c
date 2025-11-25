#include <stdio.h>
#include "gradelib.h"


float finals(FILE *pF) {
    float total_flec_grade = 0, total_flab_grade = 0, total_finterm_grade = 0, finexam_grade, fparti_grade, fpt_grade, fww_grade, fproj_grade, fprob_grade, flab_pt_grade;

    printf("\nFinal Term (LEC) Calculation\n");

    finexam_grade = calculate_finexam_grade();
    fparti_grade = calculate_fparti_grade();
    fpt_grade = calculate_fpt_grade();
    fww_grade = calculate_fww_grade();
    fproj_grade = calculate_fproj_grade();
    fprob_grade = calculate_fprob_grade();
    flab_pt_grade = calculate_flab_pt_grade();

    total_flec_grade = finexam_grade + fparti_grade + fpt_grade + fww_grade;
    total_flab_grade = fproj_grade + fprob_grade + flab_pt_grade;
    total_finterm_grade = (total_flec_grade*40)/100 + (total_flab_grade*60)/100;

    printf("\nFinal Term Term (LEC) Results\n");
    printf("Final Term Examinations (30%): %.2f%%\n", finexam_grade);
    printf("Class Participations (20%): %.2f%%\n", fparti_grade);
    printf("Performance Task (30%): %.2f%%\n", fpt_grade);
    printf("Written Works (20%): %.2f%%\n", fww_grade);
    printf("Final Term (LEC) Grade: %.2f%%\n", total_flec_grade);
    
    printf("\nFinal Term (LAB) Results\n");
    printf("Final Term Project (30%): %.2f%%\n", fproj_grade);
    printf("Final Term Problems (30%): %.2f%%\n", fprob_grade);
    printf("Final Term Performance Task (40%): %.2f%%\n", flab_pt_grade);
    printf("Final Term (LAB) Grade: %.2f%%\n", total_flab_grade);
    
    printf("\nFINAL TERM GRADE\n");
    printf("Final Term Grade (MG) = %.2f%%\n", total_finterm_grade);
    
    if (total_finterm_grade >= 75) {
        printf("\nPASSED\n");
    } 
    else { 
        printf("\nFAILED\n");
    }

    if(pF != NULL) {
    fprintf(pF, "\nFinal Term Term (LEC) Results\n");
    fprintf(pF, "Final Term Examinations (30%): %.2f%%\n", finexam_grade);
    fprintf(pF, "Class Participations (20%): %.2f%%\n", fparti_grade);
    fprintf(pF, "Performance Task (30%): %.2f%%\n", fpt_grade);
    fprintf(pF, "Written Works (20%): %.2f%%\n", fww_grade);
    fprintf(pF, "Final Term (LEC) Grade: %.2f%%\n", total_flec_grade);
    
    fprintf(pF, "\nFinal Term (LAB) Results\n");
    fprintf(pF, "Final Term Project (30%): %.2f%%\n", fproj_grade);
    fprintf(pF, "Final Term Problems (30%): %.2f%%\n", fprob_grade);
    fprintf(pF, "Final Term Performance Task (40%): %.2f%%\n", flab_pt_grade);
    fprintf(pF, "Final Term (LAB) Grade: %.2f%%\n", total_flab_grade);
    
    fprintf(pF, "\nFINAL TERM GRADE\n");
    fprintf(pF, "Final Term Grade (MG) = %.2f%%\n", total_finterm_grade);
    
    if (total_finterm_grade >= 75) {
        fprintf(pF, "\nStatus: PASSED\n");
        fprintf(pF, "=======================================================\n");
    } 
    else { 
        fprintf(pF, "\nStatus: FAILED\n");
        fprintf(pF, "=======================================================\n");
    }
    }
    
    return total_finterm_grade;
}

float calculate_finexam_grade() {
    float fin_score, fin_overall, fin_percentage, fin_result = 0;
     
    printf("\nFINAL TERM EXAMINATIONS CALCULATION\n");
    printf("Enter your final term exam score: ");
    scanf("%f", &fin_score);
    
    printf("Enter the overall items: ");
    scanf("%f", &fin_overall);
    
    if (fin_overall > 0) {
        fin_percentage = (fin_score/fin_overall)*100;
        fin_result = (fin_percentage*30)/100;
        printf("Final Term Exam Grade: %.2f%%\n", fin_result);
    }
    else {
        printf("ERROR in Final Term Examinations Calculation.\n");
    }
    
    return fin_result;
}

float calculate_fparti_grade() {
    float facad_days, fabsence, fparti_percentage, fparti_result = 0;
    
    printf("\nCLASS PARTICIPATIONS CALCULATION\n");
    printf("Academic days in total this midterm: ");
    scanf("%f", &facad_days);
    
    printf("Days you were absent: ");
    scanf("%f", &fabsence);
    
    if (facad_days > 0 && fabsence <= facad_days) {
        fparti_percentage = ((facad_days-fabsence)/facad_days)*100;
        fparti_result = (fparti_percentage*20)/100;
        printf("Class Participation Grade: %.2f%%\n", fparti_result);
    }
    else {
        printf("ERROR in Class Participations Calculation.\n");
    }
    
    return fparti_result;
}

float calculate_fpt_grade() {
    int fnum_pts, i;
    float fpt_score, foverall_pts, fpt_percentage, final_fptgrade = 0, total_fptscore = 0, total_foverallpts = 0;

    printf("\nPERFORMANCE TASK CALCULATION\n");
    printf("Enter the number of performance tasks: ");
    if (scanf("%d", &fnum_pts) != 1 || fnum_pts <= 0) {
        printf("Invalid input for the number of tasks.\n");
        return 0;
    }

    for (i = 1; i <= fnum_pts; i++) {
        printf("\nEnter details for Performance Task %d:\n", i);

        printf("Enter the score earned from the PT: ");
        scanf("%f", &fpt_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &foverall_pts);

        total_fptscore += fpt_score;
        total_foverallpts += foverall_pts;
    }

    if (total_foverallpts > 0) {
        fpt_percentage = (total_fptscore/total_foverallpts)*100;
        final_fptgrade = (fpt_percentage * 30)/100;
        printf("\nPerformance Task Grade: %.2f%%\n", final_fptgrade);
    } 
    else {
        printf("\nERROR in Performance Task Calculation.\n");
    }
    
    return final_fptgrade;
}

float calculate_fww_grade() {
    int fnum_wws, i;
    float fww_score, overall_fwws, fww_percentage, final_wwgrade = 0, total_fwwscore = 0, total_foverallwws = 0;

    printf("\nWRITTEN WORKS CALCULATION\n");
    printf("Enter the number of Written Works: ");
    if (scanf("%d", &fnum_wws) != 1 || fnum_wws <= 0) {
        printf("Invalid input for the number of works.\n");
        return 0;
    }

    for (i = 1; i <= fnum_wws; i++) {
        printf("\nEnter details for Written Work %d:\n", i);

        printf("Enter the score you got from the written work: ");
        scanf("%f", &fww_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &overall_fwws);

        total_fwwscore += fww_score;
        total_foverallwws += overall_fwws;
    }

    if (total_foverallwws > 0) {
        fww_percentage = (total_fwwscore/total_foverallwws)*100;
        final_wwgrade = (fww_percentage*20)/100;
        printf("\nWritten Works Grade: %.2f%%\n", final_wwgrade);
    } 
    else {
        printf("\nERROR in Written Works Calculation.\n");
    }
    
    return final_wwgrade;
}
//MIDTERM LAB

float calculate_fproj_grade() {
     int num_fproj, i;
    float fproj_score, overall_fprojs, fproj_percentage, final_fprojgrade = 0, total_fprojscore = 0, total_foverallprojs = 0;

    printf("\nFinal Term (LAB) Calculation\n");
    printf("\nMACHINE PROJECT CALCULATION\n");
    printf("Enter the number of Machine Project(Found in the Final Project Folder): ");
    if (scanf("%d", &num_fproj) != 1 || num_fproj <= 0) {
        printf("Invalid input for the number of projects.\n");
        return 0;
    }

    for (i = 1; i <= num_fproj; i++) {
        printf("\nEnter details for Machine Project %d:\n", i);

        printf("Enter the score you got from the Machine Project: ");
        scanf("%f", &fproj_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &overall_fprojs);

        total_fprojscore += fproj_score;
        total_foverallprojs += overall_fprojs;
    }

    if (total_foverallprojs > 0) {
        fproj_percentage = (total_fprojscore/total_foverallprojs)*100;
        final_fprojgrade = (fproj_percentage*30)/100;
        printf("\nMachine Project Grade: %.2f%%\n", final_fprojgrade);
    } 
    else {
        printf("\nERROR in the Machine Project Calculation.\n");
    }
    
    return final_fprojgrade;
    
}

float calculate_fprob_grade() {
     int fnum_prob, i;
    float fprob_score, overall_fprobs, fprob_percentage, final_fprobgrade = 0, total_fprobscore = 0, total_foverallprobs = 0;

    printf("\nMACHINE PROBLEMS CALCULATION\n");
    printf("Enter the number of Machine Problems: ");
    if (scanf("%d", &fnum_prob) != 1 || fnum_prob <= 0) {
        printf("Invalid input for the number of problems.\n");
        return 0;
    }

    for (i = 1; i <= fnum_prob; i++) {
        printf("\nEnter details for Machine Problems %d:\n", i);

        printf("Enter the score you got from the Machine Problems: ");
        scanf("%f", &fprob_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &overall_fprobs);

        total_fprobscore += fprob_score;
        total_foverallprobs += overall_fprobs;
    }

    if (total_foverallprobs > 0) {
        fprob_percentage = (total_fprobscore/total_foverallprobs)*100;
        final_fprobgrade = (fprob_percentage*30)/100;
        printf("\nMachine Problems Grade: %.2f%%\n", final_fprobgrade);
    } 
    else {
        printf("\nERROR in the Machine Problems Calculation.\n");
    }
    
    return final_fprobgrade;
    
}

float calculate_flab_pt_grade() {
    int num_flab_pts, i;
    float flab_pt_score, overall_flab_pts, flab_pt_percentage, final_flab_ptgrade = 0, total_flab_ptscore = 0, total_overall_flab_pts = 0;

    printf("\nPERFORMANCE TASK CALCULATION\n");
    printf("Enter the number of performance tasks: ");
    if (scanf("%d", &num_flab_pts) != 1 || num_flab_pts <= 0) {
        printf("Invalid input for the number of tasks.\n");
        return 0;
    }

    for (i = 1; i <= num_flab_pts; i++) {
        printf("\nEnter details for Performance Task %d:\n", i);

        printf("Enter the score earned from the PT: ");
        scanf("%f", &flab_pt_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &overall_flab_pts);

        total_flab_ptscore += flab_pt_score;
        total_overall_flab_pts += overall_flab_pts;
    }

    if (total_overall_flab_pts > 0) {
        flab_pt_percentage = (total_flab_ptscore/total_overall_flab_pts)*100;
        final_flab_ptgrade = (flab_pt_percentage * 40)/100;
        printf("\nPerformance Task Grade: %.2f%%\n", final_flab_ptgrade);
    } 
    else {
        printf("\nERROR in Performance Task Calculation.\n");
    }
    
    return final_flab_ptgrade;
}