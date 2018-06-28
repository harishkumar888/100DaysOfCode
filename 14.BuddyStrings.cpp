/*

859. Buddy Strings

Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false

Solution:
If A.length() != B.length(): no possible swap

If A == B, we need swap two same characters. Check is duplicated char in A.

In other cases, we find index for A[i] != B[i]. There should be only 2 diffs and it's our one swap.
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool buddyStrings(string A, string B) {
    int n_a=A.size(), n_b=B.size();
    vector<int> diff;
    if(n_a != n_b) return false;
    
    if(A==B && set<char>(A.begin(), A.end()).size() < A.size())
        return true;
    
    for(int i=0; i<n_a; ++i){
        if(A[i] != B[i]){
            diff.push_back(i);
        }
    }
    if(diff.size() != 2) return false;
    if(A[diff[0]] != B[diff[1]] || A[diff[1]] != B[diff[0]]) return false;
    return true;

    // Alternate way to do the same.
    //return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
}

int main(){
    cout << boolalpha << buddyStrings("ab", "ba");
    return 0;
}