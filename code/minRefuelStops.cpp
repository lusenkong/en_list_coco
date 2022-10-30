
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


set<int>  steps;

void move_on(int target, long long cur_fuel, int cur_station, vector<vector<int>>& stations,int step){
     printf("%d : %d : %d\n",cur_fuel,cur_station,step);
    // containing cur_fuel when arriving cur_station

    if (cur_station==stations.size()-1)
    {       
        
        if ((cur_fuel>=target-stations.back()[0]))
        {
            /* code */
            steps.insert(step);
            }
            else if ((cur_fuel+stations.back()[1])>=(target-stations.back()[0]))
            {
                /* code */
                steps.insert(++step);
            }else{

                steps.insert(-1);
            }
    return ;
    }

       
        if (cur_fuel>=(stations[cur_station+1][0]-stations[cur_station][0]))
        {
            move_on(target,cur_fuel-(stations[cur_station+1][0]-stations[cur_station][0]),cur_station+1,stations,step);
        }
         if (cur_fuel+stations[cur_station][1]>=(stations[cur_station+1][0]-stations[cur_station][0]))
        {
            move_on(target,stations[cur_station][1]+cur_fuel-(stations[cur_station+1][0]-stations[cur_station][0]),cur_station+1,stations,step+1);//refuel
        }
        
        
    
    return ;


}

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

    if (stations.size()==0)
    {
        /* code */
        if (startFuel>=target)
        {
            /* code */
            return 0;
        }else{
            return -1;
        }
        
    }
    

    if (startFuel-stations[0][0]<0)
    {
        /* code */
        return -1;
    }
    
    //stations.insert(stations.begin(), {0,startFuel});
    move_on(target,startFuel-stations[0][0],0,stations,0);
    printf("size of step: %d \n",int(steps.size()));
    for (int k:steps)
    {
        /* code */
        printf("step: k %d\n",k);
        if (k!=-1)
        {
            /* code */
            return k;
        }
    }
    
        return -1;
    }

int main(){

vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
int target = 100;
int  startFuel = 10;


stations = {{5,1000000000},{1000,1000000000},{100000,1000000000}};
target = 1000000000;
startFuel = 1000000000;

int flag = minRefuelStops(target,startFuel,stations);

cout<<flag<<endl;

}