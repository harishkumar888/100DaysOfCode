/*
Leetcode problem
845. Longest Mountain in Array

Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

 

Example 1:

Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: [2,2,2]
Output: 0
Explanation: There is no mountain.
 

Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestMountain2Pass(vector<int>& A){
  int N=A.size(), res=0;
  vector<int> down(N, 0), up(N, 0);
  for(int i=N-2; i>=0; --i){
    if(A[i] > A[i+1])
      down[i] = down[i+1]+1;
  }
  for(int i=0; i<N; ++i){
    if(A[i] > A[i-1])
      up[i] = up[i-1]+1;
    if(up[i] && down[i])
      res = max(res, up[i]+down[i]+1);
  }
  return res;
}

int longestMountain1Pass(vector<int>& A){
  int res=0;
  int i=0, up=0, down=0;

  for(int i=1; i<A.size(); ++i){
    if(down && A[i] > A[i-1] || A[i] == A[i-1])
      up=down=0;
    up += A[i] > A[i-1];
    down += A[i] < A[i-1];
    if(up && down)
      res = max(res, up+down+1);
  }
  return res;
}

int main() {
  // vector<int> A={2,2,2};
  vector<int> A={2,1,4,7,3,2,5};
  
  // 2 pass solution
  cout << longestMountain2Pass(A) << endl;

  // 1 pass solution
  cout << longestMountain1Pass(A) << endl;
  return 0;
}