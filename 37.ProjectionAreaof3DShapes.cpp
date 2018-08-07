/*

887. Projection Area of 3D Shapes

On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Now we view the projection of these cubes onto the xy, yz, and zx planes.

A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane. 

Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

Return the total area of all three projections.

Example 1:

Input: [[2]]
Output: 5
Example 2:

Input: [[1,2],[3,4]]
Output: 17
Explanation: 
Here are the three projections ("shadows") of the shape made with each axis-aligned plane.

Example 3:

Input: [[1,0],[0,2]]
Output: 8
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 14
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 21

Note:

1 <= grid.length = grid[0].length <= 50
0 <= grid[i][j] <= 50

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int projectionArea_naive(vector<vector<int>>& grid) {
    int res = 0;
    
    //Front view
    for(int i=0; i<grid.size(); ++i){
        int cur_max = 0;
        for(int j=0; j<grid[0].size(); ++j){
            cur_max = max(cur_max, grid[i][j]);
        }
        res += cur_max;
    }
    
    //Side view
    for(int j=0; j<grid[0].size(); ++j){
        int cur_max = 0;
        for(int i=0; i<grid.size(); ++i){
            cur_max = max(cur_max, grid[i][j]);
        }
        res += cur_max;
    }
    
    // Top view
    for(int i=0; i<grid.size(); ++i){
        int cur_max = 0;
        for(int j=0; j<grid[0].size(); ++j){
            if(grid[i][j] != 0) res++;
        }
        res += cur_max;
    }
    return res;
}

int projectionArea(vector<vector<int>>& grid){
    int res = 0, x=0, y=0, z=0;
    for(int i=0; i<grid.size(); ++i){
        int mx=0, my=0;
        for(int j=0; j<grid[0].size(); ++j){
            mx = max(mx, grid[j][i]);
            my = max(my, grid[i][j]);
            if(grid[i][j] > 0) z++;
        }
        x += mx;
        y += my;
    }
    return x + y + z;
}


int main(){
    vector<vector<int>> grid = {{1,1,1},{1,0,1},{1,1,1}};
    cout << projectionArea(grid);
    return 0;
}