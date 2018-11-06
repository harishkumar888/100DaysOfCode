/*
34. Find First and Last Position Of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange_naive(vector<int>& nums, int target) {
    int l=0, r=nums.size()-1, n=nums.size()-1;
    vector<int> res{-1,-1};
    while(l<=r){
        int mid = (l+r)/2;
        if(nums[mid]<target){
            l=mid+1;
        }
        else if(nums[mid]>target){
            r=mid-1;
        }
        else{
            l=mid;
            r=mid;
            while(nums[l]==target)--l;
            while(nums[r]==target)++r;
            res = {max(0,l+1),min(n,r-1)};
            break;
        }
    }
    return res;
}

vector<int> searchRange(vector<int>& nums, int target){
    int start = 0, end = nums.size(), mid, left, right;
    while(start<end){
        mid = (start+end)/2;
        if(nums[mid] >= target)
            end = mid;
        else
            start = mid+1;
    }
    // Left found. Search for the right.
    left = start;
    end = nums.size();
    while(start<end){
        mid = (start+end)/2;
        if(nums[mid]>target)
            end = mid;
        else
            start = mid+1;
    }
    right = start;
    return left == right ? vector<int> {-1, -1} : vector<int> {left, right-1};
}

int main(){
    vector<int> ans = searchRange(vector<int>{5,7,7,8,8,10}, 8);
    cout << ans[0] << " " << ans[1] << endl;
    ans = searchRange(vector<int>{5,7,7,8,8,10}, 6);
    cout << ans[0] << " " << ans[1] << endl;
    ans = searchRange(vector<int>{0,0,0,1,2,3}, 0);
    cout << ans[0] << " " << ans[1] << endl;
    ans = searchRange(vector<int>{1}, 1);
    cout << ans[0] << " " << ans[1] << endl;
    ans = searchRange(vector<int>{1,3}, 1);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}