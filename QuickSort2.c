#include<stdio.h>
#include<stdlib.h>
#define len 6
//双路 快速排序

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int quickSort2(int arr[],int l,int r){
    int p=rand()%(r-l+1)+l;
    swap(arr,l,p);/*随机一个位置作为标定点*/
    int i=l+1,j=r;/*除开标定点后分别从头和尾开始遍历*/
    while(1){
        while(i<=j&&arr[i]<arr[l]){
            i++;
        }
        while(i<=j&&arr[j]>arr[l]){
            j--;
        }
        if(i>=j){
            break;
        }
        swap(arr,i,j);
        i++;
        j--;
    }
    swap(arr,l,j);/*将标定点的数换回靠中间的位置后返回其位置*/
    return j;
}
void quickSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int p=quickSort2(arr,l,r);
    quickSort(arr,l,p-1);/*将数组划分成多个小区域*/
    quickSort(arr,p+1,r);
}
void show(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
        if((i+1)%10==0){
            printf("\n");
        }
    }
}
int main(){
   //创建一个数组
    int a[len] ={0};
    int i;

    //输入数字
    for(i =0; i < len; i++)
    {
        scanf("%d",&a[i]);
    }
    show(a,len);
    printf("\n\n\n");
    quickSort(a,0,len-1);
    show(a,len);
    return 0;
}