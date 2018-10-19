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
    /**
 * Solution (DP, O(n)):
 * 
 * Assume L[i] = s[m...i], denotes the longest substring without repeating
 * characters that ends up at s[i], and we keep a hashmap for every
 * characters between m ... i, while storing <character, index> in the
 * hashmap.
 * We know that each character will appear only once.
 * Then to find s[i+1]:
 * 1) if s[i+1] does not appear in hashmap
 *    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
 * 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
 *    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
 *    entry in hashmap to mark the latest occurency of s[i+1].
 * 
 * Since we scan the string for only once, and the 'm' will also move from
 * beginning to end for at most once. Overall complexity is O(n).
 *
 * If characters are all in ASCII, we could use array to mimic hashmap.
 */
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for(int i=0; i != s.length(); ++i){
        if(dict[s[i]] > start)
            start = dict[s[i]];
            /* Can also be written as
            start = max(dict[s[i]], start);
            */
        dict[s[i]] = i;
        maxLen = max(maxLen, i-start);
    }
    return maxLen;
}

int main(){
    cout << lengthOfLongestSubstring("tmmuzxt");
    return 0;
}