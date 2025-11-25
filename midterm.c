// INITIAL CODING / NO STARTER / NO RECITATION / LAB UNCHECKED / NO ENDING
#include <stdio.h>
#include "gradelib.h"

float midterm(FILE *pF) {
    float total_lec_grade = 0, total_lab_grade = 0, total_midterm_grade = 0, midexam_grade, parti_grade, pt_grade, ww_grade, proj_grade, prob_grade, lab_pt_grade;

    printf("\nMidterm Term (LEC) Calculation\n");

    midexam_grade = calculate_midexam_grade();
    parti_grade = calculate_parti_grade();
    pt_grade = calculate_pt_grade();
    ww_grade = calculate_ww_grade();
    proj_grade = calculate_proj_grade();
    prob_grade = calculate_prob_grade();
    lab_pt_grade = calculate_lab_pt_grade();

    total_lec_grade = midexam_grade + parti_grade + pt_grade + ww_grade;
    total_lab_grade = proj_grade + prob_grade + lab_pt_grade;
    total_midterm_grade = (total_lec_grade*40)/100 + (total_lab_grade*60)/100;

    printf("\nMidterm Term (LEC) Results\n");
    printf("Midterm Examinations (30%): %.2f%%\n", midexam_grade);
    printf("Class Participations (20%): %.2f%%\n", parti_grade);
    printf("Performance Task (30%): %.2f%%\n", pt_grade);
    printf("Written Works (20%): %.2f%%\n", ww_grade);
    printf("Midterm (LEC) Grade: %.2f%%\n", total_lec_grade);
    
    printf("\nMidterm Term (LAB) Results\n");
    printf("Midterm Project (30%): %.2f%%\n", proj_grade);
    printf("Midterm Problems (30%): %.2f%%\n", prob_grade);
    printf("Midterm Performance Task (40%): %.2f%%\n", lab_pt_grade);
    printf("Midterm (LAB) Grade: %.2f%%\n", total_lab_grade);
    
    printf("\nMIDTERM GRADE\n");
    printf("Midterm Grade (MG) = %.2f%%\n", total_midterm_grade);
    
    if (total_midterm_grade >= 75) {
        printf("\nPASSED\n");
    } 
    else { 
        printf("\nFAILED\n");
    }

    if (pF != NULL) {
        fprintf(pF, "\nMidterm Term (LEC) Results\n");
        fprintf(pF, "Midterm Examinations (30%%): %.2f%%\n", midexam_grade);
        fprintf(pF, "Class Participations (20%%): %.2f%%\n", parti_grade);
        fprintf(pF, "Performance Task (30%%): %.2f%%\n", pt_grade);
        fprintf(pF, "Written Works (20%%): %.2f%%\n", ww_grade);
        fprintf(pF, "Midterm (LEC) Grade: %.2f%%\n", total_lec_grade);
        
        fprintf(pF, "\nMidterm Term (LAB) Results\n");
        fprintf(pF, "Midterm Project (30%%): %.2f%%\n", proj_grade);
        fprintf(pF, "Midterm Problems (30%%): %.2f%%\n", prob_grade);
        fprintf(pF, "Midterm Performance Task (40%%): %.2f%%\n", lab_pt_grade);
        fprintf(pF, "Midterm (LAB) Grade: %.2f%%\n", total_lab_grade);
        
        fprintf(pF, "\nMIDTERM GRADE\n");
        fprintf(pF, "Midterm Grade (MG) = %.2f%%\n", total_midterm_grade);
        
        if (total_midterm_grade >= 75) {
            fprintf(pF, "\nStatus: PASSED\n");
            fprintf(pF, "=======================================================\n");
        } else { 
            fprintf(pF, "\nStatus: FAILED\n");
            fprintf(pF, "=======================================================\n");
        }
    }
    
    return total_midterm_grade;
}

float calculate_midexam_grade() {
    float mid_score, mid_overall, mid_percentage, mid_result = 0;
     
    printf("\nMIDTERM EXAMINATIONS CALCULATION\n");
    printf("Enter your midterm exam score: ");
    scanf("%f", &mid_score);
    
    printf("Enter the overall items: ");
    scanf("%f", &mid_overall);
    
    if (mid_overall > 0) {
        mid_percentage = (mid_score/mid_overall)*100;
        mid_result = (mid_percentage*30)/100;
        printf("Midterm Exam Grade: %.2f%%\n", mid_result);
    }
    else {
        printf("ERROR in Midterm Examinations Calculation.\n");
    }
    
    return mid_result;
}

float calculate_parti_grade() {
    float acad_days, absence, parti_percentage, parti_result = 0;
    
    printf("\nCLASS PARTICIPATIONS CALCULATION\n");
    printf("Academic days in total this midterm: ");
    scanf("%f", &acad_days);
    
    printf("Days you were absent: ");
    scanf("%f", &absence);
    
    if (acad_days > 0 && absence <= acad_days) {
        parti_percentage = ((acad_days-absence)/acad_days)*100;
        parti_result = (parti_percentage*20)/100;
        printf("Class Participation Grade: %.2f%%\n", parti_result);
    }
    else {
        printf("ERROR in Class Participations Calculation.\n");
    }
    
    return parti_result;
}

