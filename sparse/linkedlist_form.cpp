#include <bits/stdc++.h>
#include <string.h>

using namespace std;

struct node
{
    int info;
    int row;
    int clm;
    struct node *next;
};

struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void insbeg(struct node **start, int x,int r,int c)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->clm=c;
    p->row=r;
    p->next = (*start);
    (*start) = p;
}

void insaft(struct node **p, int x, int r, int c)
{
    struct node *ptr, *q;
    int count = 0;
    ptr = (*p);
    q = getnode();
    q->info = x;
    q->clm = c;
    q->row = r;
    q->next = ptr->next;
    ptr->next = q;
}

int ordered_ins(struct node **start, int x, int r, int c)
{
    struct node *p, *q;
    p = (*start);
    q = NULL;
    while ((p != 0) && (p->row) <= r)
    {
        q = p;
        p = p->next;
    }
    if (q == 0)
        insbeg(&(*start), x,r,c);
    else
        insaft(&q, x,r, c);
}
int traverse(struct node **q)
{

    struct node *p;
    p = (*q);
    while (p != NULL)
    {

        cout<<p->row<<" |  "<<p->clm <<"     |  "<< p->info <<endl;
        p = p->next;
    }
}
int main()
{
    struct node*start;
    start=0;

    int n;
    cin >> n;
    vector<int> m[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            m[i].push_back(x);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] != 0)
            {
                ordered_ins(&start,m[i][j],i,j);
            }
        }
    }
    cout<<"Row"<<" "<<"Column"<<" "<<"Data"<<endl;
    traverse(&start);
}