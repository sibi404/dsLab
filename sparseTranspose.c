#include<stdio.h>
typedef struct{
	int row;
	int col;
	int value;
}Sparse;

int main(){
	int nonZero,row,column;
	printf("Enter number of non zero values ");
	scanf("%d",&nonZero);
	printf("Enter the number of rows and column ");
	scanf("%d %d",&row,&column);
	Sparse matrix[nonZero];
	Sparse transpose[nonZero];
	matrix[0].row = row;
	matrix[0].col = column;
	matrix[0].value = nonZero;

	printf("Enter matrix\n");
	for (int i = 1; i < nonZero + 1; i++){
		scanf("%d %d %d",&matrix[i].row,&matrix[i].col,&matrix[i].value);
	}

	printf("Matrix is \n");
	for (int i = 0; i < nonZero + 1; i++){
		printf("%d\t%d\t%d\n",matrix[i].row,matrix[i].col,matrix[i].value);
	}

	

}