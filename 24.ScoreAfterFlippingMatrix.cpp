/*

861. Score After Flipping Matrix

We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.


Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

Note:

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] is 0 or 1.

*/

#include<iostream>
#include<vector>

using namespace std;

void flipRow(vector<vector<int>>& A, int row, int n){
    for(int j=0; j<n; ++j){
        A[row][j] = (A[row][j] == 0) ? 1:0;
    }
}

void flipCol(vector<vector<int>>& A, int col, int m){
    for(int i=0; i<m; ++i){
        A[i][col] = (A[i][col] == 0) ? 1:0;
    }
}

int matrixScore(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size(), res=0, zeros=0;
    vector<int> col(n, 0);
    // Convert the first element in each row to 1.
    for(int i=0; i<m; ++i){
        if(A[i][0] == 0)
            flipRow(A, i, n);
    }
    
    for(int i=1; i<n; ++i){
        zeros = 0;
        for(int j=0; j<m; ++j){
            if(A[j][i] == 0) zeros++;
        }
        if(zeros>m/2)
            flipCol(A, i, m);
    }

    int sum=0;
    for(int i=0; i<m; ++i){
        sum = 0;
        for(int j=0; j<n; ++j){
            if(A[i][j] == 1)
                sum += pow(2,n-1-j);
        }
        res += sum;
    }

    return res;
}

// Alternate solution
// int matrixScore(vector<vector<int>> A) {
//     int M = A.size(), N = A[0].size(), res = (1 << (N - 1)) * M;
//     for (int j = 1; j < N; j++) {
//         int cur = 0;
//         for (int i = 0; i < M; i++) cur += A[i][j] == A[i][0];
//         res += max(cur, M - cur) * (1 << (N - j - 1));
//     }
//     return res;
// }


int main(){
    // vector<vector<int> > A = {{0,1},{1,1}};
    vector<vector<int> > A = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << matrixScore(A);
    return 0;
}
