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

struct node *initialize()
{
    struct node *top;
    top=NULL;
    return top;
}
void push(struct node **start, int x)
{
    insbeg(&(*start),x);
}
int pop(struct node **start){
    int x;
    if((*start)==0){
        cout<<"stack under flow"<<endl;
    }
    else{
    x=delbeg(&(*start));
    return x;
    }
}
int Is_empty(struct node **start){
    if((*start)==0){
        return true;
    }
    else
      return false;
}
int main(){
    struct node *top =initialize();
    int a[5]={10,20,30,40,50};
    for (int i = 0; i < 5; i++)
    {
        push(&top,a[i]);
    }

    cout <<pop(&top)<<" ";
    cout << pop(&top) << " ";
    cout << pop(&top) << " ";
    cout << pop(&top) << " ";
    cout << pop(&top) << " ";
    cout << pop(&top) << " ";
}
