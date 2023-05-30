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

#define LIST_SIZE 10
Person * list[LIST_SIZE] = {0};

void
initializeList (void)
{
    for (int i = 0; i < LIST_SIZE; ++i)
    {
        list[i] = NULL;
    }

    return;
}

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

Person *
getPerson (void)
{
    for (int i = 0; i < LIST_SIZE; ++i)
    {
        if (list[i] != NULL)
        {
            Person * ptr = list[i];
            list[i] = NULL;
            return ptr;
        }
    }

    Person * person = (Person *) malloc(sizeof(Person));
    return person;
}

Person *
returnPerson (Person * person)
{
    for (int i = 0; i < LIST_SIZE; ++i)
    {
        if (NULL == list[i])
        {
            list[i] = person;
            return person;
        }
    }

    deallocatePerson(person);
    free(person);
    return NULL;
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

void
processPerson (void)
{
    Person * ptr_person;
    
    
    initializeList();
    ptr_person = getPerson();
    initializePerson(ptr_person, "Peter", "Underwood", "Manager", 36);
    displayPerson(*ptr_person);
    returnPerson(ptr_person);
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