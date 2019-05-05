#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include <person.h>

ListElement * head;

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
                printf("\nCould not insert person. Person already exists.\n");
            }
        } else if (input[0] == 'R' || input[0] == 'r') {
            printf("Person to remove:\n");
            Person p = getInput();
            if (removePerson(p)) {
                printf("\nPerson successfully removed.\n");
            } else {
                printf("\nCould not delete person. Person doesn't exists.\n");
            }
        } else if (input[0] == 'S' || input[0] == 's') {
            show();
        } else if (input[0] == 'C' || input[0] == 'c') {
            if (clear()) {
                printf("List successfully cleared.\n");
            }
        } else if (input[0] == 'E' || input[0] == 'e') {
            printf("Exiting...\n");
            end = true;
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
    if (!head) {
        head = malloc(sizeof(ListElement));
        head->context = p;
        head->next = NULL;
        return true;
    }

    ListElement * current = head;
    ListElement * before = NULL;

    ListElement * newElement = malloc(sizeof(ListElement));
    newElement->context = p;
    newElement->next = NULL;

    while (true) {
        if (comparePerson(p, current->context) == 0) {
            return false;
        }

        if (comparePerson(p, current->context) > 0) {
            if (current->next == NULL) {
                current->next = newElement;
                return true;
            }
            before = current;
            current = current->next;
        } else if (comparePerson(p, current->context) < 0) {
            if (before == NULL) {
                newElement->next = current;
                head = newElement;
                return true;
            }
            before->next = newElement;
            newElement->next = current;
            return true;
        }
    }
}

bool removePerson(Person p) {
    if (head == NULL) {
        return false;
    }

    ListElement * current = head;
    ListElement * before = NULL;

    while (current != NULL) {
        if (comparePerson(p, current->context) < 0) {
            return false;
        }

        if (comparePerson(p, current->context) == 0) {
            if (before == NULL) {
                head = current->next;
                free(current);
                return true;
            }

            before = current->next;
            free(current);
            return true;
        }

        if (comparePerson(p, current->context) > 0) {
            before = current;
            current = current->next;
        }
    }

    return false;
}

void show() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List of people:\n");

    ListElement * current = head;

    while (current != NULL) {
        display_person(current->context);
        current = current->next;
    }
}

bool clear() {
    if (head == NULL) {
        return true;
    }

    ListElement * current = head;
    head = NULL;

    while (current != NULL) {
        ListElement * toRemove = current;
        current = current->next;
        free(toRemove);
    }
    
    if (head == NULL) {
        return true;
    }

    return false;
}

void display_person(Person p) {
    printf("%s %s, %d\n", p.firstName, p.name, p.age);
}

int comparePerson(Person p1, Person p2) {
    int comparison = strcmp(p1.name, p2.name);
    if (comparison != 0) {
        return comparison;
    } else {
        comparison = strcmp(p1.firstName, p2.firstName);
        if (comparison != 0) {
            return comparison;
        }
        
        return p1.age - p2.age;
    }
}