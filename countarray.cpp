#include<stdio.h>
#define max 200

void Array_input(int arr[], int &n)
{
    printf("Nhap kich thuoc mang: ");
    do
    {
        scanf("%d",&n);
        if (n <= 1 || n > max ) printf("\nNhap lai kich thuoc mang!");
    } while (n <= 1 || n > max);
    
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ",i);
        scanf("%d",&arr[i]);
    }

}

void Array_output (int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf ("\na[%d] = %d", i, arr[i]);
    }
}

void Array_sequency (int arr[], int n)
{
    int prevalue = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {

        if (arr[i] == prevalue)
        {
            count++;
        }
    }
    printf("\nPhan tu co gia tri %d, xuat hien %d lan!",prevalue,count);

    for (int i = 1; i < n; i++)
    {
        count = 1;
        for(int k = i - 1; k >= 0; k--)
        {
            if (arr[i] == arr[k])
            {
                count ++;
            }
        }
        if (count == 1)
        {
            prevalue = arr[i];
            for (int j = i+1; j < n; j++)
            {
                if (arr[j] == prevalue)
                {count++;}
            }
            printf("\nPhan tu co gia tri %d, xuat hien %d lan!",prevalue,count); 
        } 
    }
}

int main ()
{
    int n;
    int arr[max];
    printf("----Nhap mang----\n");
    Array_input(arr,n);
    printf("----Xuat mang----\n");
    Array_output(arr,n);
    printf("\n----Xu ly mang----\n");
    Array_sequency(arr,n);
}

