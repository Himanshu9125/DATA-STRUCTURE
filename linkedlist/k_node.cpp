#include "mylinked2.h"

int kth_node_end(struct node **start, int idx)
{
    int c = 0, x, y;
    x = count(&(*start));
    struct node *p;
    p = (*start);
    if (p == NULL || x < idx)
    {
        cout << "no node exist" << endl;
    }
    else
    {
        while (p != 0)
        {
            c++;
            if (c == (x - idx) + 1)
            {
                y = p->info;
                cout << y << endl;
                break;
            }
            p = p->next;
        }
    }
}

int main()
{
    struct node *start;
    start = NULL;
    int idx;
    cin >> idx;
    insend(&start, 100);
    insend(&start, 200);
    insend(&start, 300);
    insend(&start, 400);
    insend(&start, 500);
    insend(&start, 700);
    insend(&start, 10);
    insend(&start, 20);
    insend(&start, 30);
    traverse(&start);
    cout<<endl;
    cout << "Now =>"<< " ";
    kth_node_end(&start, idx);
    return 0;
}