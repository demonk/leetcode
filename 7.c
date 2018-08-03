#include "stdio.h"
#include "math.h"

int reverse(int x){
    int copyX=abs(x);
    int result[32];
    int size=0;
    while(copyX>0){
        int num=copyX%10;
        copyX=copyX/10;
        result[size++]=num;
    }

    int ret=0;
    int i=0;
    while(size>0){
        ret+=(result[--size]*pow(10,i++));
    }
    return x<0?-ret:ret;
}

int main(){
    printf("%d\n",reverse(1534236469));
    return 0;
}
