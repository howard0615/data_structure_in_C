#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    /* data */
    int val;
    struct Node* next;
} Node;


Node* createNode(int value){
    Node* lk = (Node*)malloc(sizeof(Node)*1);
    lk->val = value;
    lk->next = NULL;
    return lk;
}

// void add(Node* head, int value){
//     head->next = createNode(value);
// }

void printLinklist(Node* head){
    while(head!=NULL){
        printf(" %d ", head->val);
        head = head->next;
    }
    printf("\n");
}

Node* reverseLinklist(Node* head){
    if(head==NULL) return NULL;
    Node* prev_node = NULL;
    while(head!=NULL){
        Node* next_node = head->next;
        head->next = prev_node;
        prev_node = head;
        head = next_node;
    }
    return prev_node;
}

Node* reverse_recursive_Linklist(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* prev_node = reverse_recursive_Linklist(head->next);
    head->next->next = head;
    head->next = NULL;

    return prev_node;
}


int main(){
    Node* head = createNode(0);;
    Node* ptr = head;
    for(int i=1; i<10; i++){
        ptr->next = createNode(i);
        ptr = ptr->next;
    }
    
    printLinklist(head);
    Node* reverse_list = reverseLinklist(head);
    printLinklist(reverse_list);
    Node* recursive_list = reverse_recursive_Linklist(reverse_list);
    printLinklist(recursive_list);
    
    return 0;
}