#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "statistics.h"

unsigned int getMark(unsigned int p, unsigned int p6) {
    if (p < 0) {
        return -1;
    }
    float note = 1.0 + (5.0 * p) / (float) p6;

    if ((int) (note * 10) % 10 >= 5) {
        return ceil(note);
    }

    return floor(note);
}

statistics_t getStatistics(unsigned int student_points[],
                            size_t num_students,
                            unsigned int p6) {

    unsigned int refactored_student_points[num_students];
    int counter = 0;

    for (int i = 0; i < num_students; i++) {
        if (student_points[i] >= 0 && student_points[i] <= p6) {
            refactored_student_points[counter] = student_points[i];
            counter++;
        }
    }
    statistics_t statistics;
    
    statistics.averageMark = 0.0;
    statistics.worstMark = 0;
    statistics.bestMark = 0;
    statistics.mark1 = 0;
    statistics.mark2 = 0;
    statistics.mark3 = 0;
    statistics.mark4 = 0;
    statistics.mark5 = 0;
    statistics.mark6 = 0;
    statistics.greaterThan4 = 0;

    for (int i = 0; i < counter; i++) {
        int note = getMark(refactored_student_points[i], p6);

        switch (note)
        {
            case 6:
                statistics.mark6 += 1;
                break;
            case 5:
                statistics.mark5 += 1;
                break;
            case 4:
                statistics.mark4 += 1;
                break;
            case 3:
                statistics.mark3 += 1;
                break;
            case 2:
                statistics.mark2 += 1;
                break;
            case 1:
                statistics.mark1 += 1;
                break;
            default:
                break;
        }

        if (statistics.bestMark < note) {
            statistics.bestMark = note;
        }

        if (statistics.worstMark > note || statistics.worstMark == 0) {
            statistics.worstMark = note;
        }

        statistics.averageMark += note;

        if (note >= 4) {
            statistics.greaterThan4++;
        }
    }

    statistics.averageMark /= (double) counter;
    statistics.greaterThan4Percent = statistics.greaterThan4 / (double) counter * 100;
    
    return statistics;
}

void printStats(statistics_t stats, int num_students, int p6) {
    printf("--------------------------------------------------------\n\n");
    printf("Statistics (%d students, %d points needed for mark 6):\n", num_students, p6);
    printf("Mark 6: %d\n", stats.mark6);
    printf("Mark 5: %d\n", stats.mark5);
    printf("Mark 4: %d\n", stats.mark4);
    printf("Mark 3: %d\n", stats.mark3);
    printf("Mark 2: %d\n", stats.mark2);
    printf("Mark 1: %d\n", stats.mark1);
    printf("Best mark: %d\n", stats.bestMark);
    printf("Worst mark: %d\n", stats.worstMark);
    printf("Average mark: %.2f\n", stats.averageMark);
    printf("Mark >= 4: %d students (%.2f)\n", stats.greaterThan4, stats.greaterThan4Percent);
    printf("--------------------------------------------------------\n");
}

int main(int argc, char* argv[]) {
    printf("Statistics: \n");

    bool done = false;

    while(!done){
        printf("Input max points.");
        int p6 = 0;
        scanf("%d", &p6);

        printf("Input num students: ");
        int num_students = 0;
        scanf("%d", &num_students);
        
        int inputs = 0;
        unsigned int students_points[100];
        while(inputs < num_students){
            printf("Insert next student's points: ");
            unsigned int points = 0;
            if (!scanf("%d", &points) || points < 0) {
                printf("You have to input a positive integer.");
                continue;
            }
            
            students_points[inputs] = points;
            inputs++;
            printStats(getStatistics(students_points, inputs, p6), inputs, p6);
        }
        
        printf("Would you like to make a new statistic? [y/N]");
        char response;
        scanf("%s", &response);

        if (response == 'y' || response == 'Y') {
            continue;
        } else {
            done = true;
        }
    }
    
}
