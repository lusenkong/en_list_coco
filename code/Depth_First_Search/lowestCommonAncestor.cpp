
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
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


int lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        queue<TreeNode*> queue_name;
        map<TreeNode*,TreeNode*> parents;

        queue_name.push(root);
        parents[root] = nullptr;

        while (parents.find(p)!=parents.end() && parents.find(q)!=parents.end())
        {
            /* code */
            TreeNode* node = queue_name.front();
            queue_name.pop();
            if (node->left!=nullptr)
            {
                /* code */
                parents[node->left]= node;
                queue_name.push(node->left);
            }
            if (node->right!=nullptr)
            {
                /* code */
                parents[node->right]= node;
                queue_name.push(node->right);
            }
        }      
        set<TreeNode* >p_parents;      
        TreeNode* p1 = p;
        while (parents.find(p1)!=parents.end())
        {
            /* code */
            p_parents.insert(p1);
            p1 = parents[p1];

        }
        TreeNode* q1 = q;
        while (q1!=nullptr)
        {
            if (p_parents.find(q1)!=p_parents.end())
            {
                /* code */
                return q1->val;
            }
            q1 = parents[q1];

        }
        return -1;

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
int result = lowestCommonAncestor(&root,&node5,&node4);


printf("result1 : %d \n",result);
}