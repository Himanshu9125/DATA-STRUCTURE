#include <bits/stdc++.h>
#include <string.h>

using namespace std;
/***************************************************/
struct node
{
    int info;
    struct node *next;
};

/*****************************************************/

/*****************************************************/
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
/*********************************************/
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
/******************************************************/
int delend(struct node **start)
{
    struct node *p, *q;
    p = (*start);
    if (p == NULL)
    {
        cout << "no deletion" << endl;
    }
    else
    {
        q = NULL;
        while ((p->next) != NULL)
        {
            q = p;
            p = p->next;
        }
        if (q != NULL)
        {
            q->next = NULL;
            int x = p->info;
            free(p);
            cout << x << endl;
        }
        else
            *start = NULL;
    }
}
/*********************************************/
void insbeg(struct node **start, int x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = (*start);
    (*start) = p;
}
/******************************************************/
void insaft(struct node **p, int x)
{
    struct node *ptr, *q;
    int count = 0;
    ptr = (*p);
    q = getnode();
    q->info = x;
    q->next = ptr->next;
    ptr->next = q;
}
/******************************************************/
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
/**************************************************************************/
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

/******************************************************************************/
int count(struct node **p)
{
    struct node *ptr;
    ptr = (*p);
    int c = 0;
    while (ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}
/******************************************************************************/
int ordered_ins(struct node **start, int x)
{
    struct node *p, *q;
    p = (*start);
    q = NULL;
    while ((p != 0) && (p->info) <= x)
    {
        q = p;
        p = p->next;
    }
    if (q == 0)
        insbeg(&(*start), x);
    else
        insaft(&q, x);
}
void Union(struct node *start, struct node *start2)
{
    struct node *p, *q;
    struct node *start3;
    p = (start);
    q = (start2);
    start3 = NULL;
    while (p != 0 && q != 0)
    {
        if ((p->info) < (q->info))
        {
            insend(&start3, p->info);
            p = p->next;
        }
        else if ((p->info) > (q->info))
        {
            insend(&start3, q->info);
            q = q->next;
        }
        else{
            insend(&start3, q->info);
            p = p->next;
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
   cout<<"union set\n"<<"{ ";
    traverse(&start3);
    cout<<" }"<<endl;
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
    cout<<"1st set\n"<<"{ ";
    traverse(&start);
    cout<<" }"<<endl;
    ordered_ins(&start2, 20);
    ordered_ins(&start2, 25);
    ordered_ins(&start2, 30);
    ordered_ins(&start2, 35);
    ordered_ins(&start2, 40);
    ordered_ins(&start2, 55);
     cout<<"2st set\n"<<"{ ";
    traverse(&start2);
    cout << " }" << endl;
    Union(start, start2);
}
