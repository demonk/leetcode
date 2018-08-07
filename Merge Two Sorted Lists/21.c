#include "stdio.h"
#include "malloc.h"


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1=l1;
    struct ListNode* p2=l2;
    struct ListNode* head=p1==NULL?p2:p1,*p=NULL;

    while(p1!=NULL&&p2!=NULL){
        if(p1->val<=p2->val){
            if(p!=NULL){
                p->next=p1;
            }else{
                head=p1;
            }
            p=p1;
            p1=p1->next;
        }else{
            if(p!=NULL){
                p->next=p2;
            }else{
                head=p2;
            }
            p=p2;
            p2=p2->next;
        }
    }

    if(p!=NULL){
        if(p1!=NULL)
        {
            p->next=p1;
        }
        if(p2!=NULL){
            p->next=p2;
        }
    }
    return head;
}

int main(int argv,char* argc){
    struct ListNode* one=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* three=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* five=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* two=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* four=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* six=(struct ListNode*)malloc(sizeof(struct ListNode));

    one->val=1;
    two->val=2;
    three->val=3;
    four->val=4;
    five->val=5;
    six->val=6;

    one->next=three;
    three->next=five;
    five->next=NULL;

    two->next=four;
    four->next=six;
    six->next=NULL;


    struct ListNode* result=mergeTwoLists(one,two);

    while(result!=NULL){
        printf("%d ",result->val);
        result=result->next;
    }

    printf("\n");

    return 0;
}


