/*
922. Sort Array By Parity II

Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    int n=A.size();
    vector<int> odd, even;
    for(auto elem:A){
        if(elem%2 == 0)
            even.push_back(elem);
        else
            odd.push_back(elem);
    }
    A.clear();
    for(int i=0; i<n/2; ++i){
        A.push_back(even[i]);
        A.push_back(odd[i]);
    }
    return A;
}

int main(){
    vector<int> A = {4,2,3,5};
    sortArrayByParityII(A);
    for(auto elem:A)
        cout << elem << " ";
    return 0;
}