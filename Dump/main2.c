#include <stdio.h>
#include <string.h>

int main() {
    char choice[50];
    printf("Choose between the two:\n");
    printf("1.) Midterm exam score calc\n");
    printf("2.) Midterm grade calc\n");
    printf("Enter number of the choice: ");
    scanf("%s", &choice);

    int i;
    float mid_score, mid_overall, mid_percentage, mid_result;
    float scores, overalls, total=0; 
    if(strcmp(choice, "1")==0){
    printf("Enter your midterm score: ");
    scanf("%f", &mid_score);
    
    printf("Enter the overall items: ");
    scanf("%f", &mid_overall);
    
    if (mid_overall>0) {
        mid_percentage = (mid_score / mid_overall)*100;
        mid_result = (mid_percentage*30)/100;
        printf("Your Midterm Exam Percentage is: %.2f%%\n", mid_result);
    }
    else {
        printf("ERROR\n");
    }
    for (i = 1; i <= 5; i++);
    printf("Enter your scores %d: ", i);
    scanf("%f", &scores);
    
    printf("Enter all the overall items: ");
    scanf("%f", &overalls);
    
    printf("%f", &scores);
}
    
    return 0;
}
