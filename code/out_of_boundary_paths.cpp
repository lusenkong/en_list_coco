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

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
    }

int main(){

    vector<int>  nums = {0,1,0,3,12};

    moveZeroes(nums);


    
    printf_vector_int(nums);
            //printf_vector_int(nums);

}