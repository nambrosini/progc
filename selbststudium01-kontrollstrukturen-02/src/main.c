/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments
 *                  with argv[0] being the command call
 *                  argv[1] the 1st argument, ...
 *                  argv[argc-1] the last argument.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if more than one argument is given.
 */

/*
ASCII: 
- 9: TAB
- 10: New Line
- 32 : Space
*/
int main(int argc, char* argv[])
{
    char c = getchar();

    int charCounter = 0, wordCounter = 0;
    bool wasChar = false;

    while (c != 10) {
        charCounter++;
        if (c != 32 && c != 9) {
            wasChar = true;
        } else if (wasChar) {
            wordCounter++;
            wasChar = false;
        }

        c = getchar();
    }

    if (wasChar) {
        wordCounter++;
    }

    printf("words: %d, characters: %d\n", wordCounter, charCounter);
    return EXIT_SUCCESS;
}
