#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//数组中的第k个最大元素(快速排序)

/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/

int* array;
void swap(int *nums, int i,int j);
int randomPartition(int left , int right);
int quickSelect(int left, int right, int index);

int findKthLargest(int* nums, int numsSize, int k){
    array = nums;
    return quickSelect(0, numsSize - 1, numsSize - k);
}

int quickSelect(int left, int right, int index) {
    //! 找到分区点
    int q = randomPartition(left,right);
    if (q == index) {
        printf("%d",array[q]);
        return array[q];    
    } 
    else {
      return q < index ? quickSelect(q+1, right, index) : quickSelect(left, q-1, index);
    }

}

//! 以 区间最后一个元素为锚点，依次进行比对分割，左侧比锚点小，右侧比锚点大
int randomPartition(int left , int right)  {
    if (left >= right) {
      return left;
    }
    //! 参考值
    int x = array[right];
    //! 分区边界, i 是第一个不小于 x 的坐标，也就是左边界
    int i = left;
    for (int j = left; j < right; ++j) {
      if (array[j] < x) {
        swap(array, i, j);
        i += 1;
      }
    }
    //! 最后 将 参考值 替换
    swap(array, i, right);
    return i;
}

void swap(int *nums, int i,int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}


int main()
{
    int array[6] ={3,2,1,5,6,4};
   
    findKthLargest(array,6,2);
   
}