float calculate_pt_grade() {
    int num_pts, i;
    float pt_score, overall_pts, pt_percentage, final_ptgrade = 0, total_ptscore = 0, total_overallpts = 0;

    printf("\nPERFORMANCE TASK CALCULATION\n");
    printf("Enter the number of performance tasks: ");
    if (scanf("%d", &num_pts) != 1 || num_pts <= 0) {
        printf("Invalid input for the number of tasks.\n");
        return 0;
    }

    for (i = 1; i <= num_pts; i++) {
        printf("\nEnter details for Performance Task %d:\n", i);

        printf("Enter the score earned from the PT: ");
        scanf("%f", &pt_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &overall_pts);

        total_ptscore += pt_score;
        total_overallpts += overall_pts;
    }

    if (total_overallpts > 0) {
        pt_percentage = (total_ptscore/total_overallpts)*100;
        final_ptgrade = (pt_percentage * 30)/100;
        printf("\nPerformance Task Grade: %.2f%%\n", final_ptgrade);
    } 
    else {
        printf("\nERROR in Performance Task Calculation.\n");
    }
    
    return final_ptgrade;
}

float calculate_ww_grade() {
    int num_wws, i;
    float ww_score, overall_wws, ww_percentage, final_wwgrade = 0, total_wwscore = 0, total_overallwws = 0;

    printf("\nWRITTEN WORKS CALCULATION\n");
    printf("Enter the number of Written Works: ");
    if (scanf("%d", &num_wws) != 1 || num_wws <= 0) {
        printf("Invalid input for the number of works.\n");
        return 0;
    }

    for (i = 1; i <= num_wws; i++) {
        printf("\nEnter details for Written Work %d:\n", i);

        printf("Enter the score you got from the written work: ");
        scanf("%f", &ww_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &overall_wws);

        total_wwscore += ww_score;
        total_overallwws += overall_wws;
    }

    if (total_overallwws > 0) {
        ww_percentage = (total_wwscore/total_overallwws)*100;
        final_wwgrade = (ww_percentage*20)/100;
        printf("\nWritten Works Grade: %.2f%%\n", final_wwgrade);
    } 
    else {
        printf("\nERROR in Written Works Calculation.\n");
    }
    
    return final_wwgrade;
}
//MIDTERM LAB

float calculate_proj_grade() {
     int num_proj, i;
    float proj_score, overall_projs, proj_percentage, final_projgrade = 0, total_projscore = 0, total_overallprojs = 0;

    printf("\nMidterm Term (LAB) Calculation\n");
    printf("\nMACHINE PROJECT CALCULATION\n");
    printf("Enter the number of Machine Project(Found in the Final Project Folder): ");
    if (scanf("%d", &num_proj) != 1 || num_proj <= 0) {
        printf("Invalid input for the number of projects.\n");
        return 0;
    }

    for (i = 1; i <= num_proj; i++) {
        printf("\nEnter details for Machine Project %d:\n", i);

        printf("Enter the score you got from the Machine Project: ");
        scanf("%f", &proj_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &overall_projs);

        total_projscore += proj_score;
        total_overallprojs += overall_projs;
    }

    if (total_overallprojs > 0) {
        proj_percentage = (total_projscore/total_overallprojs)*100;
        final_projgrade = (proj_percentage*30)/100;
        printf("\nMachine Project Grade: %.2f%%\n", final_projgrade);
    } 
    else {
        printf("\nERROR in the Machine Project Calculation.\n");
    }
    
    return final_projgrade;
    
}

float calculate_prob_grade() {
     int num_prob, i;
    float prob_score, overall_probs, prob_percentage, final_probgrade = 0, total_probscore = 0, total_overallprobs = 0;

    printf("\nMACHINE PROBLEMS CALCULATION\n");
    printf("Enter the number of Machine Problems: ");
    if (scanf("%d", &num_prob) != 1 || num_prob <= 0) {
        printf("Invalid input for the number of problems.\n");
        return 0;
    }

    for (i = 1; i <= num_prob; i++) {
        printf("\nEnter details for Machine Problems %d:\n", i);

        printf("Enter the score you got from the Machine Problems: ");
        scanf("%f", &prob_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &overall_probs);

        total_probscore += prob_score;
        total_overallprobs += overall_probs;
    }

    if (total_overallprobs > 0) {
        prob_percentage = (total_probscore/total_overallprobs)*100;
        final_probgrade = (prob_percentage*30)/100;
        printf("\nMachine Problems Grade: %.2f%%\n", final_probgrade);
    } 
    else {
        printf("\nERROR in the Machine Problems Calculation.\n");
    }
    
    return final_probgrade;
    
}

float calculate_lab_pt_grade() {
    int num_lab_pts, i;
    float lab_pt_score, overall_lab_pts, lab_pt_percentage, final_lab_ptgrade = 0, total_lab_ptscore = 0, total_overall_lab_pts = 0;

    printf("\nPERFORMANCE TASK CALCULATION\n");
    printf("Enter the number of performance tasks: ");
    if (scanf("%d", &num_lab_pts) != 1 || num_lab_pts <= 0) {
        printf("Invalid input for the number of tasks.\n");
        return 0;
    }

    for (i = 1; i <= num_lab_pts; i++) {
        printf("\nEnter details for Performance Task %d:\n", i);

        printf("Enter the score earned from the PT: ");
        scanf("%f", &lab_pt_score);
        
        printf("Enter the overall items: ");
        scanf("%f", &overall_lab_pts);

        total_lab_ptscore += lab_pt_score;
        total_overall_lab_pts += overall_lab_pts;
    }

    if (total_overall_lab_pts > 0) {
        lab_pt_percentage = (total_lab_ptscore/total_overall_lab_pts)*100;
        final_lab_ptgrade = (lab_pt_percentage * 40)/100;
        printf("\nPerformance Task Grade: %.2f%%\n", final_lab_ptgrade);
    } 
    else {
        printf("\nERROR in Performance Task Calculation.\n");
    }
    
    return final_lab_ptgrade;
}