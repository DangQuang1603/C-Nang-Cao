#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void Array_input(uint8_t**ptr, uint8_t *lenght){
    printf("Nhap kich thuoc mang: ");
    scanf("%d", lenght);
    *ptr = (uint8_t*)malloc(*lenght*sizeof(uint8_t));

    for (int i = 0; i < *lenght; i++){
        printf("a[%d] = ",i);
        scanf("%d", ptr + i);
    }
}

void Array_output(uint8_t **arr, uint8_t lenght){
    printf("\n");
    for(int i = 0; i < lenght; i++){
        printf("a[%d] = %d\n",i, *(arr+i));
    }
}

void sort_mintomax (uint8_t **arr, uint8_t lenght){
    uint8_t checkcomplete;
    for(int i = 0; i < lenght; i++){
        for(int j = 0; j < lenght; j++){
            if(*(arr+j) > *(arr + i)){
                uint8_t temp = *(arr+j);
                *(arr+j) = *(arr + i);
                *(arr + i) = temp;
            }
        }
    }
}

void sort_maxtomin (uint8_t **arr, uint8_t lenght){
    uint8_t checkcomplete;
    for(int i = 0; i < lenght; i++){
        for(int j = 0; j < lenght; j++){
            if(*(arr+j) < *(arr + i)){
                uint8_t temp = *(arr+j);
                *(arr+j) = *(arr + i);
                *(arr + i) = temp;
            }
        }
    }
}



int main(){
    int *arr;
    int lenght;
    printf("------NHAP MANG------\n");
    Array_input(&arr, &lenght);
    printf("------SAP XEP BE DEN LON------\n");
    sort_mintomax(&arr, lenght);
    Array_output(&arr,lenght);
    printf("------SAP XEP LON DEN BE------\n");
    sort_maxtomin(&arr, lenght);
    Array_output(&arr,lenght);
}