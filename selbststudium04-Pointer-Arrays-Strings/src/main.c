#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    // read and sort
    char word[20];
    char * wordlist[100];

    int counter = 0;
    while (true)
    {
        scanf("%s", word);

        if (strcmp(word, "ZZZ") == 0) {
            break;
        }

        size_t n = strlen(word);
        char *entry = malloc(n + 1);
        strcpy(entry, word);

        bool contains = false;

        for (int i = 0; i < counter; i++) {
            if (strcmp(wordlist[i], entry) == 0) {
                contains = true;
            }
        }

        if (!contains) {
            wordlist[counter] = entry;
            counter++;
        }
    };

    char temp[20];

    for (int i = 0; i < counter - 1; i++) {
        for (int j = i + 1; j < counter; j++) {
            if (strcmp(wordlist[i], wordlist[j]) > 0) {
                strcpy(temp, wordlist[i]);
                strcpy(wordlist[i], wordlist[j]);
                strcpy(wordlist[j], temp);
            }
        }
    }

    printf("\nSortierte Liste:\n");

    for (int i = 0; i < counter; i++) {
        printf("%s\n", wordlist[i]);
    }
    
    return EXIT_SUCCESS;
}
