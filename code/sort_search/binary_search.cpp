#include<vector>
#include<iostream>
#include<stdlib.h>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l<=r){
            printf("l %d, r %d \n",l,r);
            int mid = l +(r-l)/2;
            if(nums[mid]==target)return mid;
            
            if(nums[mid]<target){

                l = mid+1;
            }else{

                r = mid-1;//0
            }
        }
        
        if(l==0)return 0;
        if (r==nums.size()-1)return r;
        
        if(nums[l]<target)return l;
        if(nums[r]>target)return r;
        
        if(nums[l]>target)return l+1;
        if(nums[r]<target)return r-1;
        
        return -1;

    }

int search_iter(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;
        
        int mid_index = (left + right) /2;
        printf("mid %d\n",mid_index);
        
        while(left <= right){
            printf("left %d\n",left);
            printf("right %d\n",right);
            mid_index = (left + right) >>1;
            if (nums[mid_index]==target){
                return mid_index;
            }else if (nums[mid_index]>target){
                right = mid_index-1;
            }else{
                left = mid_index +1;
            }
        }
        
        return -1;
        
}


int search_recusive_sub(vector<int>& nums, int target,int left ,int right){
    

}

int search_recusive(vector<int>& nums, int target){

}

int main(){
    
    vector <int> nums1  = {1,3,5,6};

    // 0,....,5 -> 2
    int target = 7;

    int t = searchInsert(nums1,target);
    printf("out %d\n",t);


 


}