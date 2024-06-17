/*
    FIFO First In First Out

    init
    isFull
    isEmpty
    enqueue
    dequeue


    circul
*/

#define DATA_MAX 20

typedef struct 
{
    /* data */
    int data[DATA_MAX];
    int front;
    int end;
}queue;

void init(queue* q){
    q->front = -1;
    q->end = -1;
}

int isEmpty(queue* q){
    // front and end pointer are the same
    return q->front == q->end;
}

int isFull(queue* q){
    return (q->end+1)%DATA_MAX == q->front;
}

void enqueue(queue* q, int value){
    if(isFull(q)){
        printf("Queue is Full!\n");
        return;
    }
    q->front = ++(q->front) % DATA_MAX;
    q->data[q->front] = value;
}

int dequeue(queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }
    q->end = ++(q->end) % DATA_MAX;

    return q->data[q->end];
}

int main() {
    queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Elements: \n");

    while (!isEmpty(&q)) {
        printf("%d\n", dequeue(&q));
    }

    return 0;
}