#include<stdio.h>
typedef struct{
	int coef;
	int exp;
}Poly;
int main(){
	int size1,size2;
	printf("Enter the size of polynomial 1 ");
	scanf("%d",&size1);
	printf("Enter the size of polynomial 2 ");
	scanf("%d",&size2);
	Poly p1[size1],p2[size2],sum[size1 + size2];

	printf("Enter the elements in polynomial 1 ");
	for (int i = 0; i < size1; i++){
		scanf("%d %d",&p1[i].coef,&p1[i].exp);
	}

	printf("Enter the elements in polynomial 2 ");
	for (int i = 0; i < size2; i++){
		scanf("%d %d",&p2[i].coef,&p2[i].exp);
	}


	printf("\nPolynomial 1 is \n");
	for (int i = 0; i < size1; i++){
		if (i == 0){
			printf("%dX^%d",p1[i].coef,p1[i].exp);
		}else{
			printf("+%dX^%d",p1[i].coef,p1[i].exp);
		}
	}

	printf("\nPolynomial 2 is \n");
	for (int i = 0; i < size2; i++){
		if(i == 0){
			printf("%dX^%d",p2[i].coef,p2[i].exp);
		}else{
			printf("+%dX^%d",p2[i].coef,p2[i].exp);
		}
	}

	int i = 0, j = 0, k = 0;
	while(i < size1 && j < size2){
		if (p1[i].exp < p2[j].exp){
			sum[k].exp = p2[j].exp;
			sum[k].coef = p2[j].coef;
			k++;
			j++;
		}else if (p1[i].exp > p2[j].exp){
			sum[k].exp = p1[i].exp;
			sum[k].coef = p1[i].coef;
			j++;
			i++;
		}else{
			sum[k].exp = p1[i].exp;
			sum[k].coef = p1[i].coef + p2[j].coef;
			j++;
			k++;
			i++;
		}
	}
	while(i < size1){
		sum[k].coef = p1[i].coef;
		sum[k].exp = p1[i].exp;
		i++;
		k++;
	}
	while(j < size2){
		sum[k].coef = p2[j].coef;
		sum[k].exp = p2[j].exp;
		j++;
		k++;
	}

	printf("\nSum of polynomial is \n");
	for (int i = 0; i < k; i++){
		if (i == 0){
			printf("%dX^%d",sum[i].coef,sum[i].exp);
		}else{
			printf("+%dX^%d",sum[i].coef,sum[i].exp);
		}
	}

	return 0;

}