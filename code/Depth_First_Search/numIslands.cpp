#include<vector>
#include<cmath>
#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<queue>


using namespace std;









void dfs(vector<vector<char>>& grid, int c ,int r ){

if ( c < 0 || r < 0|| c>=grid.size() || r >= grid[0].size()){

    return ;

}

if (grid[c][r]=='0' )
{
    return;
}


printf("i %d j %d \n",c,r);
grid[c][r]='0';
dfs(grid,c-1,r);
dfs(grid,c,r-1);
dfs(grid,c+1,r);
dfs(grid,c,r+1);

}


int numIslands_dfs(vector<vector<char>>& grid) {

    int c = grid.size();
    int r = grid[0].size();
    int count = 0;
    for(int i = 0;i < c ;i++){

        for(int j = 0;j<r;j++){
            if(grid[i][j]=='1')
            {
                dfs(grid,i,j);
                count++;
            }
        }
    }
    return count;

        
    } 



int numIslands_bfs(vector<vector<char>>& grid) {

    int c1 = grid.size();
    int r1 = grid[0].size();
    int count = 0;
    for(int i = 0;i < c1 ;i++){

        for(int j = 0;j<r1;j++){
            if(grid[i][j]=='1')
            {
                
                count++;
                grid[i][j]='0';
                queue<pair<int,int>> neighbors;
                neighbors.push({i,j});
                while (!neighbors.empty())
                {
                    /* code */
                    pair<int,int > ij = neighbors.front();
                    neighbors.pop();
                    int r = ij.first;
                    int c = ij.second;
                    
                    if (r-1>=0 && grid[r-1][c]=='1')
                    {
                        /* code */
                        neighbors.push({r-1,c});
                        grid[r-1][c]='0';
                    }
                    if (c-1>=0 && grid[r][c-1]=='1')
                    {
                        /* code */
                        neighbors.push({r,c-1});
                        grid[r][c-1]='0';
                    }
                    if (r+1<grid.size() && grid[r+1][c]=='1')
                    {
                        /* code */
                        neighbors.push({r+1,c});
                        grid[r+1][c]='0';
                    }
                    if (c+1<grid[0].size() && grid[r][c+1]=='1')
                    {
                        /* code */
                        neighbors.push({r,c+1});
                        grid[r][c+1]='0';
                    }
                    
                }
                
                
            }
        }
    }
    return count;

        
    } 

int main(){

vector<vector<int>> image = {{0,0,1,0},{0,0,1,0},{0,0,1,0},{0,0,1,0}};

    vector<vector<char>> image1 = { {'1','1','1','1','0'},{'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};

    numIslands_dfs(image1);

   
    return 0;
    
    
            //printf_vector_int(nums);

}