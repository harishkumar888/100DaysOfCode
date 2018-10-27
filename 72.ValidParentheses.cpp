/*
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

char getMatching(char c){
    if(c == ')')
        return '(';
    else if(c == ']')
        return '[';
    else
        return '{';
}

bool isClosing(char c){
    return (c==')' || c==']' || c=='}');    
}

bool isValid_naive(string s) {
    if(s == "") return true;
    stack<char> sc;
    for(auto c:s){
        if(sc.empty()){
            if(isClosing(c)) return false;
            sc.push(c);
        }else{
            if(isClosing(c)){
                if(sc.top() == getMatching(c)){
                    sc.pop();
                }
                else{
                    return false;
                }
            }else{
                sc.push(c);
            }
        }
    }
    return sc.empty();
}

bool isValid(string s) {
    stack<char> paren;
    for (char& c : s) {
        switch (c) {
            case '(': 
            case '{': 
            case '[': paren.push(c); break;
            case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
            case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
            case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
            default: ; // pass
        }
    }
    return paren.empty() ;
}

int main(){
    cout << boolalpha << isValid("()[]") << endl;
    cout << boolalpha << isValid("()[]{}") << endl;
    cout << boolalpha << isValid("(]") << endl;
    cout << boolalpha << isValid("([)]") << endl;
    cout << boolalpha << isValid("{[]}") << endl;
    return 0;
}