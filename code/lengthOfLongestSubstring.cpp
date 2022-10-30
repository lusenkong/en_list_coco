#include<vector>
#include<cmath>
#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include <algorithm>


using namespace std;

void printf_vector_int(vector<int>& nums){
    for(int t:nums){
        printf(" %d ",t) ;
    }
    printf("\n");
}

void printf_set_char(unordered_set<char>& nums){
   for(auto iter = nums.begin();iter!=nums.end();++iter){
        printf("%c ",*iter);
   }

   cout<<endl;
}

int lengthOfLongestSubstring(string s) {
        
        // # [0,1,0,3,12]
       //# [1,3,0,0,12]
        //
//"abcabcbb";
        //unordered_set<char> char_set;
        //unordered_set<char>::iterator set_ed = char_set.end();

        int left =0;
        int r = 0;
        int lenth= 0;
        unordered_map<char,int> window_map;
        while (r<s.size())

        {   
            char cur = s[r];
            
            if (window_map.find(cur)!=window_map.end()){
                printf("left %d\n",left);
                left = max(left,window_map.at(cur));

                if(left>window_map.at(cur)){
                    ;
                }else{
                    left = window_map.at(cur)+1;
                }

                
                window_map.find(cur)->second = r;
                
            }else{
                window_map.insert(make_pair(cur,r));
            }
            
            int cur_lenth = r-left+1;
            lenth = max(lenth,cur_lenth);        
            r++;

            

            /* code */
        }
        return lenth;
        
        
        
    }

int main(){

    // a,0,  b,1  left = 2

    string s = "tmmzuxt";

    int s1 = lengthOfLongestSubstring(s);

    cout<<s1<<endl;
    
    //printf_vector_int(nums);
            //printf_vector_int(nums);

}