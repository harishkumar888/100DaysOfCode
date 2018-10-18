/*

15. 3sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum_naive(vector<int>& nums) {
        // Does not check for duplicates
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n=nums.size();
    for(int i=0; i<n; ++i){
        vector<int> cur;
        int j=0, k=n-1;
        while(j<k && j!=i && j!=k && i!=k){
            if(nums[j]+nums[k]<-nums[i]){
                j++;
            }
            else if(nums[j]+nums[k]>-nums[i]){
                k--;
            }
            else if(nums[j]+nums[k] == -nums[i]){
                cur.push_back(nums[i]);
                cur.push_back(nums[j]);
                cur.push_back(nums[k]);
                res.push_back(cur);
                j++; k--;
            }
        }
    }
    return res;
}



vector<vector<int>> threeSum(vector<int>& nums) {
    // Does not check for duplicates
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    int n=nums.size();
    for(int i=0; i<n; ++i){
        int front=i+1, back=n-1, target = -nums[i];
        while(front<back){
            int cur_sum = nums[front] + nums[back];
            if(cur_sum < target){
                front++;
            }
            else if(cur_sum > target){
                back--;
            }
            else{
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[front];
                triplet[2] = nums[back];
                res.push_back(triplet);


                /*A good approach is to jump over the number which
                has been scanned, no matter whether it is a part of some solution or not.
                If the three numbers formed a solution, we can safely ignore all
                the duplicates of them. We can do this to all the three numbers
                such that we can remove the duplicates.*/

                //process duplicates of number 2
                while(front<back && nums[front] == triplet[1]) front++;

                //Process duplicates of number 3
                while(front<back && nums[back] == triplet[2]) back--;
            }
        }
        //Process duplicates of number 1
        while(i+1 < nums.size() && nums[i+1] == nums[i])
            i++;
    }
    return res;
}

int main(){
    vector<int> nums = {0,0,0,0,0,0};
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    for(auto vec:ans){
        for(auto elem:vec){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
