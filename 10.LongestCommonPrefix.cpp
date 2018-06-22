/*

14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    string prefix = strs[0];
    for(auto elem: strs){
        int n = min(elem.size(), prefix.size());
        int i=0;
        for(i=0; i<n; i++){
            if(elem[i] != prefix[i])
                break;
        }
        prefix = prefix.substr(0,i);
    }
    return prefix;
}

int main() {
  // vector<string> inp = {"dog","racecar","car"};
  // vector<string> inp = {"aa", "a"};
  vector<string> inp = {"flower","flow","flight"};
  cout << longestCommonPrefix(inp);
  return 0;
}