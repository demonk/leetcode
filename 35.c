#include "stdio.h"
#include "malloc.h"

int searchInsert(int* nums, int numsSize, int target) {
    int i=0;
    for(;i<numsSize;i++){
        if(target <= nums[i]){
            return i;
        }
    }

    return i;
}

int main(int argv,char* argc){
    int nums[]={1,3,5,6};
    int size=4;
    int target=7;
    printf("index=%d\n",searchInsert(nums,size,target));
    return 0;
}


