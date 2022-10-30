
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
        

        
        int size = nums.size();
        vector<int> mask(size);
        int max  = 0;
        mask[size-1] =  nums[size-1];
        for (int i = size-2 ; i >=0; i--)
        {   
            
            mask[i] = std::max(mask[i+1],nums[i]);

        }


        for (int i = 0; i < size; i++)
        {
            /* code */
            max = std::max(max,mask[i]-nums[i]);
            
        }
        
        return max;
        
        

    }

int main(){
    
vector<int> input ={-2,1,-3,4,-1,2,1,-5,4};

int result = trap(input);

printf("result : %d \n",result);


}