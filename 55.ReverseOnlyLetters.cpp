/*
917. Reverse Only Letters

Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "

*/

#include <iostream>
#include <string>

using namespace std;

string reverseOnlyLetters(string S) {
    int l=0, r=S.size()-1;
    int n = S.size();
    for(int l=0, r=n-1; l<r;){
        if(!isalpha(S[l])){
            l++;
        }
        else if(!isalpha(S[r])){
            r--;
        }
        else{
            swap(S[l++], S[r--]);
        }
    }
    return S;
}

int main(){
    cout << reverseOnlyLetters("Test1ng-Leet=code-Q!");
    return 0;
}