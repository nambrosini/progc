#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"

#include "statistics.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

static int setup(void)
{
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0; // success
}

static int teardown(void)
{
    // Do nothing.
    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
    return 0; // success
}


static void test_getMark(void)
{
    CU_ASSERT_EQUAL(getMark(100, 100), 6);
    CU_ASSERT_EQUAL(getMark(90, 100), 6);
    CU_ASSERT_EQUAL(getMark(89, 100), 5);
    CU_ASSERT_EQUAL(getMark(80, 100), 5);
    CU_ASSERT_EQUAL(getMark(60, 100), 4);
    CU_ASSERT_EQUAL(getMark(40, 100), 3);
    CU_ASSERT_EQUAL(getMark(20, 100), 2);
    CU_ASSERT_EQUAL(getMark(0, 100), 1);
}

static void test_getStatistics(void)
{
    unsigned int student_points[] = {
        0,
        20, 20,
        40, 40, 40,
        60, 60, 60, 60,
        80, 80, 80, 80, 80,
        100, 100, 100, 100, 100, 100
    };
    unsigned int num_students = sizeof(student_points)/sizeof(*student_points);



    statistics_t statistics = getStatistics(student_points, num_students, 100);

    CU_ASSERT_EQUAL(statistics.mark1, 1);
    CU_ASSERT_EQUAL(statistics.mark2, 2);
    CU_ASSERT_EQUAL(statistics.mark3, 3);
    CU_ASSERT_EQUAL(statistics.mark4, 4);
    CU_ASSERT_EQUAL(statistics.mark5, 5);
    CU_ASSERT_EQUAL(statistics.mark6, 6);
    CU_ASSERT_EQUAL(statistics.bestMark, 6);
    CU_ASSERT_EQUAL(statistics.worstMark, 1);
    CU_ASSERT_EQUAL(statistics.averageMark, 91.0 / (float) num_students);
    CU_ASSERT_EQUAL(statistics.greaterThan4, 6 + 5 + 4);
    CU_ASSERT_EQUAL(statistics.greaterThan4Percent, (6 + 5 + 4) / (float) num_students * 100);
}

int main(void)
{
    // setup, run, teardown
    TestMainBasic("Notenstatistik", setup, teardown
                  , test_getMark
                  , test_getStatistics
                  );
}
