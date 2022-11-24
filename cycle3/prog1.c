#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int main(){
	int ch,value,stack[MAX],top = -1;
	while(1){
		printf("1.PUSH\n2.POP\n3.Display\n4.Exit\nSelect an option ");
		scanf("%d",&ch);
		if (ch == 1){
			if (top == MAX - 1){
				printf("Stack is full!\n");

			}else{
				top++;
				printf("Enter value to PUSH ");
				int value;
				scanf("%d",&value);
				stack[top] = value;
			}
		}else if (ch == 2){
			if (top == -1){
				printf("Stack is empyt!\n");
			}else{
				printf("Deleted data is %d\n",stack[top]);
				top--;
			}
		}else if (ch == 3){
			if (top == -1){
				printf("Stack is empyt!\n");
			}else{
				for (int i = top; i >= 0; i--){
					printf("%d\t",stack[i]);
				}
				printf("\n");
			}
		}else if (ch == 4){
			exit(0);
		}else{
			printf("Enter correct option\n");
		}
	}
	return 0;	
}