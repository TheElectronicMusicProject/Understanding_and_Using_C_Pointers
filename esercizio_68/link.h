#ifndef LINK_H
#define LINK_H

typedef void * Data;
typedef struct _linkedList LinkedList;

LinkedList * getLinkedListInstance();
void removeLinkedListInstance(LinkedList * list);
void addNode(LinkedList *, Data);
Data removeNode(LinkedList *);

#endif /* LINK_H */