#include<stdio.h>
//颜色分类（力扣75）
/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，
使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

*/
void swap(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}

void sortColors(int *nums, int numsSize) {
    int p0 = 0, p1 = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 1) {
            swap(&nums[i], &nums[p1]);
            ++p1;
        } else if (nums[i] == 0) {
            swap(&nums[i], &nums[p0]);
            if (p0 < p1) {
                swap(&nums[i], &nums[p1]);
            }
            ++p0;
            ++p1;
        }
    }
}

void show(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
        if((i+1)%10==0){
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    int nums[6] = {2,0,2,1,1,0};
    show(nums,6);
    sortColors(nums,6);
    show(nums,6);
}