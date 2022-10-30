
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


string lowestCommonAncestor_v1(TreeNode* root, TreeNode* p, TreeNode* q) {

        queue<TreeNode*> queue_name;
        map<TreeNode*,TreeNode*> parents;

        queue_name.push(root);
        parents[root] = nullptr;

        while (parents.find(p)==parents.end() || parents.find(q)==parents.end())
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
        TreeNode* ans = q;
        while (ans!=nullptr)
        {
            if (p_parents.find(ans)!=p_parents.end())
            {
                /* code */
                break;
            }
            ans = parents[ans];

        }

        p1 = p;
        string cmd1 = "";
        while (p1!=ans)
        {
            /* code */
            p1 = parents[p1];
            cmd1 = cmd1+'U';

        }
        if (ans==q)
        {
            /* code */
            return cmd1;
        }
        string cmd2 = "";
        queue<TreeNode*> ways;
        map<TreeNode* ,string> ways_table;
        ways.push(ans);
        ways_table[ans] = "";
        while (1)
        {   
            TreeNode* cur_node = ways.front();
            ways.pop();
            if (cur_node->left!=nullptr)
            {
                if(cur_node->left==q){
                    cmd2 = ways_table[cur_node]+'L';
                    break;
                }else{
                    ways_table[cur_node->left] = ways_table[cur_node]+'L';
                    ways.push(cur_node->left);
                }
            }
            if (cur_node->right!=nullptr)
            {
                if(cur_node->right==q){
                    cmd2 = ways_table[cur_node]+'R';
                    break;
                }else{
                    ways_table[cur_node->right] = ways_table[cur_node]+'R';
                    ways.push(cur_node->right);
                }
            }
            
            
            
        }
        
        return cmd1+cmd2;

    }

string lowestCommonAncestor_v2(TreeNode* root, TreeNode* p, TreeNode* q) {

        queue<TreeNode*> queue_name;
        map<TreeNode*,TreeNode*> parents;

        queue_name.push(root);
        parents[root] = nullptr;

        while (parents.find(p)==parents.end() || parents.find(q)==parents.end())
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
        set<TreeNode* >q_parents;      
        TreeNode* q1 = q;
        while (parents.find(q1)!=parents.end())
        {
            /* code */
            q_parents.insert(q1);
            q1 = parents[q1];

        }
        TreeNode* ans = p ;
        string cmd1 = "";
        while (ans!=nullptr)
        {   
            if (q_parents.find(ans)!=q_parents.end())
            {
                /* code */
                break;
            }
            ans = parents[ans];
            cmd1 = cmd1+'U';

        }




        string cmd2 = "";
        queue<TreeNode*> ways;
        map<TreeNode* ,string> ways_table;
        if (ans==q)
        {
            /* code */
            return cmd1;
        }
        
        ways.push(ans);
        ways_table[ans] = "";
        printf("b\n");
        printf("ans %d\n",ans->val);
        printf("start %d\n",p->val);
        printf("dest %d\n",q->val);
        
        while (!ways.empty())
        {   
            TreeNode* cur_node = ways.front();
            ways.pop();
            printf("cur_node %d\n",cur_node->left->val);
            if (cur_node->left!=nullptr)
            {   
                printf("step in1 \n");
                if(cur_node->left==q){
                    printf("step in11 \n");
                    cmd2 = ways_table[cur_node]+'L';
                    break;
                }else{
                    printf("step in12 \n");
                    ways_table[cur_node->left] = ways_table[cur_node]+'L';
                    ways.push(cur_node->left);
                }
            }
           
            if (cur_node->right!=nullptr)
            {   
                printf("step in2 \n");
                if(cur_node->right==q){
                    cmd2 = ways_table[cur_node]+'R';
                    break;
                }else{
                    ways_table[cur_node->right] = ways_table[cur_node]+'R';
                    ways.push(cur_node->right);
                }
            }
            
            
            
        }
        
        return cmd1+cmd2;

    }

