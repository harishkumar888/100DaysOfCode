/*
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

From the Wikipedia page, in the 14th century, a man named Narayana Pandita gives the following classic and yet quite simple algorithm (with minor modifications in notations to fit the problem statement):

Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is sorted in descending order, just reverse it to ascending order and we are done. For example, the next permutation of [3, 2, 1] is [1, 2, 3].
Find the largest index l greater than k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array from nums[k + 1] to nums[nums.size() - 1].

*/

#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n-2;
    if(nums.empty() || n<1) return;
    while(i>=0 && nums[i] >= nums[i+1]) // Find 1st id i that breaks descending order
        i--;
    
    if(i>=0){                           // If not entirely descending
        int j = n-1;              // Start from the end
        while(nums[j] <= nums[i]) // Find rightmost first larger id j
            j--;
        swap(nums[i], nums[j]);   // Swap i and j
    }
    reverse(nums.begin()+i+1, nums.end()); // Reverse the descending sequence.
}

int main(){
    vector<int> nums = {1,3,2};
    nextPermutation(nums);
    for(auto elem: nums){
        cout << elem << " ";
    }
    return 0;
}