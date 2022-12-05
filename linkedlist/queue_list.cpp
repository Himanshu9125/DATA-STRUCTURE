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
}void enqueue(struct node **start,int x){

    insend(&(*start),x);
}
int dequeue(struct node **front){
    struct node*p;
    p = (*front);
    if(p==0){
        cout<<endl;
        cout<<"Queue underflow"<<endl;
        exit(1);
    }
    else{
   // p=(*front);
    *front=(*front)->next;
    int x=p->info;
     free(p);
     return x;
    }
}
int Isempty(struct node **front, struct node **rear)
{
    if((*front==(*rear))||(*front==0)){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    struct node *rear,*front;
    rear=NULL;
    enqueue(&rear,10);
    front=rear;
    enqueue(&rear, 20);
    enqueue(&rear, 30);
    enqueue(&rear, 40);
    enqueue(&rear, 50);
    enqueue(&rear, 60);
    cout<<dequeue(&front)<<" ";
    cout << dequeue(&front) << " ";
    cout << dequeue(&front) << " ";
    cout << dequeue(&front) << " ";
    cout << dequeue(&front) << " ";
    cout << dequeue(&front) << " ";
    cout << dequeue(&front) << " ";
}
