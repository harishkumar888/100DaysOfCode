/*
921. Minimum Add to Make Parentheses Valid

Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

Example 1:

Input: "())"
Output: 1
Example 2:

Input: "((("
Output: 3
Example 3:

Input: "()"
Output: 0
Example 4:

Input: "()))(("
Output: 4

Note:

S.length <= 1000
S only consists of '(' and ')' characters.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int minAddToMakeValid_naive(string S) {
    int res=0;
    stack<char> stck;
    for(auto elem: S){
        if(elem == '('){
            stck.push(elem);
        }
        else if(elem == ')'){
            if(!stck.empty() && stck.top() == '('){
                stck.pop();
            }
            else{
                res++;
            }
        }
    }
    
    while(!stck.empty()){
        res++;
        stck.pop();
    }
    
    return abs(res);
}

int minAddToMakeValid(string S) {
    int c = 0, ans = 0;
    for (auto e : S) {
        if (e == '(') c++;      // keep track of left parens on "stack"
        else if (c == 0) ans++; // if missing left paren when needed, ++
        else c--;               // reduce left paren count when matched
    }
    return c + ans;             // add the unmatched left parens at the end
}

int main(){
    cout << minAddToMakeValid("()))");;
    return 0;
}