/*
890. Find and Replace Pattern

You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 

Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20

*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


vector<int> vectorize(string pattern){
    vector<int> res;
    int itr=0;
    map<char, int> char_map;
    for(int i=0; i<pattern.size(); ++i){
        char cur = pattern[i];
        if(char_map.find(cur) == char_map.end())
            char_map[cur] = ++itr;
        res.push_back(char_map[cur]);
    }
    return res;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> res;
    vector<int> pattern_vec = vectorize(pattern);
    for(auto word:words)
        if(vectorize(word) == pattern_vec)
            res.push_back(word);
    return res;
}

int main(){
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> answer = findAndReplacePattern(words, pattern);

    for(auto elem:answer)
        cout << elem << " ";

    return 0;
}