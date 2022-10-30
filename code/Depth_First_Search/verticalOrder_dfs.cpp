#include<vector>
#include<cmath>
#include<stdio.h>
#include<iostream>
#include<map>
#include<queue>


using namespace std;




struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


void node_insert(TreeNode* node , int col,int row,map<int,map<int,vector<int>>>&mem){
        if(node)
        {
            mem[col][row].push_back(node->val);
            node_insert(node->left,col-1,row+1,mem);
            node_insert(node->right,col+1,row+1,mem);

        }else{
            return;
        }

}

vector<vector<int>> verticalOrder(TreeNode* root) {

         map<int,map<int,vector<int>>> mp;
        node_insert(root, 0, 0,mp);
        
        //now convert map into answer format vector of vector
        vector<vector<int>> ans;


        


        for(auto m1 : mp) {
            vector<int> a;
            for(auto m2 : m1.second) {
                for(auto x : m2.second) {
                    a.push_back(x);
                }
            }
            ans.push_back(a);
        }
        
        return ans;
    }
        
    
int main(){

    TreeNode root = TreeNode(3);
    TreeNode node_9 = TreeNode(9);
    TreeNode node_8 = TreeNode(8);
    TreeNode node_4 = TreeNode(4);
    TreeNode node_0 = TreeNode(0);
    TreeNode node_1 = TreeNode(1);
    TreeNode node_7 = TreeNode(7);
    TreeNode node_5 = TreeNode(5);
    TreeNode node_2 = TreeNode(2);

    root.left = &node_9;
    root.right = &node_8;
    node_9.left = &node_4;
    node_9.right = &node_0;
    node_8.left = &node_1;
    node_8.right = &node_7;
    node_1.left = &node_5;
    node_0.right = &node_2;


    vector<vector<int>> result = verticalOrder(&root);
    printf("result.size() %d\n",result.size());
    for (size_t i = 0; i < result.size(); i++)
    {
        /* code */

        for (size_t j = 0; j < result[i].size(); j++)
        {
            printf(" %d ",result[i][j]);
            /* code */

        }

        printf("\n");
        
    }
    
            //printf_vector_int(nums);

}