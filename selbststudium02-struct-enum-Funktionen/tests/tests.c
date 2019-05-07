#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"

#include "datehandling.h"

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

static void test_intput_on_cmd_line(void)
{
    const char *out_txt[] = {"The next date is:  3  2 2000\n"};

    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " < stim.input");
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));

}

static void test_next_date(void)
{
    Date dates[] = { {1, 1, 1583},
                     {2, 1, 1583},

                     {29, 2, 2016},
                     { 1, 3, 2016},

                     {28, 2, 1900},
                     { 1, 3, 1900},

                     {29, 2, 4000},
                     { 1, 3, 4000},

                     {31, 12, 2016},
                     { 1,  1, 2017}
    };
    int num_dates = sizeof(dates) / sizeof(*dates);

    printf("\n");
    for (int i=0; i<num_dates; i+=2) {
        Date next_date = calculate_next_date(dates[i]);
        printf("%2d %2d %4d -> %2d %2d %4d\n",
               dates[i].day, dates[i].month, dates[i].year,
               next_date.day, next_date.month, next_date.year);

        CU_ASSERT_EQUAL(dates[i+1].day, next_date.day);
        CU_ASSERT_EQUAL(dates[i+1].month, next_date.month);
        CU_ASSERT_EQUAL(dates[i+1].year, next_date.year);
    }
}

static void test_weird_dates(void)
{
    Date dates[] = { {-1, 1, 1583},
                     {-1, -1, -1},

                     {0, 0, 0},
                     {-1, -1, -1},

                     {29, 2, 1900},
                     {-1, -1, -1},

                     {29, 13, 4000},
                     {-1, -1, -1},

                     {32, 12, 2016},
                     {-1, -1, -1}
    };
    int num_dates = sizeof(dates) / sizeof(*dates);

    printf("\n");
    for (int i=0; i<num_dates; i+=2) {
        Date next_date = calculate_next_date(dates[i]);
        printf("%2d %2d %4d -> %2d %2d %4d\n",
               dates[i].day, dates[i].month, dates[i].year,
               next_date.day, next_date.month, next_date.year);

        CU_ASSERT_EQUAL(dates[i+1].day, next_date.day);
        CU_ASSERT_EQUAL(dates[i+1].month, next_date.month);
        CU_ASSERT_EQUAL(dates[i+1].year, next_date.year);
    }
}

int main(void)
{
    // setup, run, teardown
    TestMainBasic("Calculate next date", setup, teardown
                  , test_intput_on_cmd_line
                  , test_next_date
                  , test_weird_dates
                  );
}
