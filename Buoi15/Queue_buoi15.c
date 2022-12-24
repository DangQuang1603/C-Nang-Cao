#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef uint8_t bool;

typedef struct 
{
    uint8_t size;
    uint8_t index;
    uint8_t *arr;
}Queue;

void createqueue (Queue *member, uint8_t size)
{
    member->index = 0;
    member->size = size;
    member->arr = (uint8_t*)malloc(size*sizeof(uint8_t));
}

//kiểm tra queue trống hay không
bool isEmpty(Queue emptycheck){
 if (emptycheck.index == 0)
 {
    return true;
 }else{
    return false;
 }
}

//kiểm tra queue đầy hay không
bool isFull(Queue checkfull){
    if(checkfull.index - checkfull.size >= 0)
    {
        return true;
    }else{
        return false;
    }

}

//kiểm tra kích thước queue
uint8_t size(Queue sizecheck){
    return sizecheck.index;
}

//thêm 1 phần tử vào cuối queue
void enqueue( Queue *input, uint8_t element){
    if (isFull(*input))
    {
        printf("Queue is full!\n");
    }else{
        input->arr[input->index] = element;
        input->index++;
    }

}

//trả về giá trị của phân tử đầu queue rồi nó trong queue (lùi index)
uint8_t dequeue(Queue *value){
    if(isEmpty(*value)){
        printf("Queue is emty!\n");
    }else{
        for (int i = 0; i < value->index; i++)
        {
            value->arr[i] = value->arr[i+1];
        }
        value->index--;
        value->arr[value->index] = "\0";
    }

}

//trả về giá trị phân tử đầu queue nhưng không xóa nó
uint8_t front(Queue front){
    return front.arr[0];
}

//trả về phần tử cuối queue nhưng không xóa nó
uint8_t rear(Queue rear){
    return rear.arr[rear.index-1];
}


int main()
{
    Queue queue;
    createqueue(&queue,5); // tạo queue với size = 5
    enqueue(&queue,6);  //thêm phần tử = 6 vào cuối queue
    enqueue(&queue,7);  //thêm phần tử =  7 vào cuối queue
    enqueue(&queue,8);  //thêm phần tử = 8 vào cuối queue
    enqueue(&queue,9);  //thêm phần tử = 9 vào cuối queue

    printf("%d\n",size(queue)); // return size và chỉ số rear = 4
    printf("%d\n",rear(queue)); // in ra phần tử ở đuôi queue = 9
    printf("%d\n",front(queue)); // in ra phần tử ở đầu queue = 6

    dequeue(&queue); // xóa phần tử ở đầu queue
    printf("%d\n",size(queue)); // return size và chỉ số rear = 3

    printf("%d\n",rear(queue)); //in ra phần tử ở đuôi queue = 9
    printf("%d\n",front(queue)); // in ra phần tử ở đầu queue = 7

    enqueue(&queue,20); // thêm phần tử = 20 vào cuối queue
    enqueue(&queue,50); // thêm phần tử = 50 vào cuối queue
    printf("%d\n",rear(queue)); //in ra phần tử ở đuôi queue = 50
    printf("%d\n",front(queue));// in ra phần tử ở đầu queue = 7


    enqueue(&queue,70); // thêm phần tử = 70 vào cuối queue nhung queue full
}
