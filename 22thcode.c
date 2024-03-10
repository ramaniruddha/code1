#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// Function to create a new node
struct node *create_node()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->link = NULL;
    }
    return newnode;
}

// Function to insert a node at the end of the list
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
        cur->link = newnode;
    }
    return head;
}

// Function to insert a node at a specific position in the list
struct node *delete_at_pos(struct node *head, int pos)
{
    struct node *newnode = create_node();
    int count = 0;
    struct node *cur = head;

    // Count the number of nodes
    while (cur != NULL)
    {
        count++;
        cur = cur->link;
    }

    if (head == NULL)
    {
        printf("nothing to delete\n");
    }
    else if (pos==count)
    {
        cur = head;
        struct node *prev=NULL;
        while (cur->link != NULL)
        {
            prev=cur;
            cur = cur->link;
        }
        prev->link=NULL;
        free(cur);
    }
    else if (pos == 1)
    {
        struct node *temp=head;
        head=head->link;
        free(temp);
    }
    else if (pos > 1 && pos <= count)
    {
        cur = head;
        struct node *prev = NULL;

        for (int i = 0; i < pos-1; i++)
        {
            prev = cur;
            cur = cur->link;
        }

        prev->link = cur->link;
        free(cur);
    }
    return head;
}

// Function to display the linked list
void display_list(struct node *head)
{
    struct node *cur = head;
    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->link;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;

    // Insert nodes at the end
    head = insert_end(head);
    head = insert_end(head);
    head = insert_end(head);

    // Display the linked list
    printf("Linked List after inserting at the end: ");
    display_list(head);

    // Insert node at a specific position
    int position;
    printf("Enter the position to insert a node: ");
    scanf("%d", &position);
    head = delete_at_pos(head, position);

    // Display the linked list after insertion at a specific position
    printf("Linked List after deleteing at position %d: ", position);
    display_list(head);

    return 0;
}


