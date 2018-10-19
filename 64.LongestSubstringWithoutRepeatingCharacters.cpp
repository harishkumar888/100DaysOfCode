/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, 
             "pwke" is a subsequence and not a substring.

*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring_incorrect(string s) {
    map<char, int> m;
    int n = s.size(), count = 0, ans=0;
    for(int i=0; i<n ;++i){
        if(m.find(s[i]) != m.end()){
            count = min(count, i - m[s[i]]);
        }else{
            count++;
        }
        m[s[i]] = i;
        ans = max(ans, count);
    }
    return ans;
}

int lengthOfLongestSubstring(string s){
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for(int i=0; i != s.length(); ++i){
        if(dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = max(maxLen, i-start);
    }
    return maxLen;
}

int main(){
    cout << lengthOfLongestSubstring("tmmuzxt");
    return 0;
}