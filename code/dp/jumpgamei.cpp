
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

bool canjumpfromposition(int position , vector<int>& nums,map<int,int>& memo){


    if (memo[position]!=0)
    {
        /* code */
        return memo[position]==1?true:false;
    }
    

    int fisrtest_jump =std::min(position+nums[position],int(nums.size()-1));

    //for (int i = position+1; i <= fisrtest_jump; i++)
    for (int i = fisrtest_jump; i > position; i--)
    {
        /* code */
        if(canjumpfromposition(i,nums,memo))
        {   
            memo[position]=1;
            return true;
        }
    }
    memo[position]=-1;
    return false;
    

}

bool canJump1(vector<int>& nums) {
        
        map<int,int> memo;
        for (int i = 0; i < nums.size(); i++)
        {
            memo[i] = 0;
            /* code */
        }
        memo[nums.size()-1] = 1;
        return canjumpfromposition(0,nums,memo);
    }
    

bool canJump(vector<int>& nums) {
    int mostright = nums.size()-1;
    
    for (int i = mostright; i >=0; i--)
    {
        /* code */
        if (nums[i]+i>=mostright)
        {
            /* code */
            mostright = i;
        }
        


    }
    return mostright==0;
    }

int main(){

vector<int> nums = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
bool flag = canJump(nums);

cout<<flag<<endl;

}