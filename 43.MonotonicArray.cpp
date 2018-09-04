/*
896. Monotonic Array

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true

Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic_naive(vector<int>& A) {
    int det = 0;
    bool mono=true;
    for(int i=0; i<A.size()-1; ++i){
        if(A[i] > A[i+1]){
            if(det == 2)
                return false;
            else
                det = 1;
        }else if(A[i] < A[i+1]){
            if(det == 1)
                return false;
            else
                det = 2;
        }
    }
    return mono;
}

bool isMonotonic(vector<int>& A){
    return is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend());
}

bool isMonotonic_alt(vector<int> A) {
    bool inc = true, dec = true;
    for (int i = 1; i < A.size(); ++i){
        inc &= A[i - 1] <= A[i];
        dec &= A[i - 1] >= A[i];
    }
    return inc || dec;
}

int main(){
    cout << boolalpha << isMonotonic(vector<int>{1,2,2,3});
    return 0;
}
