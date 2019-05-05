/*
5051. Valid Boomerang
User Accepted: 77
User Tried: 155
Total Accepted: 77
Total Submissions: 173
Difficulty: Easy
A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.

 

Example 1:

Input: [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: [[1,1],[2,2],[3,3]]
Output: false
 

Note:

points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool isBoomerang(vector<vector<int>>& points) {
    set<vector<int>> s{points.begin(), points.end()};
    if(s.size() != points.size())
        return false;
    
    double num1 = points[0][1]-points[1][1];
    double den1 = points[0][0]-points[1][0];
    double num2 = points[1][1]-points[2][1];
    double den2 = points[1][0]-points[2][0];
    double ratio1 = (den1 == 0) ? INT_MAX: num1/den1;
    double ratio2 = (den2 == 0) ? INT_MAX: num2/den2;
    return ratio1 != ratio2;
}

int main(){
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    cout << boolalpha << isBoomerang(points);
}