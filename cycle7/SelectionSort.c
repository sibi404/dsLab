#include<stdio.h>
int size;

void readArray(int ar[]){
	printf("Enter the elements\n");
	for (int i = 0; i < size; i++){
		scanf("%d",&ar[i]);
	}
}

void selectionSort(int ar[]){
	for (int i = 0; i < size -1; i++){
		for(int j = i + 1; j < size; j++){
			if (ar[i] > ar[j]){
				int temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
	}
}

void printAarray(int ar[]){
	for (int i = 0; i < size; i++){
		printf("%d\t",ar[i]);
	}
	printf("\n");
}
int main(){
	printf("Enter the number of elements : ");
	scanf("%d",&size);
	int ar[size];
	readArray(ar);
	printf("Array before sorting\n");
	printAarray(ar);
	selectionSort(ar);
	printf("Array after sorting\n");
	printAarray(ar);
	return 0;
}