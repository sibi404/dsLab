#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int top = -1,minTop = -1;

void push(int a[],int min[]){
	int data;
	printf("Enter the data to push : ");
	scanf("%d",&data);
	top++;
	a[top] = data;
	if (minTop == -1 || min[minTop] > data){
		minTop++;
		min[minTop] = data;
	}
}

void pop(int a[],int min[]){
	if (a[top] == min[minTop]){
		minTop--;
	}
	printf("Popped data is %d\n",a[top]);
	top--;
}

void display(int a[]){
	for (int i = top; i >= 0; i--){
		printf("%d\n",a[i]);
	}
	printf("\n");
}

int main(){
	int stack[MAX],min[MAX],ch;
	while(1){
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.Show minimum\n5.EXIT\nSelect an option : ");
		scanf("%d",&ch);
		if (ch == 1){
			if (top == MAX - 1){
				printf("Stack is full\n");
			}else{
				push(stack,min);
			}
		}else if (ch == 2){
			if (top == -1){
				printf("Stack is empty\n");
			}else{
				pop(stack,min);
			}
		}else if (ch == 3){
			if (top == -1){
				printf("Stack is empty\n");
			}else{
				display(stack);				
			}
		}else if (ch == 4){
			if (minTop == -1){
				printf("Stack is empty\n");
			}else{
				printf("min element is %d\n",min[minTop]);
			}
		}else if (ch == 5){
			exit(0);
		}else{
			printf("Choose correct option\n");
		}
	}
	return 0;
}