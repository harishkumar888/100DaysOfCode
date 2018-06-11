/*
848. Shifting Letters
User Accepted: 1447
User Tried: 1750
Total Accepted: 1480
Total Submissions: 4970
Difficulty: Medium
We have a string S of lowercase letters, and an integer array shifts.

Call the shift of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a'). 

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.

Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times.

Return the final string after all such shifts to S are applied.

Example 1:

Input: S = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: 
We start with "abc".
After shifting the first 1 letters of S by 3, we have "dbc".
After shifting the first 2 letters of S by 5, we have "igc".
After shifting the first 3 letters of S by 9, we have "rpl", the answer.
Note:

1 <= S.length = shifts.length <= 20000
0 <= shifts[i] <= 10 ^ 9
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Naive implementation. Time out on leetcode.
string shiftingLetters_naive(string S, vector<int>& shifts) {
    for(int i=0; i<shifts.size(); ++i){
        shifts[i] = shifts[i]%26;
        for(int j=0; j<i+1; ++j){
            if(S[j]+shifts[i] > 122)
                S[j] += shifts[i]-26;
            else
                S[j] += shifts[i];
        }
    }
    return S;
}

string shiftingLetters(string S, vector<int>& shifts) {
  int delta=0;
  int shidx = shifts.size()-1;
  for(int i=S.size()-1; i>=0; --i){
    delta = (delta+shifts[shidx--])%26;
    if(S[i]+delta > 'z')
      S[i] += delta-26;
    else
      S[i] += delta;
  }
  return S;
}

int main() {
  vector<int> vec = {10,20,30};
  cout << shiftingLetters("bad", vec);
  return 0;
}