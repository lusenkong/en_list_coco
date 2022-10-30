#include<vector>
#include<cmath>
#include<stdio.h>
#include<iostream>
#include<map>



using namespace std;

void printf_vector_int(vector<int>& nums){
    for(int t:nums){
        printf(" %d ",t) ;
    }
    printf("\n");
}

vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int> nums_map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
            nums_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
            int temp = target-nums[i];
            if (nums_map.find(temp) !=nums_map.end() && i!=nums_map[temp])
            {
                /* code */
                result.push_back(i);
                result.push_back(nums_map[temp]);
                return result;

            }
            
        }
        

        return result;
    }

int main(){

    vector<int>  nums = {0,0,2,3,9,9,9};

    //vector<int> t = twoSum(nums,0);


    
    //printf_vector_int(t);
            //printf_vector_int(nums);

}