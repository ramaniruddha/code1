#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *create_node()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        scanf("%d", &newnode->data);
        newnode->link = NULL;
    }
    return newnode;
}

struct node *insert_end(struct node *head)
{
    struct node *newnode = create_node();
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *cur = head;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = newnode; // Update the link field of the last node
    }
    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        struct node *cur = head;
        while (cur != NULL)
        {
            printf("%d ", cur->data);
            cur = cur->link;
        }
        printf("\n");
    }
}

int main()
{
    struct node *head = NULL;
    int i, n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        head = insert_end(head);
        display(head);
    }
    return 0;
}
