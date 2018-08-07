#include "stdio.h"
#include "malloc.h"
#include "string.h"
#include <stdbool.h>

bool isValid(char* s) {
    int index=0;
    int stack_ptr=0;
    int size=strlen(s);
    char** stack;

    if(size>0){
        stack=(char**)malloc(size*sizeof(char*));
    }

    for(;index<size;index++){
        if(s[index]=='(' || s[index]=='[' || s[index]=='{'){
            stack[stack_ptr++]=&s[index];
        }else if(s[index]==')'){
            if(stack_ptr<=0||*stack[--stack_ptr]!='('){
                return false;
            }
        }else if(s[index]==']'){
            if(stack_ptr<=0||*stack[--stack_ptr]!='['){
                return false;
            }
        }else if(s[index]=='}'){
            if(stack_ptr<=0||*stack[--stack_ptr]!='{'){
                return false;
            }
        }
    }

    return stack_ptr<=0;
}

int main(int argv,char* argc){
    char* s="){";
    printf("%d",isValid(s));
    return 0;
}


