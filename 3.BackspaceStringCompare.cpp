/*
Leetcode problem
844. BackSpace String Compare

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
 

Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
*/

#include <iostream>

using namespace std;

bool backspaceCompare(string S, string T) {
    int i=0, j=0;
    while(i<S.size() && j<S.size()){
        if(S[j] != '#'){
            S[i++] = S[j++];
        }
        else{
          if(i>0)
            i--;
            j++;
        }
    }
    S = S.substr(0,i);
    i=0,j=0;
    while(i<T.size() && j<T.size()){
        if(T[j] != '#'){
            T[i++] = T[j++];
        }
        else{
          if(i>0)
            i--;
            j++;
        }
    }
    T = T.substr(0,i);
    return S==T;
}

int main(){
    cout << boolalpha << backspaceCompare("a##c", "#a#c");
    return 0;
}
