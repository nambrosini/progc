#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

#include <person.h>

ListElement root;

void showMenu() {
    printf("Welcome to your personal stalking list:\n");
    printf("Make your choice:\n");
    printf("I(nsert)\nR(emove)\nS(how)\nC(lear)\nE(nd)\n");
}

int main(int argc, char* argv[])
{    
    char * input = "";
    bool end = false;

    while (!end) {
        showMenu();
        scanf("%s", input);
        
        if (strcasecmp(input, "i") || strcasecmp(input, "insert")) {
            Person p = getInput();
            if (insert(p)) {
                printf("Person successfully inserted.\n");
            } else {
                printf("Could not insert person. Person already exists.\n");
            }
        } else if (strcasecmp(input, "r") || strcasecmp(input, "remove")) {
            Person p = getInput();
            if (removePerson(p)) {
                printf("Person successfully removed.\n");
            } else {
                printf("Could not delete person. Person doesn't exists.\n");
            }
        } else if (strcasecmp(input, "s") || strcasecmp(input, "show")) {
            show();
        } else if (strcasecmp(input, "c") || strcasecmp(input, "clear")) {
            if (clear()) {
                printf("List successfully cleared.\n");
            }
        } else if (strcasecmp(input, "e") || strcasecmp(input, "end")) {
            exit(0);
        } else {
            printf("Command not found.\n");
        }
    }
    
    return EXIT_SUCCESS;
}

Person getInput() {
    Person p;
    scanf("Input last name: %s", p.name);
    scanf("Input first name: %s", p.firstName);
    scanf("Input age: %d", &p.age);
    return p;
}

bool insert(Person p) {
    return false;
}

bool removePerson(Person p) {
    return false;
}

void show() {

}

bool clear() {
    return false;
}