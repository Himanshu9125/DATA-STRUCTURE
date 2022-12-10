#include <bits/stdc++.h>
using namespace std;

struct node
{
    int priv;
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
}
/******************************************************/
int deleaft(struct node **p)
{
    struct node *ptr, *r;
    ptr = (*p)->next;
    r = (*p);
    int x= ptr->info;
    r->next = ptr->next;
    free(ptr);
    return x;
    // cout << " delete after" << x << endl;
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
            //cout << x << endl;
        }
        else
            *start = NULL;
    }
}
/*********************************************/
int insbeg(struct node **start, int x,int y)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->priv = y;
    p->next = (*start);
    (*start) = p;
}
/******************************************************/
void insaft(struct node **p, int x,int y)
{
    struct node *ptr, *q;
    int count = 0;
    ptr = (*p);
    q = getnode();
    q->info = x;
    q->priv =y;
    q->next = ptr->next;
    ptr->next = q;
}
/******************************************************/
int insend(struct node **p, int x,int y)
{
    struct node *ptr, *q;
    q = getnode();
    q->info = x;
    q->priv =y;
    q->next = NULL;
    ptr = (*p);
    if (ptr == NULL)
        insbeg(&(*p), x,y);
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = q;
    }
}
/**************************************************************************/
int traverse(struct node **q)
{
    struct node *p;
    p = (*q);
    while (p != NULL)
    {
        if(p->next!=0)
        cout << p->info << " x^"<< p->priv<<" + ";
        else
            cout << p->info << " x^" << p->priv << " ";
        p = p->next;
    }
}

/******************************************************************************/
int count(struct node **p)
{
    struct node *ptr;
    ptr = (*p);
    int c = 0;
    while (ptr->next != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}
/******************************************************************************/
int ordered_ins(struct node **start, int x ,int y)
{
    struct node *p, *q;
    p = (*start);
    q = NULL;
    while ((p != 0) && (p->priv) <= y)
    {
        q = p;
        p = p->next;
    }
    if (q == 0)
        insbeg(&(*start), x,y);
    else
        insaft(&q, x,y);
}
