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

void traverse()
{
    int sum=0;
    struct node *p;
    p = first;
    if(p!=NULL){
    while (p != NULL)
    {
        sum=sum+(p->data);
        p = p->next;
    }
    printf("%d",sum);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    create(a, n);
    traverse();
}
