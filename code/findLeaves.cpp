
#include <stdio.h>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<iostream>
#include<unordered_set>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
void printf_2d_mem(vector<pair<int,int>>& mem){

    for (int i = 0; i < mem.size(); i++)
    {
        /* code */
        printf("height: %d  val: %d\n",mem[i].first,mem[i].second);
    }
    


}
int calculate_Height(TreeNode* node,map<int,vector<int>>& mem){
    if (!node)
    {
        return 0;
    }

    int left_h = calculate_Height(node->left,mem);
    int right_h = calculate_Height(node->right,mem);

    int cur_height = max(left_h,right_h)+1;
    //mem.push_back(pair<int,int>(cur_height,node->val));
    mem[cur_height].push_back(node->val);
    return cur_height;

}



vector<vector<int>> findLeaves(TreeNode* root) {
        
        map<int,vector<int>> mem;
        calculate_Height(root,mem);
        vector<vector<int>> solution;
        for (int i = 1; i <= mem.size(); i++)
        {
            /* code */
            solution.push_back(mem[i]);

        }
        
        
        //printf_2d_mem(mem);
        return solution;
    }
    
    

int main(){

//araa  6;

// 0,1-> 1,2->1,-1
int s =2;
TreeNode root  = TreeNode(3);
TreeNode node5 = TreeNode(5);
TreeNode node1 = TreeNode(1);
TreeNode node6 = TreeNode(6);
TreeNode node2 = TreeNode(2);
TreeNode node0 = TreeNode(0);
TreeNode node8 = TreeNode(8);
TreeNode node7 = TreeNode(7);
TreeNode node4 = TreeNode(4);


root.left = &node5;
root.right = &node1;
node5.left = &node6;
node5.right = &node2;
node2.left = &node7;
node2.right = &node4;
node1.left = &node0;
node1.right = &node8;
 findLeaves(&root);


}