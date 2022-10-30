
#include <stdio.h>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<iostream>
#include<unordered_set>
using namespace std;



int start(vector<vector<int>>& mem,int n,int k){

    if (n=0)
    {
        /* code */
        return 0;
    }
    if (k==0)
    {
        /* code */
        return 1;
    }

    if (mem[n][k]!=-1)
    {
        /* code */
        return mem[n][k];
    }

    int value = 0;

    for (int i = 0; i < min(n-1,k); i++)
    {
        /* code */
        value  = (value+start(mem,n-1,k-i))%1000000007;
        
    }
    mem[n][k] = value;
    return value;

}


int kInversePairs(int n, int k) {

    vector<vector<int>> mem(1001,vector<int>(1001,-1));
    
    int value = start(mem,n,k);
    return value;
        
    }
    
    

int main(){


    // 1,2,3,4,5

    //        1
    //        1 1
    //    1   1 1
    //    1 1 1 1
    //  1 1 1 1 1

    //  1 1 1 1
    //  1 1 1 1 1
    //  1 1 1 1 1
    //  1 1 1 1 1
    //  1 1 1 1 1

    //        1 1
    //        1 1
    //    1 1 1 1
    //    1 1 1 1
    //  1 1 1 1 1

    //1,3,2,5,4
    // 1,2,3,4,5


    // 1
    //  1 2

    // 3 1 2
    // 1 3 4 2 
    // 1 4 2 3 5
    //1 2 5 3  4  

int n = 5;
int k =2;
int result1  = kInversePairs(n,k);

printf("result1 : %d \n",result1);
}