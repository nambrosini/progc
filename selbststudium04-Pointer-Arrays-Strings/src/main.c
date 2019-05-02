#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int compare (const void * a, const void * b) {
    return strcmp (*(const char **) a, *(const char **) b);
}


int main(int argc, char* argv[])
{
    // read and sort
    char input[20];
    char wordlist[100][20];
    int counter = 0;
    while (true)
    {
        scanf("%s", input);

        if (strcmp(input, "ZZZ") == 0) {
            break;
        }

        strcpy(wordlist[counter], input);
        counter++;
    } ;

    int n_array = sizeof(wordlist) / sizeof(char*);

    int i;
    qsort (wordlist, n_array, sizeof (const char *), compare);
    for (i = 0; i < n_array; i++) {
        printf ("%d: %s.\n", i, wordlist[i]);
    }
    
    return EXIT_SUCCESS;
}
