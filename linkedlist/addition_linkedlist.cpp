#include "mylinked2.h"
void add(struct node **start, struct node **start2)
{
   struct node *start3,*p,*q,*r;
   p= (*start);
   q=(*start2);
    start3 = NULL;
    r = start3;
     int total, carry = 0;
    reverse(&(*start));
    reverse(&(*start2));
    while (p != 0 && q != 0)
    {
        total = (p->info + q->info) % 10 ; 
        insbeg(&r, total + carry);
        carry = (p->info + q->info) / 10;
        p=p->next;
        q=q->next;
    }
    
    while (p != 0)

    {
        insbeg(&r, p->info + carry);
        carry = (p->info) / 10;
        p = p->next;
    }
    while (q != 0)
    {
        insbeg(&r, q->info + carry);
        carry = (q->info) / 10;
        q = q->next;
    }
    if (carry > 0)
    {
        insbeg(&r, carry);
    }
    traverse(&r);
}
int main()
{
    struct node *start, *start2;
    start=NULL;
    start2=NULL;
    insend(&start,1);
    insend(&start, 8);
    insend(&start, 8);
    insend(&start2, 8);
    insend(&start2, 5);
    add(&start, &start2);
    return 0;
}