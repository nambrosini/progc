#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include <person.h>

ListElement root;

void showMenu() {
    printf("\nWelcome to your personal stalking list:\n");
    printf("I(nsert)\nR(emove)\nS(how)\nC(lear)\nE(nd)\n");
    printf("Make your choice:\n");
}

int main(int argc, char* argv[])
{    
    char input[20] = "";
    bool end = false;

    while (!end) {
        showMenu();
        scanf("%s", input);
        
        if (input[0] == 'I' || input[0] == 'i') {
            printf("Person to insert:\n");
            Person p = getInput();
            if (insert(p)) {
                printf("\nPerson successfully inserted.\n");
            } else {
                printf("Could not insert person. Person already exists.\n");
            }
        } else if (input[0] == 'R' || input[0] == 'r') {
            printf("Person to remove:\n");
            Person p = getInput();
            if (removePerson(p)) {
                printf("Person successfully removed.\n");
            } else {
                printf("Could not delete person. Person doesn't exists.\n");
            }
        } else if (input[0] == 'S' || input[0] == 's') {
            show();
        } else if (input[0] == 'C' || input[0] == 'c') {
            if (clear()) {
                printf("List successfully cleared.\n");
            }
        } else if (input[0] == 'E' || input[0] == 'e') {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Command not found.\n");
        }
    }
    
    return EXIT_SUCCESS;
}

Person getInput() {
    Person p;
    printf("Input first name: ");
    scanf("%s", p.firstName);
    printf("\nInput name: ");
    scanf("%s", p.name);
    printf("\nInput age: ");
    scanf("%d", &p.age);
    return p;
}

bool insert(Person p) {
    if (isPersonEmpty(root.context)) {
        root.context = p;

        return true;
    }

    ListElement le = root;

    ListElement newLe;
    newLe.context = p;

    while (true) {
        ListElement next = *le.next; // If next is null everything fucks up!!


        // if (comparePerson(next.context, newLe.context) > 0) {
        //     if (!next.next) {
        //         next.next = &newLe;
        //         return true;
        //     }
        //     le = next;
        // }
        // } else if (comparePerson(next.context, p) < 0) {
        //     newLe.next = &next;
        //     le.next = &newLe;
        //     return true;
        // } else {
        //     return false;
        // }
    }
}

bool removePerson(Person p) {
    return false;
}

void show() {
    printf("List of people:\n");
    ListElement le = root;

    bool stop = false;

    while(!stop) {
        display_person(le.context);
        if (le.next) {
            le = *le.next;
        } else {
            stop = true;
        }
    }
}

bool clear() {
    return false;
}

void display_person(Person p) {
    printf("%s %s, %d\n", p.firstName, p.name, p.age);
}

bool isPersonEmpty(Person p) {
    return p.name[0] == '\0' || 
        p.firstName[0] == '\0' ||
        p.age == 0;
}

int comparePerson(Person p1, Person p2) {
    int comparison = strcmp(p1.name, p2.name);
    if (comparison != 0) {
        return comparison;
    } else {
        comparison = strcmp(p1.firstName, p2.firstName);
        if (comparison != 0) {
            return comparison;
        } else {
            return p2.age - p1.age;
        }
    }
}