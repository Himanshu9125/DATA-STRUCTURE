
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    struct node *next;
};
struct node *start;
/********************************************************************/
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
int insbeg(int x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = start;
    start = p;
}
/******************************************************/
int insaft(int x)
{
    struct node *q;
    struct node *p;
    struct node *r = q->next;
    p = getnode();
    // p->info = r;
    p->next = p;
}
int traverse()
{
    struct node *p;
    while (p != NULL)
    {
        if((p->info)%2==0){
        cout << p->info << " "<<"even"<<" ";
        p = p->next;
        }
        else{
         cout << p->info << " "<<"odd"<<" ";
        p = p->next;
        }
    }
}
int main()
{
    start = NULL;
    insbeg(100);
    insbeg(200);
    insbeg(35);
    insbeg(400);
    insbeg(500);
    insbeg(7);
    insbeg(10);
    insbeg(20);
    insbeg(3);
    traverse();
    return 0;
}