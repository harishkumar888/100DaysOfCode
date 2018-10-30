/*

22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

//For the output string to be right, stack of ")" most be larger than stack of "(". If not, it creates string like "())"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> result;

/*  this hepler function insert result strings to "vector<string> result"
	When number of '(' less than "n", can append '(';
	When number of '(' is more than number of ')', can append ')';

	string s : current string;
	int leftpare_need : number of '(' that have not put into "string s";
	int moreleft : number of '(' minus number of ')' in the "string s";
*/
void helper(string s, int leftparse_need, int moreleft){
    if(leftparse_need == 0 && moreleft == 0){
        result.push_back(s);
        return;
    }
    if(leftparse_need>0){
        helper(s+"(", leftparse_need-1, moreleft+1);
    }
    if(moreleft > 0){
        helper(s+")", leftparse_need, moreleft-1);
    }
}

void helper_alt(string r,int n,int L,int R){
    if(L==n && R==n)
        result.push_back(r);
    if(L<n)
        helper_alt(r+"(",n,L+1,R);
    if(L>R)
        helper_alt(r+")",n,L,R+1);
}

vector<string> generateParentheses(int n){
    helper("", n, 0);
    // helper_alt("", n, 0, 0);
    return result;
}

int main(){
    vector<string> ans = generateParentheses(4);

    for(auto s:ans) cout << s << endl;

    return 0;
}