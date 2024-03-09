#include <stdio.h>
#include <string.h>

struct f
{
    char name[20], usn[20];
    float cgpa;
};

void read_struct(struct f *sptr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %f", sptr[i].name, sptr[i].usn, &sptr[i].cgpa);
    }
}

void display_struct(struct f *sptr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s %s %0.2f\n", sptr[i].name, sptr[i].usn, sptr[i].cgpa);
    }
}

void display_nod(struct f *sptr, int n)
{
    int i;
    float c = 9.20;
    for (i = 0; i < n; i++)
    {
        if (c == sptr[i].cgpa)
        {
            printf("selected candidTE IS %s %s %0.2f\n", sptr[i].name, sptr[i].usn, sptr[i].cgpa);
        }
    }
}

int main()
{
    struct f g[100];
    struct f *sptr = g;
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    read_struct(sptr, n);
    display_struct(sptr, n);
    display_nod(sptr, n);
    return 0;
}
