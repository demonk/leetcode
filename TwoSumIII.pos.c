#include "stdio.h"
#include "malloc.h"

typedef int bool;
#define true 1
#define false 0

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

bool findTarget(struct TreeNode* root,int k){
    while(root->left!=NULL&&root->val>=k){
        root=root->left;
    }

    TreeNode* p1=root;
    TreeNode* p2=root->left;

    if(p2==NULL){
        p2=root->right;
    }
    if(p2==NULL){
        return false;
    }

    int sum=0; 
    while(p1!=NULL){ 
        printf("%d+%d\n",p1->val,p2->val);
        sum=p1->val+p2->val;
        if(sum>k){
            if(p2->left==NULL){
                p1=p1->left;
            }else{
                p2=p2->left;
            }
        }else if(sum<k){
            if(p2->right==NULL){
                p1=p1->right; 
            }else{
                p2=p2->right; 
            }
        }else{
            return true;
        }
    }
    return false;
}

int main(int argv,char* argc){
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* leaf_1=(TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* leaf_2=(TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* leaf_3=(TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* leaf_4=(TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* left=(TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* right=(TreeNode*)malloc(sizeof(TreeNode));

    root->val=2;
    left->val=0;
    right->val=3;
    leaf_1->val=-4;
    leaf_2->val=1;
    //leaf_3->val=7;
    //leaf_4->val=7;

    left->left=leaf_1;
    left->right=leaf_2;
    //right->left=leaf_3;
    //right->right=leaf_4;

    root->left=left;
    root->right=right;

    int target=-1;

    printf("result=%i\n",findTarget(root,target));
    return 0;
}


