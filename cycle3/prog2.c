#include<stdio.h>
#include<stdlib.h>

void push(int ar[],int top){
	printf("Enter the value to push : ");
	scanf("%d",&ar[top]);
}

void display(int ar[],int top,int stack,int size){
	if (stack == 1){
		for (int i= top; i >= 0; i--){
			printf("\n%d",ar[i]);
		}
	}else if (stack == 2){
		for (int i = top; i < size; i++){
			printf("\n%d",ar[i]);
		}
	}
}

int main(){
	int size,ch;
	printf("Enter the size of  stack ");
	scanf("%d",&size);
	int ar[size],top1 = -1,top2 = size;
	while(1){
		printf("\n1.PUSH 1\n2.push 2\n3.POP 1\n4.POP 2\n5.DISPLAY 1\n6.DISPLAY 2\n7.EXIT\nChoose an option ");
		scanf("%d",&ch);
		if (ch == 1){
			if (top1 == top2 -1){
				printf("\nStack is full\n");
			}else{
				top1++;
				push(ar,top1);
			}
		}else if (ch == 2){
			if (top2 == top1 + 1){
				printf("\nStack is full\n");
			}else{
				top2--;
				push(ar,top2);
			}
		}else if (ch == 3){
			if (top1 == -1){
				printf("\nStack is empty\n");
			}else{
				printf("Poped data is %d ",ar[top1]);
				top1--;
			}
		}else if (ch == 4){
			if (top2 == size){
				printf("\nStack is empty\n");
			}else{
				printf("\nPoped data is %d\n",ar[top2]);
				top2++;
			}
		}else if (ch == 5){
			if (top1 == -1){
				printf("\nStack is empty\n");
			}else{
				display(ar,top1,1,size);
			}
		}else if (ch == 6){
			if (top2 == size){
				printf("\nStack is empty\n");
			}else{
				display(ar,top1,1,size);
			}
		}else if (ch == 7){
			exit(0);
		}
	}
	return 0;
}

// display(ar,top1,1,size);