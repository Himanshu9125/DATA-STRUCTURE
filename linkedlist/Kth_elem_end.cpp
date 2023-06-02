#include"mylinked2.h"

void Kth_element(struct node **start,int idx){
    struct node *p;
    p=(*start);
    int c =0;
    reverse(&(*start));
    p=(*start);
    while (p!=NULL)
    {
        c++;
        if(c==(idx-1)&& ((idx-1)!=1)){
          deleaft(&p);
        }
        else if((idx-1)==1 ){
            delbeg(&(*start));
        }
        p=p->next;

    }
    
}
int main()
{
    struct node *start;
    start = NULL;
    int k;
    cin>>k;
    insbeg(&start, 2);
    insaft(&start, 2);
    insaft(&start, 2);
    insaft(&start, 5);
    insaft(&start, 6);
    insaft(&start, 5);
    insaft(&start, 8);
    insaft(&start, 5);
    insaft(&start, 8);
    traverse(&start);
    cout << endl;
    Kth_element(&start,k);
    traverse(&start);
    return 0;
}