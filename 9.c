#include "stdio.h"
#include "math.h"

int palindrome(int x){
    int copyX=x;
    int res=0;

    while(copyX>0){
        res=res*10+copyX%10;
        copyX=copyX/10;
    }

    return x==res?1:0;
}

int main(){
    printf("is palindrome:%d\n",palindrome(12345));
    printf("is palindrome:%d\n",palindrome(12321));
    printf("is palindrome:%d\n",palindrome(12311));
    printf("is palindrome:%d\n",palindrome(-12311));
    printf("is palindrome:%d\n",palindrome(-12321));
    printf("is palindrome:%d\n",palindrome(-2147483648));
    printf("is palindrome:%d\n",palindrome(-2147447412));
    return 0;
}
