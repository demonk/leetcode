
#include "stdio.h"
#include "malloc.h"

int* twoSum(int * nums,int numsSize,int target);
int main(int argv,char* argc){

    int nums[]={1,2,3,4,5};
    int* result=twoSum(nums,5,5);

    printf("result=%d,%d\n",result[0],result[1]);

    free result;
}

int* twoSum(int * nums,int numsSize,int target){
    int i,j;
    int* result=malloc(sizeof(int)*2);

    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
           if(nums[i]+nums[j]==target){
               result[0]=i;
               result[1]=j;
               return result;
           }
        }
    }
    return result;
}


