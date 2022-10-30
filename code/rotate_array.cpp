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

void rotate(vector<int>& nums, int k) {
        // 0，1，2，3，4，5，6
        //4，5，6，0，1，2，3
        // 
        int period = nums.size();
        int step  = k%period;
        printf("step %d\n",step);
        vector<int> output(period);
        for(int i =step,j=0; i<= nums.size()-1;i++,j++){
                        printf("step in %d %d \n",i,j);
            output[i] = nums[j];
        }
        printf_vector_int(output);
        for(int i = 0;i<=step-1;i++){

            output[i] = nums[nums.size()-step+i];
            
        }
        printf_vector_int(output);
        nums = output;
    }

int main(){

    vector<int>  nums = {-2,0};

    rotate(nums,2);


    
    printf_vector_int(nums);
            //printf_vector_int(nums);

}