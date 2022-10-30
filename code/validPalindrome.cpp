
#include <stdio.h>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<iostream>
#include<unordered_set>
using namespace std;

bool checkPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }


bool validPalindrome(string& s) {

    // 
    
    if (s.size()==0)return true;

    int i = 0;
    int j = s.size()-1;

    while (i<=j)
    {   

        if (s[i]!=s[j])
        {
            /* code */
            return checkPalindrome(s,i,j-1)||checkPalindrome(s,i+1,j);
        }
        
        ++i;
        --j;  
    }

    return true;

    }
    
    

int main(){

string s1 = "eedede";
string s2 = "lcuucul";
bool flag = validPalindrome(s2);

cout<<flag<<endl;

}