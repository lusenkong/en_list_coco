#include<vector>
#include <algorithm>
#include<stdio.h>
#include<iostream>
#include<unordered_map>



using namespace std;

void printf_vector_int(vector<int>& nums){
    for(int t:nums){
        printf(" %d ",t) ;
    }
    printf("\n");
}


int seen1(vector<vector<int>>& image,vector<vector<int>>& seen,int sr, int sc){

    if(sr>=image.size() || sr<0  || sc>=image[0].size() || sc<0 ){

        return 0;

    }

    if(seen[sr][sc]==0){
        return 0;
    }

    seen[sr][sc]=0;

    if(image[sr][sc]==1){
        int a = seen1(image,seen,sr-1,sc);
    int b = seen1(image,seen,sr+1,sc);
    int c = seen1(image,seen,sr,sc-1);
    int d = seen1(image,seen,sr,sc+1);
    return image[sr][sc]+a+b+c+d;
    }else{
        return 0;
    }
    

}




int maxAreaOfIsland(vector<vector<int>>& image) {
       int max1 = 0;
        vector<vector<int>> seen(image.size(),vector<int>(image[0].size(),-1));

        for(int i = 0;i<image.size();i++){
                for(int j = 0;j<image[i].size();j++){
                    int t = seen1(image,seen,i,j);
                    max1 = std::max(max1,t);
                }

        }


            return max1;
    }

int main(){

    vector<vector<int>> image = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};

    int result = maxAreaOfIsland(image);

    cout<<result<<endl;
    return 0;
    
    
            //printf_vector_int(nums);

}