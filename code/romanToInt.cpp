#include<vector>
#include<cmath>
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>


using namespace std;

void printf_vector_int(vector<int>& nums){
    for(int t:nums){
        printf(" %d ",t) ;
    }
    printf("\n");
}

int twoSum(const string& rome) {

        map<int,vector<int>> rome_map;
rome_map['I'] = {0,1};
rome_map['V'] = {1,5};
rome_map['X'] = {2,10};
rome_map['L'] = {3,50};
rome_map['C'] = {4,100};
rome_map['D'] = {5,500};
rome_map['M'] = {6,1000};


//Input: s = "MCMXCIV"
//Output: 1994
//Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
int result = 0;
for (int i = 0; i < rome.size(); i++)
{
    /* code */
    
    if (i+1<rome.size())
    {
        /* code */
        if (rome_map[rome[i+1]][0]<=rome_map[rome[i]][0])
        {
            /* code */
            result = result+rome_map[rome[i]][1];
        }else{
            result = result - rome_map[rome[i]][1];

        }
        
    }else{
        result = result+rome_map[rome[i]][1];
    }


}

return result;

        
    }

int main(){

    string input = "MCMXCIV";

    int result = twoSum(input);
    printf("result : %d\n",result);

    //vector<int> t = twoSum(nums,0);


    
    //printf_vector_int(t);
            //printf_vector_int(nums);

},,