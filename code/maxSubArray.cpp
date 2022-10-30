
#include <stdio.h>
#include<vector>
#include<cmath>
using namespace std;

void printf_vector_int(vector<int>& nums){
    for(int t:nums){
        printf(" %d ",t) ;
    }
    printf("\n");
}


int trap(vector<int>& nums) {
        



        int current = nums[0];
        int max  = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {   
            printf("current %d \n",current);
            current = std::max(nums[i],current+nums[i]);
            max = std::max(current,max);

        }
        return max;
        
        

    }

int main(){
    
vector<int> input ={-2,1,-3,4,-1,2,1,-5,4};

int result = trap(input);

printf("result : %d \n",result);


}