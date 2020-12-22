#include <stdio.h>
#include <stdlib.h>

struct Node{
    int angka;
    Node *next;
}*head,*tail;


Node *createNode(int angka){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->angka = angka;
    return newNode; 
}

void pushHead(int angka){
    Node *temp = createNode(angka);

    if(!head){
        head = tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void pushTail(int angka){
    Node *temp = createNode(angka);
    if(!head){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail =temp;
    }
}

void popHead(){
    if(!head){
        return;
    }
    else{
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
}

void popTail(){
    if(!head){
        return;
    }
    else{
        Node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

void printList(){
    Node *curr = head;
    while(curr){
        printf("%d\n",curr->angka);
        curr = curr->next;
    }
}

int main(){
    int angka1[] = {1,2,3,4,5,6,2,3,4,5};
    int hapus;
    int index = 10;
    if(index % 2 == 0){
        hapus = (index / 2) - 1;
        
    }
    else{
        hapus = index/2;
    }    
    int sudah = hapus;  
    
    for(int i = 0 ; i < index ; i++){
        pushTail(angka1[i]);
    }
    while(sudah > 0){
        popHead();
        popTail();
        sudah--;
    }
    printList();   
    return 0;
}