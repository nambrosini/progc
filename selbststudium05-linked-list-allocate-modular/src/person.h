#ifndef _PERSON_H_
#define PERSON_H

#include <stdbool.h>

typedef struct {
    char name[20];
    char firstName[20];
    unsigned age;
} Person;

typedef struct LE ListElement;
struct LE {
    Person context;
    ListElement *next;
};

Person getInput();

bool insert(Person p);

bool removePerson(Person p);

void show();

bool clear();

void display_person(Person p);

bool isPersonEmpty(Person p);

int comparePerson(Person p1, Person p2);

#endif //_PERSON_H_