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
/*******************************************/
void reverse(struct node **start)
{
    struct node *p;
    p = (*start);
    int n = count(&(*start));
    int arr[n] = {0};
    arr[0] = (*start)->info;
    int i = 1;
    while (i <= n)
    {
        arr[i] = p->info;
        p = p->next;
        i++;
    }
    p = (*start);
    i = count(&(*start));
    while (p != 0)
    {
        p->info = arr[i];
        i--;
        p = p->next;
    }
}
/***************************************************/
int value(struct node *p)
{
    int x = 0;
    while (p != NULL)
    {
        if (p->next != 0)
            x = x + p->info * 10;
        else
            x = x + p->info;
        p = p->next;
    }
    return x;
}
/***************************************************/
struct node* split(struct node **start,int x)
{
    int c = 0;
    struct node *p, *q;
    int idx;
    idx=count(&(*start))/2;
    p = (*start);
    if (p == NULL)
    {
        cout << "list can't be split " << endl;
    }
    else
    {
        while (p != 0)
        {
            c++;
            if (c == idx && idx!=0)
            {
                q = p->next;
                p->next = NULL;
                break;
            }
            p = p->next;
        }
    }
    if(x>q->info)
    return p;
    else
    return q;
}
/***************************************************/
struct node *min1(struct node **start)
{
    struct node *p, *q;
    p = (*start);
    int x = INT_MAX;

    while (p != 0)
    {
        if (p->info < x)
        {
            x = p->info;
            q = p;
            p = p->next;
        }
        else
        {
            p = p->next;
        }
    }
    //cout << x << endl;
    return q;
}
/***************************************************/
struct node *max(struct node **start)
{
    struct node *p, *q;
    int x = INT_MIN;
    while (p != 0)
    {
        if (p->info > x)
        {
            q = p;
            p = p->next;
        }
        else
        {
            p = p->next;
        }
    }
    cout<<q->info<<endl;
    return q;
}
/***************************************************/
int split1(struct node **start, int idx)
{
    int c = 0;
    struct node *p, *q;
    p = (*start);
    if (p == NULL)
    {
        cout << "list can't be split " << endl;
    }
    else
    {
        while (p!=0)
        {
            c++;
            if (c == idx)
            {
                q = p->next;
                p->next = NULL;
                break;
            }
            p = p->next;
        }
    }
    while (q != 0)
    {
        cout << q->info << " ";
        q = q->next;
    }
}

int main()
{
    struct node *start;
    start=NULL;
    int idx;
    cin >> idx;
    insend(&start, 100);
    insend(&start, 200);
    insend(&start, 300);
    insend(&start, 400);
    insend(&start, 500);
    insend(&start, 700);
    insend(&start, 10);
    insend(&start, 20);
    insend(&start, 30);
    traverse(&start);
    cout << "Now =>"<< " ";
    split1(&start,idx);
    cout << "split => ";
    traverse(&start);
}
