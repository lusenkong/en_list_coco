#include<vector>
#include<cmath>
#include<stdio.h>
#include<iostream>
#include<map>



using namespace std;

void print_map(map<int,int> map1){

    for (auto kv :map1)
    {
        printf("key %d ",kv.first);
        printf("value %d \n",kv.second);
        /* code */
    }
    

}


void print_list(vector<int> list1){
    for (int i = 0; i < list1.size(); i++)
    {
        /* code */

        printf("index %d value %d \n",i,list1[i]);
    }
    

}

int main(){

    ///map

    map<int,int> map1 = {{1,2},{2,3}};
    map<int,int> map2 = {};
    map<int,int> map3;
    
    map3[3] = 4;
    map3[4]++;
    map3[3] = 5;
    map3.insert({6,3});
    //map3.emplace();


    /// vector

    vector<int>  list1 = {};
    vector<int>  list2 = {1};
    vector<int>  list3(5,3);

    print_map(map3);
    print_list(list1);

}