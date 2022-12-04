#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *start = NULL;
/*****************************************************/

/*****************************************************/
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
/*********************************************/
int count() 
{
    int c=0;
    struct node *p;
    p = start;
    while (p != NULL)
    {
       c++;
        p = p->next;
    }
  return c;
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
    p = start;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

/******************************************************************************/

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
    cout<<c<<endl;
    return 0;
}

