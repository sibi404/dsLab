#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int data;
	struct Node* link;
}Node;

typedef struct{
	Node *head;
}sll;

void push(sll *s){
	int data;
	Node* newNode = (Node*) malloc(sizeof(Node));
	printf("Enter data to push : ");
	scanf("%d",&data);
	newNode -> data = data;
	if (s -> head == NULL){
		s -> head = newNode;
		newNode -> link = NULL;
	}else{
		newNode -> link = s -> head;
		s -> head = newNode;
	}
}

void pop(sll *s){
	if (s -> head == NULL){
		printf("Stack is empty\n");
		return;
	}else{
		printf("Popped data is %d\n",s ->head -> data);
		s -> head = s -> head -> link;
	}
}

void display(sll *s){
	if (s -> head == NULL){
		printf("Stack is empty\n");
		return;
	}else{
		Node *ptr = s -> head;
		while (ptr != NULL){
			printf("%d\n",ptr -> data);
			ptr = ptr -> link;
		}
	}
}

int main(){
	int ch;
	sll list;
	list.head = NULL;
	while(1){
		printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nSelect an option : ");
		scanf("%d",&ch);
		if (ch == 1){
			push(&list);
		}else if (ch == 2){
			pop(&list);
		}else if (ch == 3){
			display(&list);
		}else if (ch == 4){
			exit(0);
		}
	}
	return 0;
}