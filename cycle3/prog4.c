#include<stdio.h>
#include<stdlib.h>

int top = -1,tempTop = -1,size;
int ar[30],temp[30];

void push(int ar[],int temp[]){
	if (top == size - 1){
		printf("Stack is full\n");
	}else{
		int data;
		printf("Enter data to push : ");
		scanf("%d",&data);
		while((ar[top] < data) && (top != -1)){
			temp[++tempTop] = popStack();
		}
		ar[++top] = data;
		while(tempTop > -1){
			ar[++top] = popTemp();
		}
	}
}

int popStack(){
	if (top == -1){
		printf("Stack is empty\n");
	}else{
		return ar[top--];
	} 
}

int popTemp(){
	if (tempTop == -1){
		printf("Stack is empty\n");
	}else{
		return temp[tempTop--];
	} 
}


void display(){
	if (top == -1){
		printf("Stack is empty\n");
		return;
	}
	for (int i = top; i >= 0; i--){
		printf("%d\t",ar[i]);
	}
	printf("\n");
}

int main(){
	int ch;
	printf("Enter size of stack : ");
	scanf("%d",&size);
	while(1){
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nChoose an option : ");
		scanf("%d",&ch);
		if (ch == 1){
			push(ar,temp);
		}else if (ch == 2){
			printf("Popped data is %d\n",popStack());
		}else if (ch == 3){
			display();
		}else if (ch == 4){
			exit(0);
		}
	}
	return 0;
}