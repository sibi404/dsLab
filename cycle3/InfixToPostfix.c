#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 20
char expr[MAX_SIZE],result[MAX_SIZE],stack[MAX_SIZE];
int top = -1;


int operatiorPrecedence(char a){
	if (a == '+' || a == '-'){
		return 1;
	}else if (a == '*' || a == '/'){
		return 2;
	}else if(a == '^'){
		return 3;
	}else{
		return 0;
	}
}

int isOperant(char a){
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || isdigit(a)){
		return 1;
	}else{
		return 0;
	}
}

void convertInfixPostfix(char ar[]){
	int j = 0;
	for (int i = 0; ar[i] != '\0'; i++){
		if (isOperant(ar[i])){
			result[j++] = ar[i];
		}else if (ar[i] == '('){
			stack[++top] = ar[i];
		}else if(ar[i] == ')'){
			while(stack[top] != '('){
				result[j++] = stack[top--];
			}
			top--;
		}else{
			if((top == -1) || (stack[top] == '(') || (operatiorPrecedence(ar[i]) > operatiorPrecedence(stack[top]))){
				stack[++top] = ar[i];
			}else{
				while(stack[top] != '(' && top != -1 && operatiorPrecedence(ar[i]) <= operatiorPrecedence(stack[top])){
					result[j++] = stack[top--];
				}
				stack[++top] = ar[i];
			}
		} 
	}
	while(top != -1){
		result[j++] = stack[top--];
	}	
}

int main(){
	printf("Enter expression : ");
	gets(expr);
	printf("Infix expression : %s\n",expr);
	convertInfixPostfix(expr);
	printf("Postfix expression : %s\n",result);
	return 0;
}