/*
9. Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Could you solve it without converting the integer to a string?
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindromeViaString(int x) {
    string xs = to_string(x);
    if(x<0) return false;
    int i=0, j=xs.size()-1;
    while(i<j){
        if(xs[i] != xs[j])
            return false;
        i++,j--;
    }
    return true;
}

bool isPalindrome(int x) {
    if(x<0 || (x != 0 && x%10 == 0)) return false;
    int rev = 0;
    while(x>rev){
        rev = rev*10 + x%10;
        x = x/10;
    }
    return (x == rev || x == rev/10);
}

int main(){
    cout << boolalpha << isPalindrome(121) << endl;
    cout << boolalpha << isPalindrome(-121) << endl;
    cout << boolalpha << isPalindrome(0) << endl;
    cout << boolalpha << isPalindrome(10) << endl;
    return 0;
}