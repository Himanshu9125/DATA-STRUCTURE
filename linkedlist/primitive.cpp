#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *start = NULL,*start2=NULL;
/*****************************************************/

/*****************************************************/
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
/*********************************************/
int delbeg()
{
    int x;
    struct node *p;
    p = start;
    if (p != NULL)
    {
        start = p->next;
        x = p->info;

        free(p);
    }
    cout << "deleted node info= " << x << endl;
}
/******************************************************/
int deleaft(int idx)
{
    struct node *q, *ptr, *r;
    ptr = start;
    int x;
    int count = 0;
    while (ptr->next != NULL)
    {
        count++;
        if (count == idx)
        {

            x = ptr->info;
            q = ptr->next;
            r = q->next;
            ptr->next = r;
            free(q);
            break;
        }
        ptr = ptr->next;
    }
    cout << " delete after" << x << endl;
}
/******************************************************/
int delend()
{
    struct node *p, *q;
    p = start;
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
            start = NULL;
    }
}
/*********************************************/
int insbeg(int x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = start;
    start = p;
}
/******************************************************/
void insaft(int idx, int x)
{
    struct node *ptr, *q;
    int count = 0;
    ptr = start;
    while (ptr != NULL)
    {
        count++;
        if (count == idx)
        {
            q = getnode();
            q->info = x;
            q->next = ptr->next;
            ptr->next = q;
            break;
        }
        else
            ptr = ptr->next;
    }
}
/******************************************************/
int insend(int x)
{
    struct node *ptr, *q;
    q = getnode();
    q->info = x;
    q->next = NULL;
    ptr = start;
    if (ptr->next == NULL)
        insbeg(x);
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
int traverse()
{
    struct node *p;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout<<endl;
}

/******************************************************************************/
int count(){
     struct node *ptr;
     int c=0;
while (ptr->next != NULL)
{
    c++;
    ptr = ptr->next;
    
}
 return c;
}
/******************************************************************************/
int ordered_ins(int x)
{
    struct node *p, *q;
    p = start;
    q = NULL;
    int ct = 0;
    while ((p != 0) && (p->info) <= x)
    {
        q = p;
        p = p->next;
        ct++;
    }
    if (q == 0)
        insbeg(x);
    else
        insaft(ct, x);
}
int main()
{
    int idx,x;
    cin>>idx>>x;
    
    insbeg(100);
    insbeg(200);
    insbeg(300);
    insbeg(400);
    insbeg(500);
    insbeg(700);
    insbeg(10);
    insbeg(20);
    insbeg(30);
    traverse();
    cout << "NOW=>" << endl;
    insend(40);
    insend(50);
    insaft(idx, x);
    
    traverse();
    
    return 0;
}
