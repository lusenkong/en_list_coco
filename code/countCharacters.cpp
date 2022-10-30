
#include <stdio.h>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<iostream>
#include<unordered_set>
using namespace std;





int countCharacters(vector<string>& words, string chars) {

    map<char,int> char_table;
    
    for (int i = 0; i < chars.size(); i++)
    {
        /* code */
        char_table[chars[i]]++;
    }
    
    int result = 0;
    for (int i = 0; i < words.size(); i++)
    {
        /* code */
        map<char,int> char_table1 = char_table;
        string temp = words[i];
        bool flag = true;
        auto end = char_table1.end();
        for (int i = 0; i < temp.size(); i++)
        {
            /* code */
            if (char_table1.find(temp[i])==end)
            {
                /* code */
                flag = false;
                break;
            }else{

                if (char_table1[temp[i]]<1)
                {
                    /* code */
                    flag = false;
                    break;
                }else{
                    char_table1[temp[i]]--;
                }
                
            }
            

        }
        if (flag)
        {
            /* code */
            result= result+temp.size();
        }
        
        return result;

    }
    
    

    }
    
    

int main(){

 
}