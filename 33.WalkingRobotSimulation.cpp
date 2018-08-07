/*

874. Walking Robot Simulation

A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)

Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;


int distance(const vector<int>& current){
    return pow(current[0], 2) + pow(current[1], 2);
}

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int direction=1, x=0, y=0, ret=0;
    vector<int> current{0,0};
    set<vector<int>> s{begin(obstacles), end(obstacles)};
    const vector<vector<int>> dir{{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    for(int i=0; i<commands.size(); ++i){
        if(commands[i] == -1){
            if(++direction == 4) direction = 0;
        }
        else if(commands[i] == -2){
            if(--direction == -1) direction = 3;
        }
        else{
            for(int j=0; j<commands[i]; ++j){
                current[0] += dir[direction][0];
                current[1] += dir[direction][1];
                if(s.count(current)){
                    current[0] -= dir[direction][0];
                    current[1] -= dir[direction][1];
                    break;
                }
                ret = max(ret, distance(current));
            }
        }
    }
    return ret;
}

int main(){
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2, 4}};
    cout << robotSim(commands, obstacles);
    return 0;
}