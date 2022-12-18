#include<stdio.h>
int main(){
	int size;
	printf("Enter size of array : ");
	scanf("%d",&size);
	int ar[size];
	printf("Enter array elemets\n");
	for (int i = 0; i < size; i++){
		scanf("%d",&ar[i]);
	}
	int element;
	printf("Enter element to search : ");
	scanf("%d",&element);
	for(int i = 0; i < size; i++){
		if (ar[i] == element){
			printf("element found at index %d",i + 1);
			return 0;
		}
	}
	printf("Element not found");
	return 0;
}