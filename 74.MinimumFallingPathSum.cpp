/*
931. Minimum Falling Path Sum

Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minFallingPathSum(vector<vector<int>>& A){
    int m = A.size(), n = A[0].size();
    for(int i=m-2; i>=0; --i){
        for(int j=0; j<n; ++j){
            if(j>0 && j<n-1){
                A[i][j] += min(A[i+1][j], min(A[i+1][j-1], A[i+1][j+1]));
            }
            else if(j == 0){
                A[i][j] += min(A[i+1][j], A[i+1][j+1]);
            }
            else{
                A[i][j] += min(A[i+1][j-1], A[i+1][j]);
            }
        }
    }
    return *min_element(begin(A[0]), end(A[0]));
}

int minFallingPathSum_concise(vector<vector<int>>& A) {
  for (auto i = 1; i < A.size(); ++i)
    for (auto j = 0; j < A.size(); ++j)
      A[i][j] += min(A[i-1][j], min(A[i-1][max(0,j-1)], A[i-1][min((int)A.size()-1,j+1)]));
  return *min_element(begin(A[A.size() - 1]), end(A[A.size() - 1]));
}

int main(){
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    cout << minFallingPathSum(A);
    return 0;
}