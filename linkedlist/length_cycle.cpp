#include "mylinked.h"
void loop(int x,int y)
{
    int c=0,c1=0;
    struct node *p, *q;
    p = start;
    q = start;
    while (p->next != 0)
    {  
        c++;
        if(c==y)
          break;
        p = p->next;

    }
    while (q->next != 0)
    {
        c1++;
        if(c1==x)
        break;
        q = q->next;
    }
    p->next = q;

}

void cycle()
{
    struct node *t, *r;
    int c=0;
    t = start;
    r = start->next;
    while (r != 0 && r->next != 0)
    {
        t = t->next;
        r = r->next;
        r = r->next;
        if (r == t)
        {
            break;
        }
    }

   do
   {
       c++;
       t = t->next;
   }
   while(t!=r);
   cout<<c<<endl;

   
}

int main()
{
    int a[5] = {20, 30, 40, 50, 60};
    for (int i = 0; i < 5; i++)
    {
        insbeg(a[i]);
    }
    traverse();
    loop(3,6);
    cycle();
   
}