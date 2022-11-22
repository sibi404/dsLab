#include<stdio.h>
typedef struct{
	int row;
	int col;
	int value;
}Sparse;
int main(){
	int nonZero1,nonZero2;
	printf("Enter no.of non zero elements in the matrixes ");
	scanf("%d %d",&nonZero1,&nonZero2);
	Sparse m1[nonZero1 + 1],m2[nonZero2 + 1],sum[nonZero1 + nonZero2];
	printf("Enter the elements of matrix 1 \n");
	for(int i = 0; i < nonZero1 + 1; i++){
		scanf("%d %d %d",&m1[i].row,&m1[i].col,&m1[i].value);
	}
	printf("Enter the elements of matrix 2\n");
	for (int i = 0; i < nonZero2 + 1; i++){
		scanf("%d %d %d",&m2[i].row,&m2[i].col,&m2[i].value);
	}


	if (m1[0].row != m2[0].row || m1[0].col != m2[0].col){
		printf("Addition is not possible ");
		return 0;
	}

	sum[0].row = m1[0].row;
	sum[0].col = m1[0].col;

	int m1Index = 1,m2Index = 1,sumIndex = 1;
	for (int i = 0; i < m1[0].row; i++){
		for(int j = 0; j < m1[0].col; j++){
			if (m1[m1Index].row == i && m1[m1Index].col == j && m2[m2Index].row == i && m2[m2Index].col == j){
				sum[sumIndex].row = i;
				sum[sumIndex].col = j;
				sum[sumIndex].value = m1[m1Index].value + m2[m2Index].value;
				m1Index++;
				m2Index++;
				sumIndex++;
			}else if(m1[m1Index].row == i && m1[m1Index].col == j){
				sum[sumIndex].row = i;
				sum[sumIndex].col = j;
				sum[sumIndex].value = m1[m1Index].value;
				m1Index++;
				sumIndex++;
			}else if(m2[m2Index].row == i && m2[m2Index].col == j){
				sum[sumIndex].row = i;
				sum[sumIndex].col = j;
				sum[sumIndex].value = m2[m2Index].value;
				m2Index++;
				sumIndex++;
			}
		}
	}
	sum[0].value = sumIndex - 1;

	printf("Sum matrix is \n");

	for (int i = 0; i < sum[0].value + 1; i++){
		printf("%d %d %d\n",sum[i].row,sum[i].col,sum[i].value);
	}
}