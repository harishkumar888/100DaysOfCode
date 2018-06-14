/*
5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s){
  int i=0, j=s.size()-1;
  while(i<=j){
    if(s[i] != s[j])
      return false;
    else
      i++;
      j--;
  }
  return true;
}

string longestPalindrome_naive(string s) {
  string longest_pali = "";
  if(s.size() == 1) return s;
  for(int i=0; i<s.size(); ++i){
    for(int j=1; j<s.size(); ++j){
      string cur_str = s.substr(i,j-i+1);
      if(is_palindrome(cur_str) && cur_str.size() > longest_pali.size())
        longest_pali = cur_str;
    }
  }
  return longest_pali;
}

string longestPalindrome(string s){
  
}

int main() {
  cout << longestPalindrome_naive("a");
  
  return 0;
}