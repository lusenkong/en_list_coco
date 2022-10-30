
#include <stdio.h>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;






const int MOD = 1e9 + 7;
    
    int waysToTarget(vector<vector<int>>& memo, int diceIndex, int n, int currSum, int target, int k) {
        // All the n dice are traversed, the sum must be equal to target for valid combination
        if (diceIndex == n) {
            return currSum == target;
        }

        // We have already calculated the answer so no need to go into recursion
        if (memo[diceIndex][currSum] != -1) {
            //printf("dice %d cursum %d ways %d\n",diceIndex,currSum,memo[diceIndex][currSum]);

            return memo[diceIndex][currSum];
            
        }
		
        int ways = 0;
        // Iterate over the possible face value for current dice
        for (int i = 1; i <= min(k, target - currSum); i++) {
            ways = (ways + waysToTarget(memo, diceIndex + 1, n, currSum + i, target, k)) ;
        }
        return memo[diceIndex][currSum] = ways;
    }
    
    int numRollsToTarget1(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return waysToTarget(memo, 0, n, 0, target, k);
    }

    int start(int dice,int n, int k, int target,int cursum,int& ways){
        

        if ( dice == n)
        {
            /* code */
            if (cursum==target)
            {
                /* code */
                ways++;
            }else{
                return -1;
            }
            
        }
        
        if (cursum>target || dice > n)
        {
            /* code */
            return -1;
        } 
        // cursum < target && dice < n
        
       for (int i = 1; i <= min(k,target-cursum); i++)
       {
        /* code */

            start(dice+1,n,k,target,cursum+i,ways);
       }
    return -1;
    }


    int start1(vector<vector<int>>& mem,int n,int k,int target,int cursum,int dice){


        if(dice==n)
        {
            /* code */
            return target==cursum;
        }

        if (mem[dice][cursum]!=-1)
        {
            /* code */
            return mem[dice][cursum];

        }

        int ways = 0;
        for (int i = 1; i <= min(target-cursum,k); i++)
        {
            /* code */
            ways = ways + start1(mem,n,k,target,cursum+i,dice+1);
        }

        mem[dice][cursum]=ways;
        return ways;
        
        
        

        
    }
    
   int numRollsToTarget(int n, int k, int target) {

    vector<vector<int>> mem(n+1,vector<int>(target+1,-1));
    const int MOD = 1e9 + 7;
    int dice = 0;
    int cursum = 0;
    int ways = 0;
    ways = start1(mem,n,k,target,cursum,dice);
    return ways% MOD;

    } 

int main(){


// n =3 ,k = 6 , target = 7;

// cursum before last dice is 4;



// 1+3+3 =  7 ;
// 2+2 (1,2,3,4,5)


     int n = 10;
     int k = 10;
     int target = 15  ;
     int t = numRollsToTarget1(n,k,target);
    printf("num: %d\n",t);
     int t1 = numRollsToTarget(n,k,target);
    printf("num: %d\n",t1);

 
}