#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct st
{
    char name[20], SRN[20], project_Name[20];
    int Semester;
};

struct rr
{
    char Operating_System_Name[20], Processor_Name[20];
    int RAM, Storage;
};

void read(struct st *sptr, struct rr *sptra, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%s%d%s%d%d%s", sptr[i].name, sptr[i].SRN, sptr[i].project_Name, &sptr[i].Semester,
              sptra[i].Operating_System_Name, &sptra[i].RAM, &sptra[i].Storage, sptra[i].Processor_Name);
    }
}

void disply(struct st *sptr, struct rr *sptra, int n)
{
    float avg;
    int total = 0, count = 0;
    char s[] = "Biohazard";
    char w[] = "Windows10";

    for (int i = 0; i < n; i++)
    {
        if (strcmp(w, sptra[i].Operating_System_Name) == 0)
        {
            total += sptra[i].RAM;
            count++;
        }
    }

    printf("Average RAM allocated for Windows10 Virtual machines:\n");
    avg = (float)total / count;
    printf("%0.2f gigabytes.\n\n", avg);

    printf("Student Details working on Biohazard project:\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(s, sptr[i].project_Name) == 0)
        {
            printf("%s %s %s %d\n", sptr[i].name, sptr[i].SRN, sptr[i].project_Name, sptr[i].Semester);
        }
    }
}

int main()
{
    struct st s[100];
    struct st *sptr = s;
    struct rr r[100];
    struct rr *sptra = r;
    int n;
    scanf("%d", &n);
    if(n>3)
    {
         read(sptr, sptra, n);
    disply(sptr, sptra, n);

    }
    else
        printf("N should be greater than 3.");

    return 0;
}
