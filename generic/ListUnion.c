/* Write a c program to create 2 singly linkedlist consisting of numbers. Perform union and intersection of the two linked list and sort the
output of union of linked list using selection sort.	*/

#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int data;
	struct Node *link;
}Node;
typedef struct{
	struct Node *head;
}Sll;
void insert(Sll *list,int data){
	Node *new = (struct Node*) malloc(sizeof(Node));
	new -> data = data;
	new -> link = NULL;
	if (list -> head == NULL){
		list -> head = new;
	}else{
		Node *temp = list -> head;
		while(temp -> link != NULL){
			temp = temp -> link;
		}
		temp -> link = new;
	}
}

void display(Sll *list){
	if (list -> head != NULL){
		Node *temp = list -> head;
		while(temp != NULL){
			printf("%d\t",temp -> data);
			temp = temp -> link;
		}
		printf("\n");
	}else{
		printf("List is empyt\n");
	}
}

int isPresent(Sll *s,int data){
	Node *temp = s -> head;
	while(temp != NULL){
		if(temp -> data == data){
			return 1;
		}
		temp = temp -> link;
	}
	return 0;
}

Sll createUnion(Sll *s1,Sll *s2){
	Sll result;
	result.head = NULL;
	Node *temp1 = s1 -> head;
	Node *temp2 = s2 -> head;

	while(temp1 != NULL){
		insert(&result,temp1 -> data);
		temp1 = temp1 -> link;
	}

	while(temp2 != NULL){
		if ( !isPresent(&result,temp2 -> data)){
			insert(&result,temp2 -> data);
		}
		temp2 = temp2 -> link;
	}
	return result;
}

Sll createIntersection(Sll *s1,Sll *s2){
	Sll result;
	result.head = NULL;
	Node *temp1 = s1 -> head;

	while(temp1 != NULL){
		if (isPresent(s2,temp1 -> data)){
			if(!isPresent(&result,temp1 -> data)){
				insert(&result,temp1 -> data);
			}
		}
		temp1 = temp1 -> link;
	}
	return result;
}

void swap(Node *first,Node *second){
	int temp = first -> data;
	first -> data = second -> data;
	second -> data = temp;
}

void sortList(Sll *list){
	Node *temp = list -> head;
	while (temp != NULL){
		int min = temp -> data;
		for (Node *i = temp; i != NULL; i = i -> link){
			if (i -> data < min){
				swap(i,temp);
			}
		}
		temp = temp -> link;
	}
}

int main(){
	Sll list1,list2,unionList,intersection;
	list1.head = NULL;
	list2.head = NULL;
	//head1 = NULL;
	insert(&list1,30);
	insert(&list1,20);
	insert(&list1,10);
	insert(&list1,50);

	insert(&list2,40);
	insert(&list2,30);
	insert(&list2,60);
	insert(&list2,10);
	unionList = createUnion(&list1,&list2);
	intersection = createIntersection(&list1,&list2);
	printf("Union list is\n");
	display(&unionList);
	printf("intersection list is\n");
	display(&intersection);

	sortList(&unionList);
	printf("Sorted unionList is\n");
	display(&unionList);

	return 0;
}
