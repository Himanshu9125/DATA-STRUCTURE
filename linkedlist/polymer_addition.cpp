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


void poll_add(struct node**start,struct node **start2){
   struct node *start3;
   start3=NULL;
   struct node *p,*q;
   p=(*start);
   q=(*start2);
   while (p!=0 && q!=0)
   {
      if(p->priv==q->priv){
         insend(&start3,((p->info)+(q->info)),p->priv);
       p=p->next;
       q=q->next;
       }
       else if(p->priv>q->priv){
           insend(&start3, (p->info), p->priv);
           p = p->next;

       }
       else {
           insend(&start3,  (q->info), q->priv);
           q=q->next;
       }
   }
   while (p!=0)
   {
     insend(&start3,p->info,p->priv);
     p=p->next;
   }
   while (q != 0)
   {
       insend(&start3, q->info, q->priv);
       q = q->next;
   }
   traverse(&start3);
}
int main(){
    struct node *start,*start2;
    start=NULL;
    start2=NULL;
    insend(&start,3,5);
    insend(&start, -4, 3);
    insend(&start, 2, 2);
    insend(&start, 9, 1);
    insend(&start, -8, 0);
    traverse(&start);
    cout<<" "<<endl;
    insend(&start2, 7, 6);
    insend(&start2, 2, 5);
    insend(&start2, -1, 4);
    insend(&start2, 3, 3);
    insend(&start2, 7, 2);
    traverse(&start2);
    cout<<"now"<<endl;
    poll_add(&start,&start2);
}
