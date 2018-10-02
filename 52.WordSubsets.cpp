/*
916. Word Subsets

We are given two arrays A and B of words.  Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a. 

Return a list of all universal words in A.  You can return the words in any order.

Example 1:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]
Example 3:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]
Example 4:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]
Example 5:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"]
 

Note:

1 <= A.length, B.length <= 10000
1 <= A[i].length, B[i].length <= 10
A[i] and B[i] consist only of lowercase letters.
All words in A[i] are unique: there isn't i != j with A[i] == A[j].


*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> counter(string& word){
    vector<int> count(26);
    for(auto c:word){
        count[c-'a']++;
    }
    return count;
}

vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<int> temp(26), uni(26);
    int i=0;
    for(auto b:B){
        temp = counter(b);
        for(i=0; i<26; ++i)
            uni[i] = max(uni[i], temp[i]);
    }
    
    vector<string> res;
    for(auto a:A){
        temp = counter(a);
        for(i=0; i<26; ++i){
            if(temp[i]<uni[i])
                break;
        }
        if(i==26)
            res.push_back(a);
    }
    return res;
}


int main(){
    vector<string> A{"amazon","apple","facebook","google","leetcode"}, B{"ec","oc","ceo"};
    vector<string> ans = wordSubsets(A, B);
    for(auto elem:ans)
        cout << elem << " ";
    return 0;
}