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

typedef struct _alternatePerson
{
    char * first_name;
    char * last_name;
    char * title;
    short age;
} AlternatePerson;

void
initializePerson (Person * person, const char * fn,
                  const char * ln, const char * title,
                  unsigned int age)
{
    person->first_name = (char *) malloc(strlen(fn) + 1);
    strcpy(person->first_name, fn);
    person->last_name = (char *) malloc(strlen(ln) + 1);
    strcpy(person->last_name, fn);
    person->title = (char *) malloc(strlen(title) + 1);
    strcpy(person->title, fn);
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
processPerson (void)
{
    Person * ptr_person;
    ptr_person = (Person *) malloc(sizeof(Person));

    initializePerson(ptr_person, "Peter", "Underwood", "Manager", 36);
    deallocatePerson(ptr_person);
    free(ptr_person);
    ptr_person = NULL;

    return;
}

int
main (int argc, char ** argv)
{
    Person person;
    AlternatePerson otherPerson;

    printf("%d\n", sizeof(person));
    printf("%d\n", sizeof(otherPerson));

    processPerson();

	return (0);
}	/* main() */