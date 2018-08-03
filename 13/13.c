#include "stdio.h"

int romanNumber(char* s){
    char pre=0,cur=0;
    int sum=0;

    for(int i=0;s[i]!='\0';i++){
        pre=cur;
        cur=s[i];
        printf("pre=%c,cur=%c,sum=%d\n",pre,cur,sum);

        switch(cur){
            case 'M':
                if(pre=='C'){
                    sum+=(1000-100-100);//C多加了一次,下同
                }else{
                    sum+=1000;
                }
                break;
            case 'D':
                if(pre=='C'){
                    sum+=(500-100-100);
                }else{
                    sum+=500;
                }
                break;
            case 'C':
                if(pre=='X'){
                    sum+=(100-10-10);
                }else{
                    sum+=100;
                }
                break;
            case 'L':
                if(pre=='X'){
                    sum+=(50-10-10);
                }else{
                    sum+=50;
                }
                break;
            case 'X':
                if(pre=='I'){
                    sum+=(10-1-1);
                }else{
                    sum+=10;
                }
                break;

            case 'V':
                if(pre=='I'){
                    sum+=(5-1-1);
                }else{
                    sum+=5;
                }
                break;

            case 'I':
                sum+=1;
                break;
        }
    }
    return sum;
}

int main(){
    char *romanNumbers="MMCCCXLV";
    int result=romanNumber(romanNumbers);

    printf("\nresult=%d\n",result);
}
