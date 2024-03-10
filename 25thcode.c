#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20],modal[20];
    int no_of_seats;
    float milage;
    struct node *link;

};
struct node* creat_node()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memmory not allocted");

    }
    else
    {
        scanf("%s%s%d%f",newnode->name,newnode->modal,&newnode->no_of_seats,&newnode->milage );
        newnode->link=NULL;
    }
    return newnode;


}
struct node* insert_front (struct node *head)
{
    struct node *newnode=creat_node();
    if (head==NULL)
    {
        head=newnode;

    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
    {
        printf("ram");
    }
    else
    {
        int max=0;
        float cox=0;
        cur=head;
        while(cur!=NULL)
        {
            if(max<cur->no_of_seats)
            {
                max=cur->no_of_seats;
            }
            cur=cur->link;
        }
        cur=head;
        printf("Cars with maximum seats:\n");
        while(cur!=NULL)
        {
            if(cur->no_of_seats==max)
            {

                printf("%s %s %d %0.1f\n",cur->name,cur->modal,cur->no_of_seats,cur->milage );
                if(cox<cur->milage)
                {
                    cox=cur->milage;
                }

            }
            cur=cur->link;
        }
        printf("\n");
        cur=head;
        while(cur!=NULL)
        {
            if(cur->milage==cox)
            {
                printf("Car with highest mileage:\n");
                printf("%s %s %d %0.1f\n",cur->name,cur->modal,cur->no_of_seats,cur->milage );
            }
            cur=cur->link;
        }



    }
}
int main() {
    struct node *head=NULL;
    int n;
    scanf("%d",&n);
    if(n>=1)
    {
        int i;
        for(i=0;i<n;i++)
        {
            head=insert_front(head);
        }
        display(head);
    }
    else{
        printf("Invalid input");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;

}
