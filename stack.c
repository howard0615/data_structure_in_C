/*
    stack
    Fisrt in Last out

    init
    isEmpty
    isFull
    push
    pop
    peek
*/

#include <stdio.h>
#include <stdlib.h>

#define DATA_MAX 50

typedef struct {
    int data[DATA_MAX];
    int top;
}Stack;


void init(Stack* s){
    s->top = -1;
}


int isEmpty(Stack* s){
    return s->top == -1;
}

int isFull(Stack* s){
    return s->top == DATA_MAX-1;
}

void push(Stack* s, int value){
    if(isFull(s)){
        printf("Stack is full!\n");
        return ;
    }
    s->data[++(s->top)] = value;
    return;
}

int pop(Stack* s){
    // pop out the top value, return the top value
    if(isEmpty(s)){
        printf("Stack is Empty!\n");
        return;
    }
    return s->data[(s->top)--];
}

int peek(Stack* s){
    // pop out the top value, return the top value
    if(isEmpty(s)){
        printf("Stack is Empty!\n");
        return;
    }
    return s->data[(s->top)];
}

int main(){
    Stack s;

    init(&s);

    push(&s, 10);
    push(&s, 20);

    int pop_value = pop(&s);


    return 0;
}