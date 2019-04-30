#ifndef _STATISTICS_H_
#define _STATISTICS_H_

typedef struct {
    int mark6;
    int mark5;
    int mark4;
    int mark3;
    int mark2;
    int mark1;
    int bestMark;
    int worstMark;
    double averageMark;
    int greaterThan4;
    double greaterThan4Percent;
} statistics_t;

unsigned int getMark(unsigned int p, unsigned int p6);

statistics_t getStatistics(unsigned int student_points[],
                            size_t num_students,
                            unsigned int p6);
#endif // _STATISTICS_H_
