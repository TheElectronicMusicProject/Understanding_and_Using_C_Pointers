#include "link.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person
{
    char * first_name;
    char * last_name;
    char * title;
    unsigned int age;
} Person;

void
initializePerson (Person * person, const char * fn,
                  const char * ln, const char * title,
                  unsigned int age)
{
    person->first_name = (char *) malloc(strlen(fn) + 1);
    strcpy(person->first_name, fn);
    person->last_name = (char *) malloc(strlen(ln) + 1);
    strcpy(person->last_name, ln);
    person->title = (char *) malloc(strlen(title) + 1);
    strcpy(person->title, title);
    person->age = age;

    return;
}

void
deallocatePerson (Person * person)
{
    free(person->first_name);
    free(person->last_name);
    free(person->title);

    return;
}

void
displayPerson (Person person)
{
    printf("Name %s\n", person.first_name);
    printf("Surname %s\n", person.last_name);
    printf("Title %s\n", person.title);
    printf("Age %u\n", person.age);

    return;
}

int
main (int argc, char ** argv)
{
    LinkedList * list = getLinkedListInstance();

    Person * person = (Person *) malloc(sizeof(Person));
    initializePerson(person, "Peter", "Underwood", "Manager", 36);
    addNode(list, person);
    
    person = (Person *) malloc(sizeof(Person));
    initializePerson(person, "Sue", "Stevenson", "Developer", 28);
    addNode(list, person);

    person = removeNode(list);
    displayPerson(*person);
    deallocatePerson(person);
    free(person);

    person = removeNode(list);
    displayPerson(*person);
    deallocatePerson(person);
    free(person);

    removeLinkedListInstance(list);
    
	return (0);
}	/* main() */