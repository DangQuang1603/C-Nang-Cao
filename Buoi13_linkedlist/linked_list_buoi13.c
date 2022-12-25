#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

//khởi tạo node
struct Node
{
    uint8_t data;
    struct Node *next;
};

// định nghĩa lại node dưới dạng con trỏ
typedef struct Node *typeofnode;

// hàm tạo thêm node
typeofnode createnode(uint8_t value){
    typeofnode temp;
    temp = (typeofnode)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

//hàm check size linked list
uint8_t size (typeofnode head){
    uint8_t i = 0;
    typeofnode p = head;
    if(head == NULL)
    {
        return 0;
    }else{
        while (p->next != NULL)
        {
            p = p->next;
            i++;
        }
        return i+1;
    }
}

//hàm tạo node và liên kết các node lại
void push_back(typeofnode *head, uint8_t value){
    static uint8_t checkhead = 1;
    if (checkhead){
        *head = NULL;
        checkhead = 0;
    }
    typeofnode temp = createnode(value);
    typeofnode p = NULL;
    if (*head  == NULL)
    {
        *head = temp;
    }else{
        p = *head;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }

}

// lấy giá trị của node chỉ định
int get (typeofnode head, uint8_t index){
    uint8_t i = 0;
    typeofnode p = head;
    while (p->next != NULL && i != index){
        p = p->next;
        i++;
    }
    return p->data;
}

//xóa node cuối cùng
void pop_back (typeofnode *head){
    typeofnode p = NULL;
    typeofnode last = NULL;
    if(*head == NULL){
        printf("Linked lists is empty!\n");
    }else{
        p = *head;
        while(p->next != NULL){
            last = p;
            p = p->next;
        }
        free(p);
        last->next = NULL;
    }
}

// chèn thêm node vào vị trí chỉ định
void insert (typeofnode *head, uint8_t pos, uint8_t value){
    uint8_t i = 0;
    typeofnode temp = createnode(value);
    typeofnode p = *head;
    while (p->next != NULL && i!= pos-1 ){
        p = p->next;
        i++;
    }
    temp->next = p->next;
    p->next = temp;
}

// xóa node chỉ định
void erase(typeofnode *head, uint8_t pos){
    uint8_t i = 0;
    typeofnode pre = NULL;
    typeofnode p = *head;
    while (p->next != NULL && i != pos){
        pre = p;
        p = p->next;
        i++;
    }
    pre->next = p->next;
    free(p);
}

int main (){
    typeofnode head = NULL;// khởi tạo linked list

    printf("size = %d\n", size(head)); // check size lúc node là null = 0

    pop_back(&head);// xóa node cuối nhưng linked list rỗng 

    push_back(&head, 8); //tạo node đầu = 8
    push_back(&head, 100);//tạo node thứ hai = 100
    push_back(&head, 10);//tạo node thứ ba = 10
    push_back(&head, 20);//tạo node thứ tư = 20
    push_back(&head, 30); //tạo node thứ năm = 30          

    printf("LL[0] %d\n", get(head, 0)); //in ra node đầu = 8
    printf("LL[1] %d\n", get(head, 1)); //in ra node thứu hai = 100
    printf("LL[2] %d\n", get(head, 2)); //in ra node thứu ba = 10
    printf("LL[3] %d\n", get(head, 3)); //in ra node thứu tư = 20
    printf("LL[4] %d\n", get(head, 4)); //in ra node thứu năm = 30

    insert(&head, 2, 99); // chèn thêm node tại vị trí thứ 2
    printf("\n");

    printf("LL[0] %d\n", get(head, 0)); //in ra node đầu = 8
    printf("LL[1] %d\n", get(head, 1)); //in ra node thứu hai = 100
    printf("LL[2] %d\n", get(head, 2)); //in ra node thứu ba = 99
    printf("LL[3] %d\n", get(head, 3)); //in ra node thứu tư = 10
    printf("LL[4] %d\n", get(head, 4)); //in ra node thứu năm = 20
    printf("LL[5] %d\n", get(head, 5)); //in ra node thứu sáu = 30

    erase(&head, 2); // xóa node thứ 2
    printf("\n");

    printf("LL[0] %d\n", get(head, 0)); //in ra node đầu = 8
    printf("LL[1] %d\n", get(head, 1)); //in ra node thứu hai = 100
    printf("LL[2] %d\n", get(head, 2)); //in ra node thứu ba = 10
    printf("LL[3] %d\n", get(head, 3)); //in ra node thứu tư = 20
    printf("LL[4] %d\n", get(head, 4)); //in ra node thứu năm = 30
    printf("LL[5] %d\n", get(head, 5)); //in ra node thứu sáu = 30 (vì linked list chiwr có 5 phần tử nên sẽ in phần tử thứ 5)

    printf("size = %d\n", size(head)); //check size

}