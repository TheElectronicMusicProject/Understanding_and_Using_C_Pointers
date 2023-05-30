#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*DISPLAY)(void *);
typedef int (*COMPARE)(void *, void *);

typedef struct _employee
{
    char name[32];
    unsigned char age;
} Employee;

int
compareEmployee (Employee * e1, Employee * e2)
{
    return strcmp(e1->name, e2->name);
}

void
displayEmployee (Employee * employee)
{
    printf("%s\t%d\n", employee->name, employee->age);
    return;
}

typedef struct _node
{
    void * data;
    struct _node * next;
} Node;

typedef struct _linkedList
{
    Node * head;
    Node * tail;
    Node * current;
} LinkedList;

typedef LinkedList Stack;

int compareEmployee(Employee * e1, Employee * e2);
void displayEmployee(Employee * employee);
void initializeList(LinkedList *);
void addHead(LinkedList *, void *);
void displayLinkedList(LinkedList *, DISPLAY);
void initializeStack(Stack * stack);
void push(Stack * stack, void * data);
void * pop(Stack * stack);

int
main (int argc, char ** argv)
{
    Stack stack = {0};

    Employee * samuel = (Employee *) malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age = 32;

    Employee * sally = (Employee *) malloc(sizeof(Employee));
    strcpy(sally->name, "Sally");
    sally->age = 28;

    Employee * susan = (Employee *) malloc(sizeof(Employee));
    strcpy(susan->name, "Susan");
    susan->age = 45;

    Employee * filippo = (Employee *) malloc(sizeof(Employee));
    strcpy(filippo->name, "Filippo");
    filippo->age = 27;

    Employee * mario = (Employee *) malloc(sizeof(Employee));
    strcpy(mario->name, "Mario");
    mario->age = 27;

    initializeStack(&stack);

    push(&stack, samuel);
    push(&stack, sally);
    push(&stack, susan);
    push(&stack, filippo);
    push(&stack, mario);

    displayLinkedList(&stack, (DISPLAY) displayEmployee);

    Employee * employee;

    for (int i = 0; i < 6; ++i)
    {
        employee = (Employee *) pop(&stack);
        printf("Popped %s\n", employee->name);
    }

    displayLinkedList(&stack, (DISPLAY) displayEmployee);

	return (0);
}	/* main() */

void
displayLinkedList (LinkedList * list, DISPLAY display)
{
    fprintf(stdout, "\nLinked List\n");

    Node * current = list->head;

    while (current != NULL)
    {
        display(current->data);
        current = current->next;
    }

    return;
}

void
initializeList (LinkedList * list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

    return;
}

void
addHead (LinkedList * list, void * data)
{
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = data;

    if (NULL == list->head)
    {
        list->tail = node;
        node->next = NULL;
    }
    else
    {
        node->next = list->head;
    }

    list->head = node;

    return;
}

void
initializeStack (Stack * stack)
{
    initializeList(stack);

    return;
}

void
push (Stack * stack, void * data)
{
    addHead(stack, data);

    return;
}

void *
pop (Stack * stack)
{
    Node * node = stack->head;

    if (NULL == node)
    {
        return NULL;
    }
    else if (node == stack->tail)
    {
        stack->tail = stack->head = NULL;
        void * data = node->data;
        free(node);
        return data;
    }
    else
    {
        stack->head = stack->head->next;
        void * data = node->data;
        free(node);
        return data;
    }
}