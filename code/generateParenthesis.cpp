
#include <stdio.h>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

void generate1(vector<string> &ans,string s,int open,int close)
    {
        if(open == 0 && close == 0)
        {
            printf("result : %s\n",s.c_str());
            ans.push_back(s);
            return ;
        }
        // ((())
        if (open<close)
        {
            generate1(ans,s+')',open,close-1);

        }
        if (open>0)
        {
            /* code */
             generate1(ans,s+'(',open-1,close);
        }
        
        


    }

















void generate(vector<string> &ans,string s,int open,int close)
    {
        if(open == 0 && close == 0)
        {
            printf("result : %s\n",s.c_str());
            ans.push_back(s);
            return ;
        }
        
        if(open > 0)
        {
            generate(ans,s+'(',open-1,close);
        }
        
        //exit(0);
        
        if(open < close)
        {
            generate(ans,s+')',open,close-1);
        }
    }

vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        generate1(ans,"",n,n);
        
        return ans;
    }
    
    

int main(){
    
vector<string> result = generateParenthesis(4);

printf("result : %d \n",result.size());


}