/*
939. Minimum Area Rectangle

Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 

Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int minAreaRect_naive(vector<vector<int>>& points) {
    int res = INT_MAX;
    set<vector<int>> seen;
    for(int i=0; i<points.size(); ++i){
        vector<int> cpoint = points[i];
        for(vector<int> pt:seen){
            if(seen.find({cpoint[0], pt[1]}) != seen.end() &&
               seen.find({pt[0], cpoint[1]}) != seen.end()){
                int area = abs(cpoint[0]-pt[0]) * abs(cpoint[1]-pt[1]);
                if(area != 0 && area < res){
                    res = area;
                }
            }
        }
        seen.insert(cpoint);
    }
    return res < INT_MAX ? res : 0;
}

int minAreaRect(vector<vector<int>>& points) {
    int n=points.size();
    if(n<=3)
        return 0;
    bool find=false;
    int res=INT_MAX;
    set<pair<int, int>> s;
    for(auto p:points){
        s.insert({p[0], p[1]});
    }
    
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            int x1=points[i][0];
            int x2=points[j][0];
            int y1=points[i][1];
            int y2=points[j][1];
            if(x1==x2 || y1==y2)
                continue;
            if(abs((x1-x2)*(y1-y2))>=res)
                continue;
            if(s.find({x1, y2}) != s.end() && s.find({x2, y1}) != s.end()){
                find=true;
                res=min(res, abs((x1-x2)*(y1-y2)));
            }
        }
    }
    if(!find)
        return 0;
    return res;
    
}

int main(){
    vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
    cout << minAreaRect(points);
    return 0;
}