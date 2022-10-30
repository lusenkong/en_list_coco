
#include <stdio.h>
#include<vector>
#include<cmath>
#include<string>
#include<map>
using namespace std;


int countString(string& s){

    map<char,int> map_temp;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        /* code */
        map_temp[s[i]]++;
    }
    

    for (auto kv : map_temp)
    {
        /* code */
        if (kv.second==1)
        {
            /* code */
            count++;;
        }
        
    }
    return count;

}

int uniqueLetterString(string& s) {
        if(s=="")return 0;
        if(s.size()==1)return 1;
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            /* code */
            int left = 1;
            int right = 1;
            for (int j = i-1; j >=0; j--)
            {
                /* code */
                if (s[j]!=s[i])
                {
                    /* code */
                    left++;
                }else{
                    break;
                }
                
            }

            for (int j = i+1; j < s.size(); j++)
            {
                /* code */
                if (s[j]!=s[i])
                {
                    /* code */
                    right++;
                }else{
                    break;
                }
            }
            
            printf("%d : %d \n",i,left*right);
            result = result+(left*right);

        }

        return result;
        
    }
    
    

int main(){


string s = "leetcode";

int result = uniqueLetterString(s);

printf("result : %d \n",result);


}