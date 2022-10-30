#include<vector>
#include<cmath>
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


void flood_fill_sub(vector<vector<int>>& image,int sr, int sc, int color,int target){

    
    printf("image.size() %d\n",image.size());
    printf("image[0].size() %d\n",image[0].size());

    if(sr>=image.size() || sr<0  || sc>=image[0].size() || sc<0){

        return ;

    }

    //printf("[%d][%d] \n",sr,sc);
    if(image[sr][sc]==target){
        
        image[sr][sc] = color;
    flood_fill_sub(image,sr-1,sc,color,target);
    flood_fill_sub(image,sr+1,sc,color,target);
    flood_fill_sub(image,sr,sc-1,color,target);
    flood_fill_sub(image,sr,sc+1,color,target);
        
    }
    
    

    //printf("kk\n");
    
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc] ;
        if(target!=color)flood_fill_sub(image,sr,sc,color,target);

       
        

        return image;
        
    }

int main(){

    vector<vector<int>> image = {{0,0,0},{0,0,0}};

    floodFill(image,0,0,0);

   
    return 0;
    
    
            //printf_vector_int(nums);

}