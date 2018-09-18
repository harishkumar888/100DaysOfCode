/*
905. Sort Array By Parity

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    /*Inplace*/
    int start = 0, end = A.size()-1;
    while(start<end){
        if(A[start]%2 == 0){
            start++;
        }
        else{
            int swap_val = A[start];
            A[start]  = A[end];
            A[end] = swap_val;
            end--;
        }
    }
    return A;
}

int main()
{
    vector<int> vec = {3,1,2,4};
    vector<int> res = sortArrayByParity(vec);

    for(auto elem:res)
    {
        cout << elem << " " << endl;
    }
    return 0;
}