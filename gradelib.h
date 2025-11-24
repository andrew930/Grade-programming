#ifndef GRADELIB_H
#define GRADELIB_H

//midterms

float calculate_midexam_grade();
float calculate_parti_grade();
float calculate_pt_grade();
float calculate_ww_grade();
float calculate_proj_grade();
float calculate_prob_grade();
float calculate_lab_pt_grade();
float midterm(FILE *pF);

//finals

float calculate_finexam_grade();
float calculate_fparti_grade();
float calculate_fpt_grade();
float calculate_fww_grade();
float calculate_fproj_grade();
float calculate_fprob_grade();
float calculate_flab_pt_grade();
float finals(FILE *pF);

#endif