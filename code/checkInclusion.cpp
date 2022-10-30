#include<vector>
#include<cmath>
#include<stdio.h>
#include<iostream>
#include<unordered_map>



using namespace std;

void printf_vector_int(vector<int>& nums){
    for(int t:nums){
        printf(" %d ",t) ;
    }
    printf("\n");
}

unordered_map<char,int> get_table_from_string(const string& s1){
        unordered_map<char,int> s1map;
        for(size_t i = 0;i<s1.size();i++){
                if(s1map.find(s1[i])==s1map.end()){
                    s1map.insert(make_pair(s1[i],1));
                }else{
                    s1map.find(s1[i])->second++;
                }
        }

        return s1map;

}

bool checkInclusion(string s1, string s2) {
        

if(s1.size()>s2.size()){
            return false;
        }
        
        unordered_map<char,int> s1map = get_table_from_string(s1);


        // 0,1,2
        //0,1,2,3,4
        for(size_t i = 0;i<=s2.size()-s1.size();i++){
            
            unordered_map<char,int> s2map;
            string s2_sub = s2.substr(i,s1.size());

            s2map = get_table_from_string(s2_sub);

            int count= 0;
            for(auto kv:s1map){

                char k = kv.first;
                if(s2map.find(k)==s2map.end()){
                    break;
                }else{
                    if (kv.second==s2map.find(k)->second)
                    {
                        count++;
                        continue;
                    }else{
                        break;
                    }
                    
                }

            }

            if(count==s1map.size()){
                return true;
            }

            

        }
        return false;
        
        
        
        
    }

int main(){

    string s1 = "abcdxabcde";
    string s2 = "abcdeabcdx";

    bool x = checkInclusion(s1,s2);

    cout<<x<<endl;

    
    
            //printf_vector_int(nums);

}