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

int compareEmployee(Employee * e1, Employee * e2);
void displayEmployee(Employee * employee);
void initializeList(LinkedList *);
void addHead(LinkedList *, void *);
void addTail(LinkedList *, void *);
void delete(LinkedList *, Node *);
Node * getNode(LinkedList *, COMPARE, void *);
void displayLinkedList(LinkedList *, DISPLAY);

int
main (int argc, char ** argv)
{
    LinkedList linkedList = {0};

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
    

    initializeList(&linkedList);

    addHead(&linkedList, samuel);
    addHead(&linkedList, sally);
    addHead(&linkedList, susan);
    addTail(&linkedList, filippo);

    Node * node = getNode(&linkedList, (int (*)(void *, void *)) compareEmployee, sally);
    delete(&linkedList, node);
    free(sally);
    sally = NULL;

    displayLinkedList(&linkedList, (DISPLAY) displayEmployee);

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
addTail (LinkedList * list, void * data)
{
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (NULL == list->head)
    {
        list->head = node;
    }
    else
    {
        list->tail->next = node;
    }

    list->tail = node;

    return;
}

Node *
getNode(LinkedList * list, COMPARE compare, void * data)
{
    Node * node = list->head;

    while (node != NULL)
    {
        if (0 == compare(node->data, data))
        {
            return node;
        }

        node = node->next;
    }

    return NULL;
}

void
delete (LinkedList * list, Node * node)
{
    if (node == list->head)
    {
        if (NULL == list->head->next)
        {
            list->head = list->tail = NULL;
        }
        else
        {
            list->head = list->head->next;
        }
    }
    else
    {
        Node * tmp = list->head;

        while ((tmp != NULL) && (tmp->next != node))
        {
            tmp = tmp->next;
        }

        if (tmp != NULL)
        {
            tmp->next = node->next;
        }
    }

    free(node);

    return;
}