#include "mydub.h"

void poll_add(struct node **start, struct node **start2)
{
    struct node *start3;
    start3 = NULL;
    struct node *p, *q;
    p = (*start);
    q = (*start2);
    while (p != 0 && q != 0)
    {
        if (p->priv == q->priv)
        {
            insend(&start3, ((p->info) - (q->info)), p->priv);
            p = p->next;
            q = q->next;
        }
        else if (p->priv > q->priv)
        {
            insend(&start3, (p->info), p->priv);
            p = p->next;
        }
        else
        {
            insend(&start3, (-1) * (q->info), q->priv);
            q = q->next;
        }
    }
    while (p != 0)
    {
        insend(&start3, p->info, p->priv);
        p = p->next;
    }
    while (q != 0)
    {
        insend(&start3, (-1) * q->info, q->priv);
        q = q->next;
    }
    traverse(&start3);
}
int main()
{
    struct node *start, *start2;
    start = NULL;
    start2 = NULL;
    cout<<"p(x1) = "<<endl;
    insend(&start, 3, 5);
    insend(&start, -4, 3);
    insend(&start, 2, 2);
    insend(&start, 9, 1);
    insend(&start, -8, 0);
    traverse(&start);
    cout<<endl << "p2(x) = " ;
    insend(&start2, 7, 6);
    insend(&start2, 2, 5);
    insend(&start2, -1, 4);
    insend(&start2, 3, 3);
    insend(&start2, 7, 2);
    traverse(&start2);
    cout<<endl << "now" << endl<<" p(x) = " ;
    poll_add(&start, &start2);
}
