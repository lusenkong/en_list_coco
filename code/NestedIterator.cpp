
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


class _NestedIterator_ {
public:
    virtual int next() ;
    virtual bool hasNext();
};
    
class NestedIterator {
private:
    vector<NestedInteger> v;
    queue<int> q;
    
    void getAllIntegers(vector<NestedInteger> &v, queue<int>& q){
        for(auto& ele: v){
            if(ele.isInteger()) q.push(ele.getInteger());
            else {
                auto listItems = ele.getList();
                getAllIntegers(listItems, q);
            }
        }
    }
public:

    NestedIterator(vector<NestedInteger> &nestedList) {
        v = nestedList;
        getAllIntegers(v, q);
    }
    
    int next() {
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    bool hasNext() {
        return q.size() > 0;
    }
};

int main(){

//araa  6;

// 0,1-> 1,2->1,-1
int s =2;


}