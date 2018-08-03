#include "stdio.h"
#include "malloc.h"

int* twoSum(int* numbers,int numberSize,int target,int* returnSize){
   int i=0,j=numberSize-1;
   int* result=malloc(sizeof(int)*2);

   for(;i<numberSize-1;i++){
       for(;j>i;j--){
           int ret=numbers[i]+numbers[j];
           if(ret==target){
               result[0]=i+1;
               result[1]=j+1;
               *returnSize=2;
               return result;
           }else if(ret<target){
               break;
           }else if(ret>target){
               //useless
               continue;
           }
       }
   }
   return result;
}


int main(int argv,char* argc){
    int nums[]={2,3,4};
    int size=3;
    int target=6 ;
    int* result=twoSum(nums,size,target);
    printf("result=%d,%d\n",result[0],result[1]);
    return 0;
}


