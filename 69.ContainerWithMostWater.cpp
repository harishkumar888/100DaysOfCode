/*
11. Conainter with most water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxArea_naive(vector<int>& height) {
    int n = height.size(), res=-1;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(height[i]>height[j])
                res = max(res, height[j]*(j-i));
            else
                res = max(res, height[i]*(j-i));
        }
    }
    return res;
}

int maxArea(vector<int>& height){
/* Idea
1. The widest container (using first and last line) is a good candidate, because of its width.
   Its water level is the height of the smaller one of first and last line.
2. All other containers are less wide and thus would need a higher water level in order to hold more water.
3. The smaller one of first and last line doesn't support a higher water level and can thus 
   be safely removed from further consideration.
*/

    int i=0, j=height.size()-1;
    int res = 0;
    while(i<j){
        int height_cur = min(height[i], height[j]);
        res = max(res, height_cur*(j-i));
        if(height[i] < height[j]){
            i += 1;
        }
        else{
            j -= 1;
        }
    }
    return res;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    return 0;
}