#include<stdio.h>
#include<stdlib.h>
int size,front= -1,rear = -1;
void enqueue(int ar[]){
	if (rear == size-1){
		printf("Queue is full\n");
		return;
	}
	int data;
	printf("Enter data to enqueue : ");
	scanf("%d",&data);
	if(front == -1 && rear == -1){
		rear = 0;
		front = 0;
		ar[rear] = data;
	}else{
		rear++;
		ar[rear] = data;
	}
	
	
}

void dequeue(int ar[]){
	if (front == -1 || front > rear){
		printf("Queue is empyt\n");
	}else if (front == rear){
		printf("Deleted data is %d",ar[front]);
		front = rear = -1;
	}else{
		printf("Deleted data is %d\n",ar[front]);
		front++;
	}
}

void display(int ar[]){
	if (front == -1 && rear == -1){
		printf("Queue is empyt\n");
	}else if (front <= rear){
		for (int i = front; i <= rear; i++){
			printf("%d\t",ar[i]);
		}
		printf("\n");
	}
}

int main(){
	printf("Enter size of queue : ");
	scanf("%d",&size);
	int arr[size],ch;
	while(1){
		printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\nSelect an option : ");
		scanf("%d",&ch);
		if (ch == 1){
			enqueue(arr);
		}else if (ch == 2){
			dequeue(arr);
		}else if(ch == 3){
			display(arr);
		}else if (ch == 4){
			exit(0);
		}else{
			printf("Select correct option\n");
		}
	}
	return 0;
}