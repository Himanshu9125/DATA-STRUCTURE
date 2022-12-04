#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
}

void create(int a[], int n)
{
    struct node *m, *last;
    first = getnode();
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        m = getnode();
        m->data = a[i];
        m->next = NULL;
        last->next = m;
        last = m;
    }
}
void insert_given(int idx,int x){
    struct node *p,*q;
    int count=0;
    p = first;
    while (p != NULL)
    {     
        count++;
        if(count==idx){
        q=getnode();
        q->data=x;
        q->next=p->next;
         p->next=q;
         break;
        }
        else
        p=p->next;
    }
}

void traverse()
{
    struct node *p;
    p = first;
    while (p != NULL)
    {
        printf("% d", p->data);
        p = p->next;
    }
}

int main()
{
    int idx,x;
    scanf("%d%d",&idx,&x);
    int a[] = {4, 5, 6, 8, 9};
    create(a, 5);
    insert_given(idx,x);
    traverse();
}
