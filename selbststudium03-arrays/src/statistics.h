#ifndef _STATISTICS_H_
#define _STATISTICS_H_

typedef struct {
    // tbd
} statistics_t;

unsigned int getMark(unsigned int p, unsigned int p6);

statistics_t getStatistics(unsigned int student_points[],
                            size_t num_students,
                            unsigned int p6);
#endif // _STATISTICS_H_
