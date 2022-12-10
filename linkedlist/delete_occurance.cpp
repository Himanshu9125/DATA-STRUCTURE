
#include <bits/stdc++.h>
#include <string.h>

using namespace std;
/***************************************************/
struct node
{
    int info;
    struct node *next;
};
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void insbeg(struct node **start, int x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = (*start);
    (*start) = p;
}
/*****************************************************/
struct node *insend(struct node **p, int x)
{
    struct node *ptr, *q;
    q = getnode();
    q->info = x;
    q->next = NULL;
    ptr = (*p);
    if (ptr == NULL)
        insbeg(&(*p), x);
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = q;
    }
    return q;
}
int traverse(struct node **q)
{

    struct node *p;
    p = (*q);
    while (p != NULL)
    {

        cout << p->info << " ";
        p = p->next;
    }
}

/*****************************************************/

int delbeg(struct node **start)
{
    int x;
    struct node *p;
    p = *start;
    if (p != NULL)
    {
        (*start) = p->next;
        x = p->info;

        free(p);
    }
    // cout << "deleted node info= " << x << endl;
    return x;
}
/******************************************************/
int deleaft(struct node **p)
{
    struct node *q, *ptr, *r;
    ptr = (*p);
    int x;
    x = ptr->next->info;
    q = ptr->next;
    r = ptr->next->next;
    free(q);
    ptr->next = r;

    cout << " deleted element =" << x << endl;
}
void del_num(struct node **start, int x)
{
    struct node *p, *q, *r;
    p = (*start);
    q = 0;
    if ((*start) != 0)
    {
        while (p != 0)
        {
            if (p->info == x)
            {
                if (q == 0)
                {
                    p = p->next;
                    delbeg(&(*start));
                }
                else
                {
                    p = p->next;
                    deleaft(&q);
                }
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
        traverse(&(*start));
    }
    else
    {
        cout << " no node exist" << endl;
    }
}
int main()
{
    struct node *start;
    start = NULL;
     insend(&start, 2);
     insend(&start, 2);
     insend(&start,2);
     insend(&start, 5);
     insend(&start, 6);
     insend(&start, 5);
     insend(&start, 8);
     insend(&start, 5);
     insend(&start, 8);
     traverse(&start);
    cout << endl;
    del_num(&start, 2);
}
