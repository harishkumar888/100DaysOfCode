/*

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int n=nums.size(), lo=0, hi=n-1, mid=0, realmid=0;

    // Find the index of the smallest value using binary search.
    while(lo<hi){
        int mid = (lo+hi)/2;
        if(nums[mid]>nums[hi])
            lo = mid+1;
        else
            hi = mid;
    }

    int rot = lo;
    lo = 0, hi = n-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        int realmid = (mid+rot)%n;
        if(target == nums[realmid]){
            return realmid;
        }
        else if(target>nums[realmid]){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return -1;
}

int search_alt(vector<int>& nums, int target){
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/154836/The-INF-and-INF-method-but-with-a-better-explanation-for-dummies-like-me

    int l = 0, r = nums.size()-1;
    while(l <= r)
    {
        int mid = (r - l)/2 + l;
        int comparator = nums[mid];
        // Checking if both target and nums[mid] are on same side.
        if((target < nums[0]) && (nums[mid] < nums[0]) || (target >= nums[0]) && (nums[mid] >= nums[0]))
            comparator = nums[mid];
        else
        {
            // Trying to figure out where nums[mid] is and making comparator as -INF or INF
            if(target <nums[0])
                comparator = -INFINITY;
            else 
                comparator = INFINITY;
        }

        // Can also be written as
        /*
        comparator = (nums[mid] < nums[0]) == (target < nums[0])
           ? nums[mid] : target < nums[0] ? -INFINITY : INFINITY;
        */
        if(target == comparator) return mid;
        if(target > comparator)            
            l = mid+1;            
        else
            r = mid-1; 
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 6;
    cout << search_alt(nums, target);
    return 0;
}