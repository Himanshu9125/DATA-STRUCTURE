#include"mylinked.h"
void loop(int x){
    struct node *p,*q;
    int c=0;
    p=start;
    q=start;
    while (p->next != 0)
    {
      p=p->next;   
    }
    while (q->info!=x)
    {
        q=q->next;
          
    }
    p->next=q;
}
    
void cycle(){
    struct node *t, *r;
    t = start;
    r = start->next;
    while (r != 0 && r->next != 0)
    {
        t = t->next;
        r = r->next;
        r=r->next;
        if(r==t){
        cout<<"yes cyclic"<<endl;
        break;
        }
    }
    if((r==0 )|| (r->next == 0))
     cout<<"NO"<<endl;
}


int main(){
    int a[5] = {20, 30, 40, 50, 60};
    for (int i = 0; i < 5; i++)
    {
        insbeg(a[i]);
    }
    loop(30);
    cycle();
}