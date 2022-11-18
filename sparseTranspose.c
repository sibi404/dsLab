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
	matrix[0].row = row;
	matrix[0].column = column;
	matrix[0].value = nonZero;

}