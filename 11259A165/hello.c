   #include <stdio.h>
#define SIZE 5
int queue [SIZE];
int front = 0;
int rear = 0;
void enqueue (int value){
if (rear == SIZE){
printf("Queue full\n");
}
else{
queue [rear++]=value;
printf("Enqueue :%d\n", value);
}
}
int dequeue(){
if (front == rear){
printf("Queue empty\n");
return-1;
}
else{
return queue[front++];
}
}
int main(){
enqueue(100);
enqueue(200);
enqueue(300);
printf("Dequeued:%d\n",dequeue());
printf("Dequeued:%d\n",dequeue());
return 0 ;
}
