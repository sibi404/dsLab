#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int data;
	struct Node *link;
}Node;

typedef struct{
	Node *top;
}Sll;

Sll list;

void push(){
	Node* newNode = (Node*) malloc(sizeof(Node));
	int data;
	printf("Enter data to push : ");
	scanf("%d",&data);
	newNode -> data = data;
	if (list.top == NULL){
		list.top = newNode;
		newNode -> link = NULL;
	}else{
		newNode -> link = list.top;
		list.top = newNode;
	}
}

void pop(){
	if (list.top == NULL){
		printf("Stack is empty\n");
	}else{
		printf("Popped data is %d\n",list.top -> data);
		list.top = list.top -> link;
	}
}

void display(){
	if (list.top == NULL){
		printf("Stack is empty\n");
	}else{
		Node* ptr = list.top;
		while(ptr != NULL){
			printf("%d\t",ptr -> data);
			ptr = ptr -> link;
		}
		printf("\n");
	}
}

int main(){
	list.top = NULL;
	int ch;
	while(1){
		printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nChoose an option : ");
		scanf("%d",&ch);
		if (ch == 1){
			push();
		}else if(ch == 2){
			pop();
		}else if(ch == 3){
			display();
		}else if (ch == 4){
			exit(0);
		}else{
			printf("Select correct option\n");
		}
	}
	return 0;
}