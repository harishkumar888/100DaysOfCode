/*
888. Uncommon Words from Two Sentences

We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]

Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.

*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void get_word_count(string& A, unordered_map<string, int>& word_count){
    string cur_word;
    for(int i=0; i<A.size(); ++i){
        if(A[i] == ' ' || i==A.size()-1){
            if(i == A.size()-1) cur_word += A[i];
            word_count[cur_word]++;
            cur_word = "";
        }
        else{
            cur_word += A[i];
        }
    }
}

vector<string> uncommonFromSentences_naive(string A, string B) {
    unordered_map<string, int> word_count;
    vector<string> res;
    get_word_count(A, word_count);
    get_word_count(B, word_count);
    for(auto it=word_count.begin(); it!=word_count.end(); ++it){
        if(it->second == 1)
            res.push_back(it->first);
    }
    return res;
}

vector<string> uncommonFromSentences(string A, string B){
    unordered_map<string, int>word_count;
    vector<string> res;
    istringstream iss(A + " " + B);
    while(iss>>A)
        word_count[A]++;
    for(auto word: word_count){
        if(word.second == 1)
            res.push_back(word.first);
    }
    return res;
}

int main(){
    string A = "This apple is sweet";
    string B = "This apple is sour";
    vector<string> ans;
    ans = uncommonFromSentences(A, B);

    for(auto word:ans){
        cout << word << " ";
    }
    return 0;
}