string lowestCommonAncestor_v3(TreeNode* root, TreeNode* p, TreeNode* q) {

        queue<TreeNode*> queue_name;
        map<TreeNode*,TreeNode*> parents;

        queue_name.push(root);
        parents[root] = nullptr;

        while (parents.find(p)==parents.end() || parents.find(q)==parents.end())
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
        set<TreeNode* >q_parents;      
        TreeNode* q1 = q;
        while (parents.find(q1)!=parents.end())
        {
            /* code */
            q_parents.insert(q1);
            q1 = parents[q1];

        }
        TreeNode* ans = p ;
        string cmd1 = "";
        while (ans!=nullptr)
        {   
            if (q_parents.find(ans)!=q_parents.end())
            {
                /* code */
                break;
            }
            ans = parents[ans];
            cmd1 = cmd1+'U';

        }

        string cmd2 = "";
        if (ans==q)
        {
            /* code */
            return cmd1;
        }
        
        vector<TreeNode*> ways;
        ways.push_back(q);
        TreeNode* q2 = q;
        while (ans!=q2)
        {
            /* code */
            q2 = parents[q2];
            ways.push_back(q2);
        }
        ways.push_back(ans);
        int j = ways.size()-1;
        while (j>0)
        {   

            /* code */
            if (ways[j]->left==ways[j-1])
            {
                /* code */
                cmd1 = cmd1+'L';
            }
            if (ways[j]->right==ways[j-1])
            {
                /* code */
                cmd1 = cmd1+'R';
            }
            j--;

        }
        
        return cmd1+cmd2;

    }

string lowestCommonAncestor_v4(TreeNode* root,int startValue, int destValue) {

        TreeNode* p;
        TreeNode* q;
        if (root->val==startValue)p=root;
        if (root->val==destValue)q=root;
        queue<TreeNode*> queue_name;
        map<TreeNode*,TreeNode*> parents;
        set<int> sons;
        queue_name.push(root);
        parents[root] = nullptr;
        sons.insert(root->val);
        while (sons.find(startValue)==sons.end() || sons.find(destValue)==sons.end())
        {
            /* code */
            TreeNode* node = queue_name.front();
            queue_name.pop();
            
            
            if (node->left!=nullptr)
            {
                /* code */
                parents[node->left]= node;
                queue_name.push(node->left);
                sons.insert(node->left->val);
                if (node->left->val==startValue)p=node->left;
                if (node->left->val==destValue)q=node->left;
            }
            if (node->right!=nullptr)
            {
                /* code */
                parents[node->right]= node;
                queue_name.push(node->right);
                sons.insert(node->right->val);
                if (node->right->val==startValue)p=node->right;
                if (node->right->val==destValue)q=node->right;
            }
        }    
        set<TreeNode* >q_parents;      
        TreeNode* q1 = q;
        while (parents.find(q1)!=parents.end())
        {
            /* code */
            q_parents.insert(q1);
            q1 = parents[q1];

        }
        TreeNode* ans = p ;
        string cmd1 = "";
        while (ans!=nullptr)
        {   
            if (q_parents.find(ans)!=q_parents.end())
            {
                /* code */
                break;
            }
            ans = parents[ans];
            cmd1 = cmd1+'U';

        }

        string cmd2 = "";
        if (ans==q)
        {
            /* code */
            return cmd1;
        }
        
        vector<TreeNode*> ways;
        ways.push_back(q);
        TreeNode* q2 = q;
        while (ans!=q2)
        {
            /* code */
            q2 = parents[q2];
            ways.push_back(q2);
        }
        ways.push_back(ans);
        int j = ways.size()-1;
        while (j>0)
        {   

            /* code */
            if (ways[j]->left==ways[j-1])
            {
                /* code */
                cmd1 = cmd1+'L';
            }
            if (ways[j]->right==ways[j-1])
            {
                /* code */
                cmd1 = cmd1+'R';
            }
            j--;

        }
        
        return cmd1+cmd2;

    }



string s, t;
    void dfs(TreeNode* root,int start,int dest,string& a){

        if (!root)
        {
            return;
        }
        if (root->val==start)
        {
            /* code */
            s = a;
        }
        if (root->val==dest)
        {
            /* code */
            t = a;
        }

        if (root->left!=nullptr)
        {
            /* code */
            a.push_back('L');
            dfs1(root->left,start,dest,a);
            a.pop_back();
        }

        if (root->right!=nullptr)
        {
            /* code */
            a.push_back('R');
            dfs1(root->right,start,dest,a);
            a.pop_back();
        }
        
        
        return;

        

    }

 string getDirections(TreeNode* root, int startValue, int destValue) {
        string a= "";
        dfs(root, startValue, destValue,a);
        int i = 0;
        while (s[i]==t[i])
        {
            i++;
        }
        // i : 1
        //eg : RLRRR
        //eg : RRLLR
        string cmd1 = string(s.size()-i,'U');
        string cmd2 = t.substr(i);
        return cmd1+cmd2;
        
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


 string cmd = getDirections1(&root,6,8);

printf("cmd %s \n",cmd.c_str());

}