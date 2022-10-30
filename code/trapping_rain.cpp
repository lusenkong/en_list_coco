
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


int trap(vector<int>& height) {
        
        int i = 0;
        int size = height.size();
        vector<int> height_left(size);
        vector<int> height_right(size);

        printf_vector_int(height);
        height_left[0] = height[0];
        int max = height[0];
        for (int i = 1; i < size; i++)
        {
            /* code */
            max = std::max(height[i],max);
            height_left[i] = max;
        }

        printf_vector_int(height_left);
        
        max = height[size-1];
        height_right[size-1] = max;

        for (int i = size-2; i >=0; i--)


        {
            max = std::max(max,height[i]);
            height_right[i] = max;

        }
        printf_vector_int(height_right);
        
        int output = 0;

        for (int i = 0; i < size; i++)
        {
            /* code */
            int output_temp = std::min(height_left[i],height_right[i]);
            output +=(output_temp-height[i]);
        }

        return output;
        

    }

int main(){
    
vector<int> input = {4,2,0,3,2,5};

int result = trap(input);

printf("result : %d \n",result);


}