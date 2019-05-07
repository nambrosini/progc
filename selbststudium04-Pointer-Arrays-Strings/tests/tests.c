#include "CUnit/Basic.h"
#include "test_utils.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

#define INFILE_IN_ORDER "stim-in-order.input"
#define INFILE_OUT_OF_ORDER "stim-out-of-order.input"
#define INFILE_DOUBLE_ENTRIES "stim-double-entries.input"
#define INFILE_EMPTY "stim-empty-list.input"

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

static void test_in_order(void)
{
    // arrange
    const char *out_txt[] = {
        "\n",
        "Sortierte Liste:\n",
        "Otto\n",
        "Paula\n",
        "Quelle\n",
        "Richard\n",
        "Samuela\n",
        "Schule\n",
        "Theodor\n",
        "Ulrich\n",
        "Viktor\n",
        "Wilhelm\n",
        "Xanthippe\n",
        "Ypsilon\n",
        "Zachariasa\n",
        "anton\n",
        "berta\n",
        "caesar\n",
        "charlotte\n",
        "dora\n",
        "emil\n",
        "friedrich\n",
        "gustav\n",
        "heinrich\n",
        "ida\n",
        "julius\n",
        "kaufmann\n",
        "ludwig\n",
        "martha\n",
        "nordpol\n",
    };
    // act
    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_IN_ORDER);
    // assert
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt) / sizeof(*out_txt));
}

static void test_out_of_order(void)
{
    // arrange
    const char *out_txt[] = {
        "\n",
        "Sortierte Liste:\n",
        "Otto\n",
        "Paula\n",
        "Quelle\n",
        "Richard\n",
        "Samuela\n",
        "Schule\n",
        "Theodor\n",
        "Ulrich\n",
        "Viktor\n",
        "Wilhelm\n",
        "Xanthippe\n",
        "Ypsilon\n",
        "Zachariasa\n",
        "anton\n",
        "berta\n",
        "caesar\n",
        "charlotte\n",
        "dora\n",
        "emil\n",
        "friedrich\n",
        "gustav\n",
        "heinrich\n",
        "ida\n",
        "julius\n",
        "kaufmann\n",
        "ludwig\n",
        "martha\n",
        "nordpol\n",
    };
    // act
    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_OUT_OF_ORDER);
    // assert
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_double_entries(void)
{
    // arrange
    const char *out_txt[] = {
        "\n",
        "Sortierte Liste:\n",
        "anton\n",
        "berta\n",
        "caesar\n",
        "charlotte\n",
        "dora\n",
        "emil\n",
    };
    // act
    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_DOUBLE_ENTRIES);
    // assert
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

static void test_empty() {
    const char * out_txt[] = {
        "\n",
        "The list is empty.\n"
    };

    int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_EMPTY);
    // assert
    CU_ASSERT_EQUAL(exit_code, 0);
    assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

int main(void)
{
    // setup, run, teardown
    TestMainBasic("Sort words", setup, teardown
                  , test_in_order
                  , test_out_of_order
                  , test_double_entries
                  , test_empty
                  );
}
