/*

713. Subarray Product Less Than K

Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.

*/

#include <iostream>
#include <vector>

using namespace std;

// Works but not efficient. Will exceed memory limit on leetcode.
int numSubarrayProductLessThanK_naive(vector<int>& nums, int k) {
    vector<vector<int>> res;
    for(int i=0; i<nums.size(); ++i){
        int prod=nums[i];
        vector<int> cur_vec = {nums[i]};
        if(nums[i]<k) res.push_back(cur_vec);
        for(int j=i+1; j<nums.size(); ++j){
            cur_vec.push_back(nums[j]);
            prod *= nums[j];
            if(prod>=k || j == nums.size()){
                break;
            }
            res.push_back({cur_vec});
        }
    }

    // print the result
    // for(auto elem: res){
    //     for(auto elem1:elem){
    //         cout << elem1 << " ";
    //     }
    //     cout << endl;
    // }

    return res.size();
}

int numSubarrayProductLessThanK(vector<int>& nums, int k){


}

int main(){
    vector<int> nums = {10,5,2,6};
    int k = 100;
    numSubarrayProductLessThanK(nums, k);
    return 0;
}
