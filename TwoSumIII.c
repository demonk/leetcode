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

void sort(struct TreeNode* root,int* arrays,int* index){
    if(root!=NULL){
        sort(root->left,arrays,index);
        arrays[(*index)]=root->val;
        *index=*index+1;
        sort(root->right,arrays,index);
    }
}

bool findTarget(struct TreeNode* root,int k){
    int index=0;
    int arrays[36];

    sort(root,arrays,&index);

    int min=0,max=index-1;
    while(min!=max){
        int sum=arrays[min]+arrays[max];
        if(sum>k){
            max--;
        }else if(sum<k){
            min++;
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

    root->val=1999;
    left->val=1488;
    right->val=4594;
    leaf_1->val=15;
    leaf_2->val=1;
    leaf_3->val=3326;
    leaf_4->val=7;

    left->left=leaf_1;
    //left->right=leaf_2;
    right->left=leaf_3;
    //right->right=leaf_4;

    root->left=left;
    root->right=right;

    int target=3998;

    printf("result=%i\n",findTarget(root,target));
    return 0;
}


