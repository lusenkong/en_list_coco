#include<vector>
#include<cmath>
#include<stdio.h>
#include<iostream>




using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}


};

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1==nullptr)return root2;
        if(root2==nullptr)return root1;

        root1->val = root1->val+root2->val;

        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        return root1;

        
        
        
        
    }
int main(){

    vector<int>  nums = {0,1,0,3,12};

    moveZeroes(nums);


    
    printf_vector_int(nums);
            //printf_vector_int(nums);

}