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

void moveZeroes(string & s) {
        
        // # [0,1,0,3,12]
       //# [1,3,0,0,12]
        //
        
        int l = 0;
        int blank ;

        for(int i = l+1;i<s.length();i++){

                if(s[i]==' '){
                    blank = i;
                    int r = blank-1;
                    while (l<r)
                    {
                        char temp = s[l];
                        s[l++] = s[r];
                        s[r--] = temp;
                        
                    }
                    l = blank+1;
                    
                }

        }

        int r = s.length()-1;
        while (l<r)
                    {
                        char temp = s[l];
                        s[l++] = s[r];
                        s[r--] = temp;
                        
                    }
        
        
        
    }

int main(){

    string s = "Let's take LeetCode contest";
    moveZeroes(s);


    
    printf("%s \n",s.c_str());

}