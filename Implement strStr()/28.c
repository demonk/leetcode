#include "stdio.h"
#include "malloc.h"

int strStr(char* haystack, char* needle) {
    int i=0,j=needle[0]=='\0'?0:-1;
    
    for(i=0;haystack[i]!='\0';i++){
        for(j=0;needle[j]!='\0'&&haystack[i+j]!='\0';j++){
            if(haystack[i+j]!=needle[j]){
                break;
            }
        }
        if(needle[j]=='\0'){
            return i;
        }
    }

    //printf("i=%d,j=%d\n",i,j);
    return i==0?j:needle[0]=='\0'?0:-1;
}

int main(int argv,char* argc){

    char* haystack="aaaa";
    char* needle="bba";
    printf("index=%d\n",strStr(haystack,needle));

    char* a="";
    char* b="";
    printf("index=%d\n",strStr(a,b));

    char* c="aaaa";
    char* d="";
    printf("index=%d\n",strStr(c,d));

    char* e="";
    char* f="bbbb";
    printf("index=%d\n",strStr(e,f));

    char* g="a";
    char* h="a";
    printf("index=%d\n",strStr(g,h));

    char* i="hello";
    char* j="ll";
    printf("index=%d\n",strStr(i,j));
    return 0;
}


