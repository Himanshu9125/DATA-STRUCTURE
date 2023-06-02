#include "mylinked2.h"

void merge(struct node *start, struct node *start2)
{
    struct node *p, *q;
    struct node *start3;
    p = (start);
    q = (start2);
    start3 = NULL;
    while (p!= 0 && q != 0)
    {
        if ((p->info) < (q->info))
        {
            insend(&start3, p->info);
            p = p->next;
        }
        else
        {
            insend(&start3, q->info);
            q = q->next;
        }
    }
    while (p != 0)
    {
        insend(&start3, p->info);
        p = p->next;
    }
    while (q != 0)
    {
        insend(&start3, q->info);
        q = q->next;
    }
    traverse(&start3);
}

int main()
{
    struct node *start;
    start = NULL;
    struct node *start2;
    start2 = NULL;

    ordered_ins(&start, 10);
    ordered_ins(&start, 20);
    ordered_ins(&start, 30);
    ordered_ins(&start, 40);
    ordered_ins(&start, 50);
    ordered_ins(&start, 60);
    traverse(&start);
    cout<<endl;
    ordered_ins(&start2, 20);
    ordered_ins(&start2, 25);
    ordered_ins(&start2, 30);
    ordered_ins(&start2, 35);
    ordered_ins(&start2, 40);
    ordered_ins(&start2, 55);
    traverse(&start2);
    cout<<endl;
   merge(start, start2);
   
}