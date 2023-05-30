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

typedef LinkedList Queue;

int compareEmployee(Employee * e1, Employee * e2);
void displayEmployee(Employee * employee);
void initializeList(LinkedList *);
void addHead(LinkedList *, void *);
void displayLinkedList(LinkedList *, DISPLAY);
void initializeQueue(Queue * queue);
void enqueue(Queue * queue, void * node);
void * dequeue(Queue * queue);

int
main (int argc, char ** argv)
{
    Queue queue = {0};

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
    

    initializeQueue(&queue);

    enqueue(&queue, samuel);
    enqueue(&queue, sally);
    enqueue(&queue, susan);
    enqueue(&queue, filippo);
    enqueue(&queue, mario);

    displayLinkedList(&queue, (DISPLAY) displayEmployee);

    void * data = dequeue(&queue);
    printf("Dequeued %s\n", ((Employee *) data)->name);
    free(samuel);
    samuel = NULL;

    data = dequeue(&queue);
    printf("Dequeued %s\n", ((Employee *) data)->name);
    free(sally);
    sally = NULL;

    data = dequeue(&queue);
    printf("Dequeued %s\n", ((Employee *) data)->name);
    free(susan);
    susan = NULL;

    data = dequeue(&queue);
    printf("Dequeued %s\n", ((Employee *) data)->name);
    free(filippo);
    filippo = NULL;

    data = dequeue(&queue);
    printf("Dequeued %s\n", ((Employee *) data)->name);
    free(mario);
    mario = NULL;

    displayLinkedList(&queue, (DISPLAY) displayEmployee);

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
initializeQueue (Queue * queue)
{
    initializeList(queue);

    return;
}

void
enqueue (Queue * queue, void * node)
{
    addHead(queue, node);

    return;
}

void *
dequeue (Queue * queue)
{
    Node * tmp = queue->head;
    void * data = NULL;

    if (NULL == queue->head)
    {
        data = NULL;
    }
    else if (queue->head == queue->tail)
    {
        queue->head = NULL;
        queue->tail = NULL;
        data = tmp->data;
        free(tmp);
    }
    else
    {
        while (tmp->next != queue->tail)
        {
            tmp = tmp->next;
        }

        queue->tail = tmp;
        tmp = tmp->next;
        queue->tail->next = NULL;
        data = tmp->data;
        free(tmp);
    }

    return data;
}