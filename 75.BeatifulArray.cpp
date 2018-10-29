/*
932. Beautiful Array

For some fixed N, an array A is beautiful if it is a permutation of the integers 1, 2, ..., N, such that:

For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].

Given N, return any beautiful array A.  (It is guaranteed that one exists.)

Example 1:

Input: 4
Output: [2,1,4,3]
Example 2:

Input: 5
Output: [3,1,2,5,4]

Note:

1 <= N <= 1000

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> beautifulArray(int N) {
    //https://leetcode.com/problems/beautiful-array/discuss/186679/C++JavaPython-Odd-+-Even-Pattern-O(N)
    
    /*With the observations above, we can easily construct any beautiful array.
    Assume we have a beautiful array A with length N

    A1 = A * 2 - 1 is beautiful with only odds from 1 to N * 2 -1
    A2 = A * 2 is beautiful with only even from 2 to N * 2
    B = A1 + A2 beautiful array with length N * 2

    E.g:

    A = [2, 1, 4, 5, 3]
    A1 = [3, 1, 7, 9, 5]
    A2 = [4, 2, 8, 10, 6]
    B = A1 + A2 = [3, 1, 7, 9, 5, 4, 2, 8, 10, 6] */
    
    vector<int> res = {1};
    while (res.size() < N) {
        vector<int> tmp;
        for (int i : res) if (i * 2 - 1 <= N) tmp.push_back(i * 2 - 1);
        for (int i : res) if (i * 2 <= N) tmp.push_back(i * 2);
        res = tmp;
    }
    return res;
}

int main(){
    vector<int> ans = beautifulArray(5);

    for(auto e:ans) cout << e << " " << endl;
    return 0;
}