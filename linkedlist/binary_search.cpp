#include "mylinked2.h"
struct node* middle(struct node **start)
{
    struct node *t, *r;
    t = (*start);
    r = (*start)->next;
    while (r != 0 && r->next != 0)
    {
        t = t->next;
        r = r->next->next;
    }
    //cout<<t->info<<endl;
   return t;
}
struct node* binary(struct node **start,int x){ 
    struct node*p,*q; 
    q=(*start);  
    while((*start)->next!=0){
        p = middle(&(*start));
        if (p->info == x)
            return p;
        else if (p->info > x)
            p->next = NULL;
        else{
           (*start) = p->next;
        }
      
    }
     if((*start)->info==x)
       return ((*start));
    else
       return NULL;

}

int main()
{
    struct node *start,*p;
    start = NULL;
    //int idx;
    //cin >> idx;
    ordered_ins(&start, 100);
    ordered_ins(&start, 200);
    ordered_ins(&start, 300);
    ordered_ins(&start, 400);
    ordered_ins(&start, 500);
    ordered_ins(&start, 700);
    ordered_ins(&start, 10);
    ordered_ins(&start, 20);
    ordered_ins(&start, 30);
    traverse(&start);
    cout<<endl;
    cout << "Now =>" << " ";
     p= binary(&start,700);
     cout<<p->info<<" data found"<<endl;
}