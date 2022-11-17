#include<stdio.h>
#include<math.h>
typedef struct{
	int exp;
	int coef;
}Poly;

int main(){
	int size,x,result = 0;
	printf("Enter the size of polynomial ");
	scanf("%d",&size);
	Poly p[size];
	printf("Enter elements of polynomial \n");
	for (int i = 0; i < size; i++){
		scanf("%d %d",&p[i].coef,&p[i].exp);
	}

	printf("The polynomial is \n");
	for (int i = 0; i < size; i++){
		if(i == 0){
			printf("%dX^%d",p[i].coef,p[i].exp);
		}else{
			printf("+%dX^%d",p[i].coef,p[i].exp);
		}
	}

	printf("\nEnter the value of X ");
	scanf("%d",&x);

	for (int i = 0; i < size; i++){
		result += p[i].coef * pow(x,p[i].exp);
	}


	printf("Result is %d",result);
	return 0;
}