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

vector<int> sortedSquares(vector<int>& nums) {
        //const int target = 0;
        vector <int> minus_nums,squared_nums;
        
        int index_positive =-1;
        bool if_first = true;
        for(int i = nums.size()-1;i>=0;i--){
                if (nums[i]<0)
                {   
                    if(if_first){
                        index_positive = i;
                        if_first = false;
                    }
                    minus_nums.push_back(-nums[i]);

                    /* code */
                }
                
        }
        //printf("index_positive %d and nums_size %d\n",index_positive,nums.size());
        printf("minus_nums\n");
        printf_vector_int(minus_nums);
        printf("index_positive %d\n",index_positive);
        printf("nums\n");
        printf_vector_int(nums);
        if (minus_nums.size() == nums.size()){
            for(int t:minus_nums)
            squared_nums.push_back(pow(t,2));

        }
        else if (index_positive==-1){

            for(int t:nums)
            squared_nums.push_back(pow(t,2));
        }
        else
        {   
            
            index_positive++;
            printf("index %d \n",index_positive);
            int index_minus = 0;
            while (index_minus<=minus_nums.size()-1 && index_positive<=nums.size()-1)
            {
                /* code */
                if(minus_nums[index_minus] <= nums[index_positive]){
                    squared_nums.push_back(pow(minus_nums[index_minus],2));
                    ++index_minus;
                }else{
                    squared_nums.push_back(pow(nums[index_positive],2));
                    ++index_positive;
                }
            }

            if(index_minus>minus_nums.size()-1){
                for(;index_positive<nums.size();index_positive++)
                squared_nums.push_back(pow(nums[index_positive],2));
            }else{
                for(;index_minus<minus_nums.size();index_minus++)
                squared_nums.push_back(pow(minus_nums[index_minus],2));
            }
            

        }

        

        
    return squared_nums;
    }

int main(){

    vector<int>  nums = {-2,0};

    vector<int>  squared_nums = sortedSquares(nums);


    
    printf_vector_int(squared_nums);
            //printf_vector_int(nums);

}