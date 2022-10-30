#include<vector>
#include<cmath>
#include<stdio.h>
#include<iostream>




using namespace std;

void printf_vector_int(vector<int>& nums){
    for(int t:nums){
        printf(" %d ",t) ;
    }
    printf("\n");
}

void moveZeroes(vector<int>& nums) {
        
        // # [0,1,0,3,12]
       //# [1,3,0,0,12]
        //
        
        int non_zero = 0;
        
        for (int cur = 0; cur< nums.size(); cur++)
        {
            /* code */

            if (nums[cur]!=0)
            {
                /* code */
                int t = nums[cur];
                nums[cur] = nums[non_zero];
                nums[non_zero] = t;
                ++non_zero;
            }
            
        }
        
        
    }

int main(){

    vector<int>  nums = {0,1,0,3,12};

    moveZeroes(nums);


    
    printf_vector_int(nums);
            //printf_vector_int(nums);

}