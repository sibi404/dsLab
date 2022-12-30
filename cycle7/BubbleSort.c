#include<stdio.h>
int size;


void printList(int ar[]){
	for (int i = 0; i < size; i++){
		printf("%d\t",ar[i]);
	}
	printf("\n");
}

void bubbleSort(int ar[]){
	for(int i = 0;i < size-1;i++){
		for(int j=0;j<size-i-1;j++ ){
			if (ar[j] > ar[j + 1]){
				int temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}
		printf("Iteration %d\n",i);
		printList(ar);
	}
}

int main(){
	printf("Enter no.of elements : ");
	scanf("%d",&size);
	int ar[size];
	printf("Enter the elements\n");
	for (int i = 0; i < size; i++){
		scanf("%d",&ar[i]);
	}
	printf("List before sorting\n");
	printList(ar);
	bubbleSort(ar);
	printf("List after sorting\n");
	printList(ar);
	return 0;
}