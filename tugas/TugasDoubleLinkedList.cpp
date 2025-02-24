#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int angka;
    struct tnode *next;
    struct tnode *prev;
} *head, *tail;

struct tnode *createNode(int value){
    struct tnode *newNode = (struct tnode*)malloc(sizeof(struct tnode));
    newNode->angka = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void push_front(int value){
    struct tnode *temp = createNode(value);
    
    if(!head){
        head = tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void push_back(int value){
    struct tnode *temp = createNode(value);
    
    if(!head){
        head = tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void push_mid(int value){
    struct tnode *temp = createNode(value);
    if(!head){
        head = tail = temp;
        return;
    }

    struct tnode *slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = slow;
    temp->prev = slow->prev;

    if(slow->prev){
        slow->prev->next = temp;
    } else {
        head = temp; 
    }
    slow->prev = temp;
}

void del_front(){
    if(!head){
    	return;
	}

    struct tnode *temp = head;
    if(head == tail){
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}

void del_back(){
    if(!head){
    	return;
	}
	
    struct tnode *temp = tail;
    if(head == tail){
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

void del_mid(){
    if(!head){
    	return;
	}

    struct tnode *slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    if(slow->prev) slow->prev->next = slow->next;
    if(slow->next) slow->next->prev = slow->prev;

    if(slow == head) head = slow->next;
    if(slow == tail) tail = slow->prev;

    free(slow);
}

void print(){
    struct tnode *curr = head;
    while(curr){
        printf("%d ", curr->angka);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    push_front(5);
    push_front(3);
	del_front();
//	print();
	push_back(19);
	push_mid(10);
	push_front(7);
	push_back(22);
	push_front(11);
	push_mid(71);
	del_back();
//	print();
	del_mid();
	push_mid(66);
    print();
    return 0;
}

