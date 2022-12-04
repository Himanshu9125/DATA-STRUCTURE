#include"mylinked2.h"
void concatinate(struct node **start,struct node **start2){
    struct node *p;

    p=(*start);
     
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=(*start2);
  
     
    
}
int main(){
    struct node *start2=NULL;
    struct node *start = NULL;
    
    insbeg(&start,20);
    insbeg(&start, 30);
    insbeg(&start, 40);
    insbeg(&start2, 50);
    insbeg(&start2, 60);
    insbeg(&start2, 70);
    traverse(&start);
    cout<<endl;
    traverse(&start2);
    cout<<endl;
    concatinate(&start,&start2);
    traverse(&start);
}
