#include"mylinked.h"
int assending(){
  struct node *p,*q;
  int t;
  p=start;
  if(p==NULL)
    cout<<"list can't be arranged"<<endl;
  else{
    while (p!=0)
    {
        q=p;
        p=p->next;
        if((q->info)>(p->info)){
            t=p->next;
            p=q->next;
        }
    }
    
  }
}