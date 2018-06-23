/*

852. Peak Index in a Mountain Array

Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1
Example 2:

Input: [0,2,1,0]
Output: 1
Note:

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray_logN(vector<int>& arr){
  int l=0, r=arr.size()-1, mid=0;
  while(l<r){
    mid = (l+r)/2;
    if(arr[mid]<arr[mid+1])
      l = mid;
    else if(arr[mid-1]>arr[mid])
      r = mid;
    else
      return mid;
  }
}

int peakIndexInMountainArray_N(vector<int> A) {
   return max_element(A.begin(), A.end()) - A.begin();
}

int main() {
  vector<int> inp = {1,3,4,5,6,8,17,15,12,10,3,1};
  cout << inp[peakIndexInMountainArray_logN(inp)];
  return 0;
}
