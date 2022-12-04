#include "mylinked2.h"

void duplicte(struct node **start, struct node **start2)
{
    struct node *p;
    p = (*start);
    if (p == 0)
    {
        cout << "invalid list" << endl;
    }
    else
    {
        while (p != 0)
        {
            insend(&(*start2),p->info);
            p = p->next;
        }
    }
    cout << "copy of given list" << endl;
    traverse(&(*start2));
}
int main()
{
    struct node *start;
    start = NULL;
    struct node *start2;
    start2 = NULL;
    int idx, x;
    scanf("%d%d", &idx, &x);
    int a[] = {4, 5, 6, 8, 9,10,12,50,100};
    for (int i = 0; i <9  ; i++)
        insend(&start, a[i]);
    cout << "given list" << endl;
    traverse(&start);
    cout << endl;
    duplicte(&start, &start2);
}
