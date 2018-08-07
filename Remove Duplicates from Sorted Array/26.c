#include "stdio.h"
#include "malloc.h"

//两件事
//1. 计算非重复数
//2. 调整重复项（基于原数组）
int removeDuplicates(int* nums, int numsSize) {
    int size=numsSize>0?1:0;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[size-1]){
            nums[size++]=nums[i];
        }
    }
    return size;
}

int main(int argv,char* argc){
    int nums[]={1,1,2};
    int size=3;
    int ret_size=removeDuplicates(nums,size);
    printf("size=%d\n",ret_size);

    for(int i=0;i<ret_size;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}


