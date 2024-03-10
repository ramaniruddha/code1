#include <stdio.h>
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
        printf("Memory not allocated\n");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->link = newnode; // Circular link to itself
    }
    return newnode;
}

struct node *insert_front(struct node *head)
{
    struct node *newnode = create_node();
    if (newnode != NULL)
    {
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            struct node *cur = head;
            while (cur->link != head)
            {
                cur = cur->link;
            }
            cur->link = newnode;
            newnode->link = head;
            head = newnode;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *cur = head;
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d ", cur->data);
            cur = cur->link;
        } while (cur != head);
        printf("\n");
    }
}

int main()
{
    struct node *head = NULL;

    // Insert nodes at the front
    head = insert_front(head);
    head = insert_front(head);
    head = insert_front(head);

    // Display the circular linked list
    printf("Circular Linked List: ");
    display(head);

    return 0;
}
