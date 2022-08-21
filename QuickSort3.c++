#include <stdio.h>
#include <stdlib.h>

#define len 6
//三路快速排序


void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
 
void triSort(int *a, int low, int high){
    if(low >= high)return;
    int key = a[low];
    int i = low, j = low;
    int k = high;
    while( i <= k){
        if(a[i] < key)
        {
            i++;
            j++;
            swap(a,i, j);
        }
        else if(a[i] > key)
        {
            k--;
            swap(a,i,k);
        }
        else i++;
    }
    triSort(a, low, j);
    triSort(a, k + 1, high);
}
 
 
int main(){
    int n[12] = {5, 9, 0, 1, 6, 3, 8, 7, 2, 4, 4, 4};
    triSort(n, 0, 11);
    for(int i = 0; i < 12; i++){
        printf("%d",n[i]);
    }
    return 0;
}


