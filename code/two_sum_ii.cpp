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

vector<int> twoSum(vector<int>& numbers, int target) {
        
        // target  = 9; i = 2 ;j = 9-2 = 7;  i< half(9);
        int   = 0;
        while(left<numbers.size()){
            
            
            int temp = target - numbers[left];
            bool same = false;
            for(int i = left+1;i<numbers.size();i++){
                if(numbers[i]==numbers[left]){
                    left = i;
                    same = true;
                }
                if(temp == numbers[i]){
                    vector<int> result;
                    if(same){
                        result = {left,i+1};
                        }
                    else { result = {left+1,i+1};}
                    return result;，
                }

                if(temp<numbers[i]){
                    break;
                }
            }

            left++;

            
            
        }

        vector<int> result = {-1,-1};
                return result;
        
    }

int main(){

    vector<int>  nums = {0,0,2,3,9,9,9};

    vector<int> t = twoSum(nums,0);


    
    printf_vector_int(t);
            //printf_vector_int(nums);

}