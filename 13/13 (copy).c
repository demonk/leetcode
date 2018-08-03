#include "stdio.h"

int romanNumber(char* s){
    char pre=0,cur=0;
    int sum=0;

    for(int i=0;s[i]!='\0';i++){
        pre=cur;
        cur=s[i];
        printf("pre=%c,cur=%c\n",pre,cur);

        switch(cur){
            case 'M':
                if(pre==0||pre=='M'){
                    sum+=1000;
                }else if(pre=='C'){
                    sum+=(1000-100);
                }
                break;
            case 'D':
                if(pre==0||pre=='M'){
                    sum+=500;
                }else if(pre=='C'){
                    sum+=(500-100);
                }
                break;
            case 'C':
                if(pre==0 || pre=='D' || pre=='C'){
                    sum+=100;
                }else if(pre=='X'){
                    sum+=(100-10);
                }
                break;
            case 'L':
                if(pre==0 || pre=='C'){
                    sum+=50;
                }else if(pre=='X'){
                    sum+=(100-50);
                }
                break;
            case 'X':
                if(pre==0||pre=='L' || pre=='X'){
                    sum+=10;
                }else if(pre=='I'){
                    sum+=(10-1);
                }
                break;

            case 'V':
                if(pre==0||pre=='X'){
                    sum+=5;
                }else if(pre=='I'){
                    sum+=(5-1);
                }
                break;

            case 'I':
                if(pre==0||pre=='I'){
                    sum+=1;
                }
                break;
        }
    }
    return sum;
}

int main(){
    char *romanNumbers="MCMLXXXVI";
    int result=romanNumber(romanNumbers);

    printf("\nresult=%d\n",result);
}
