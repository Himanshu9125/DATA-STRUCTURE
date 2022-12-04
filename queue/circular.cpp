#include <bits/stdc++.h>
using namespace std;
#define size 10

struct Queue
{
    int item[size];
    int front;
    int rear;
};
int intialize(Queue *q)
{
    q->front = size-1;
    q->rear = size-1;
}

bool Isempty(Queue *q)
{
    if (q->rear == q->front ) 
    {
        return true;
    }
    else
        return false;
}
void enqueue(Queue *q, int x)
{
    if (((q->rear+1)%size)==q->front){
        cout << "QUEUE OVER FLOW" << endl;
        exit(1);
    }
    else
    {
        q->rear = (q->rear + 1)%size;
        q->item[q->rear] = x;
    }
}
int dequeue(Queue *q)
{
    int x;
    if (Isempty(q))

    {
        cout << "QUEUE UNDERFLOW" << endl;
    }
    q->front = (q->front + 1) % size;
    x = q->item[q->front];
    return x;
}
int main()
{
    struct Queue q;
    int x;
    intialize(&q);
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    enqueue(&q, 400);
    x = dequeue(&q);
    cout << x << endl;
    x = dequeue(&q);
    cout << x << endl;
    x = dequeue(&q);
    cout << x << endl;
    x = dequeue(&q);
    cout << x << endl;
    return 0;
}
