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

typedef struct _tree
{
    void * data;
    struct _tree * left;
    struct _tree * right;
} TreeNode;

int compareEmployee(Employee * e1, Employee * e2);
void displayEmployee(Employee * employee);
void insertNode(TreeNode ** realRoot, COMPARE compare, void * data);
void inOrder(TreeNode * root, DISPLAY display);
void postOrder(TreeNode * root, DISPLAY display);
void preOrder(TreeNode * root, DISPLAY display);

int
main (int argc, char ** argv)
{
    TreeNode * tree = NULL;

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

    insertNode(&tree, (COMPARE) compareEmployee, samuel);
    insertNode(&tree, (COMPARE) compareEmployee, sally);
    insertNode(&tree, (COMPARE) compareEmployee, susan);
    insertNode(&tree, (COMPARE) compareEmployee, filippo);
    insertNode(&tree, (COMPARE) compareEmployee, mario);

    printf("\n\nPre-order\n");
    preOrder(tree, (DISPLAY) displayEmployee);
    printf("\n\nIn-order\n");
    inOrder(tree, (DISPLAY) displayEmployee);
    printf("\n\nPost-order\n");
    postOrder(tree, (DISPLAY) displayEmployee);

	return (0);
}	/* main() */

void
insertNode (TreeNode ** realRoot, COMPARE compare, void * data)
{
    TreeNode * node = (TreeNode *) malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    TreeNode * root = *realRoot;

    if (NULL == root)
    {
        *realRoot = node;
        return;
    }
    else
    {
        while (1)
        {
            if (compare(root->data, data) > 0)
            {
                if (root->left != NULL)
                {
                    root = root->left;
                }
                else
                {
                    root->left = node;
                    break;
                }
            }
            else
            {
                if (root->right != NULL)
                {
                    root = root->right;
                }
                else
                {
                    root->right = node;
                    break;
                }
            }
        }
    }

    return;
}

void
inOrder (TreeNode * root, DISPLAY display)
{
    if (root != NULL)
    {
        inOrder(root->left, display);
        display(root->data);
        inOrder(root->right, display);
    }

    return;
}

void
postOrder (TreeNode * root, DISPLAY display)
{
    if (root != NULL)
    {
        postOrder(root->left, display);
        postOrder(root->right, display);
        display(root->data);
    }
    
    return;
}

void
preOrder (TreeNode * root, DISPLAY display)
{
    if (root != NULL)
    {
        display(root->data);
        preOrder(root->left, display);
        preOrder(root->right, display);
    }
    
    return;
}