#include "stdio.h"
#include "malloc.h"

typedef int bool;
#define true 1
#define false 0

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize<=0||strs[0][0]=='\0'){
        return "";
    }

    int i=0,j=0;
    int stop=0;

    for(j=0;strs[0][j]!='\0';j++){
        for(i=0;i<strsSize;i++){
            if(strs[0][j]!=strs[i][j]){
                stop=1;
                break;
            }
        }

        if(stop){
            break;
        }
    }

    char* result=(char*)malloc(sizeof(char)*j);
    strncpy(result,strs[0],j);
    result[j]='\0';
    return result;
}

int main(int argv,char* argc){
    int strsSize=1;
    char* strs[]={"a"};
    char* result=longestCommonPrefix(strs,strsSize);
    printf("lpc=%s\n",result);
    return 0;
}
