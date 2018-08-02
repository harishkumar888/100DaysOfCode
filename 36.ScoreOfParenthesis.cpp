/*

856. Score of Parentheses

Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50

*/

#include <iostream>
#include <stack>

using namespace std;

int scoreOfParentheses_naive(string S) {
    stack<int> stk;
    for(auto elem:S){
        if(elem == '('){
            stk.push(-1);
        }
        else{
            int cur=0;
            while(stk.top() != -1){
                cur += stk.top();
                stk.pop();
            }
            stk.pop();
            stk.push(cur==0? 1 : cur*2);
        }
    }
    int res=0;
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    return res;
}

int scoreOfParentheses(string S){
    int res=0, layers=0;
    for(int i=0; i<S.size(); ++i){
        if(S[i] == '(')
            layers++;
        else
            layers--;
        if(S[i] == '(' && S[i+1] == ')')
            res += 1 << (layers-1);
    }
    return res;
}

int main(){
    cout << scoreOfParentheses("(()(()))");
    return 0;
}