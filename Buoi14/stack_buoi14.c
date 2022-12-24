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
    uint8_t *array; 
}stacks;

void createstack(stacks *member, int size)
{
 member -> size = size; // khởi tạo size stack
 member -> index = 0; // khởi tạo index = 0
 member -> array = (uint8_t*)malloc(size * sizeof (uint8_t)); // gán cho array địa chỉ mản được tạo từ malloc
}

// kiểm tra size 
uint8_t size(stacks value)
{
 return value.index;
}

// kiểm tra stack trống
bool isEmpty(stacks value){
    if (value.index == 0)
    {
        return true;
    }else
    {
        return false;
    }
}

// kiểm tra stack đầy
bool isFull(stacks value){
    if (value.index - value.size >=0 )
    {
        return true;
    }else
    {
        return false;
    }
}

// truyền dữ liệu vào stack
void push(stacks *push, uint8_t element){
    if (isFull(*push))
    {
        printf("stack is full!\n");
    }
    else{
        push->array[push->index] = element;
        push->index++;
    }
}

// xóa phần tử cuối cùng trong stack
void pop(stacks *pop){
    if (isEmpty(*pop))
    {
        printf("Stack is empty!\n");
    }else
    {
        pop->index--;
        pop->array[pop->index] = "\0";

    }

}

// in ra phần tử cuối cùng trong stack
uint8_t top(stacks value){
    if (value.index == 0)
    {
        return 0;
    }else
    {
        return value.array[value.index-1]; 
    }
}


int main()
{
    stacks stack;
    createstack(&stack,5);

    printf("%d\n",top(stack));

    push(&stack,11);
    push(&stack,28);
    push(&stack,65);
    push(&stack,100);
    push(&stack,5);

    printf("%d\n",top(stack)); //in phần tử cuối = 5
    printf("%d\n",size(stack));// kiểm tra size = 5

    pop(&stack);
    pop(&stack);
    printf("%d\n",top(stack)); //in phần tử cuối = 65
    printf("%d\n",size(stack));// kiểm tra size = 3

}
