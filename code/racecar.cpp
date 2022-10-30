
#include <stdio.h>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#include<iostream>
#include<unordered_set>
using namespace std;


int bfsSol(int target) {
        // <position, speed>
        queue<tuple<long long, long long> > q;
        unordered_set<string> visited;
        vector<char> instructions = {'A', 'R'};
        int count = 0;
        
        q.push({0, 1});
        visited.emplace(to_string(0) + "," + to_string(1));
        int level = 0, level_nodes = q.size();
        
        while(!q.empty()) {
            count++;
            auto [pos, speed] = q.front();
            q.pop();
            
            if(pos == target) 
                break;
            
            --level_nodes;
            
            for(auto instruction: instructions) {
                long long position = pos, new_speed = speed;
                
                if(instruction == 'A') {
                    position += speed;
                    new_speed *= 2;
                }   
                else 
                    new_speed = new_speed > 0 ? -1 : 1;
                // Since we are looking for +ve target
                // We move in 0, 2, 4, 8, ...k, 2k manner
                // We can reach the target via two ways:
                // 1. Accelarate + Reverse until pos < target
                // 2. Go past the target and then comeback via reversing
                if(position < 0 || position > 2 * target)
                    continue;
                string state = to_string(position) + "," + to_string(new_speed);
                if(!visited.count(state)) {
                    q.push({position, new_speed});
                    visited.emplace(state);
                }
            }
            
            // end of level
            if(level_nodes == 0 && !q.empty()) {
                ++level;
                level_nodes = q.size();
            }
        }
        printf("count: %d \n",count);
        return level;
    }

std::tuple<int,int,int> command_r(std::tuple<int,int,int> attribute){

std::tuple<int,int,int> result;

if (get<1>(attribute)>0)
{
    /* code */
    get<1>(result) = -1;

}else{
    get<1>(result)  = 1;
}
get<0>(result)= get<0>(attribute);
get<2>(result)= get<2>(attribute)+1;

return result;

}

std::tuple<int,int,int> command_a(std::tuple<int,int,int> attribute){
    std::tuple<int,int,int> result;

    get<0>(result)= get<0>(attribute)+get<1>(attribute);
    get<1>(result) = get<1>(attribute)*2;
    get<2>(result)= get<2>(attribute)+1;
    return result;
}


int racecar(int target) {


    queue<vector<int>> task ;
    task.push({0,1,0});

    while (!task.empty())
    {
        vector<int> cur = task.front();
        task.pop();
        int pos = cur[0];
        int speed = cur[1];
        int steps = cur[2];


        if (pos==target)

        {
            return steps;
            /* code */
        }

        if ((pos+speed)<=10000 && (pos+speed)>0)
        {
            /* code */

            task.push({pos+speed,speed*2,steps+1});

        }

        if (speed>0 && (pos+speed)>target)
        {
            /* code */
            task.push({pos,-1,steps+1});
        }
        
        
        if (speed<0 && (pos+speed)<target)
        {
            /* code */
            task.push({pos,1,steps+1});
        }
        
        

    }
    return -1;

    }
    
    

int main(){

//araa  6;

// 0,1-> 1,2->1,-1
int s =2;
printf("start  \n");
int result = bfsSol(s);

printf("result : %d \n",result);
printf("start  \n");
int result1  = racecar(s);

printf("result1 : %d \n",result1);
}