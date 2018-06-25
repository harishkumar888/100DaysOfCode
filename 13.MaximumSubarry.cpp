/*

53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

DP solution, O(n) time
this problem was discussed by Jon Bentley (Sep. 1984 Vol. 27 No. 9 Communications of the ACM P885)

the paragraph below was copied from his paper (with a little modifications)

algorithm that operates on arrays: it starts at the left end (element A[1]) and scans through to the right end (element A[n]), keeping track of the maximum sum subvector seen so far. The maximum is initially A[0]. Suppose we’ve solved the problem for A[1 .. i - 1]; how can we extend that to A[1 .. i]? The maximum sum in the first I elements is either the maximum sum in the first i - 1 elements (which we’ll call MaxSoFar), or it is that of a subvector that ends in position i (which we’ll call MaxEndingHere).

MaxEndingHere is either A[i] plus the previous MaxEndingHere, or just A[i], whichever is larger.

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums){
  int n=nums.size(), min=0, cur_sum=0, res=nums[0];
  for(int i=0; i<n; ++i){
    cur_sum += nums[i];
    if(cur_sum-min>res) res = cur_sum-min;
    if(cur_sum<min) min = cur_sum;
  }
  return res;
}

int maxSubArray_dp(vector<int>& nums){
    int n=nums.size(), max_val=0;
    vector<int> dp(n);
    dp[0] = nums[0];

    for(int i=0; i<n; ++i){
        dp[i] = nums[i] + (dp[i-1]>0 ? dp[i-1]:0);
        max_val = max(max_val, dp[i]);
    }
    return max_val;
}

// http://ninefu.github.io/blog/056-Maximum_Subarray/

int maxSubArray_alternate(vector<int>& nums){
    int n=nums.size(), max_so_far=nums[0], max_end_here=nums[0];

    for(int i=0; i<n; ++i){
        max_so_far = max(nums[i], max_so_far);
        max_end_here = max(max_so_far, max_end_here);
    }
    return max_so_far;
}

int main() {
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  cout << maxSubArray_dp(nums);
  return 0;
}
