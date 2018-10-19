/*
8. String To Integer(stoi)

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int stringToInteger_naive(string s){
    vector<int> clean_str;
    long long mult=1;
    long long ans = 0;
    bool first_sign = false;
    char sign = ' ';
    for(auto elem:s){
        if(elem == 32){
            
        }
        else if((elem == 43 || elem == 45) && !first_sign){
            sign = elem;
            first_sign = true;
        }
        else if(elem >=48 && elem <= 57){
            clean_str.push_back(elem-48);
        }else{
            if(clean_str.empty()) return 0;
        }
    }
    for(int i=clean_str.size()-1; i>=0; --i){
        ans += clean_str[i]*mult;
        mult *=10;
    }
    ans = (sign == '-') ? -ans : ans;
    ans = (ans > 2147483647) ? 2147483648 : ans;
    ans = (ans < -2147483647) ? -2147483648 : ans;
    return ans;
}

int stringToInteger(string s){
    long long int result = 0;
    int indicator = 1;

    int i = s.find_first_not_of(' ');
    if(s[i] == '-' || s[i] == '+')
        indicator = (s[i++] == '-') ? -1 : 1;

    while('0' <= s[i] && s[i] <= '9')
    {
        result = result*10 + (s[i++] - '0');
        if(result*indicator >= INT_MAX) return INT_MAX;
        if(result*indicator <= INT_MIN) return INT_MIN;
    }
    return result*indicator;
}

int main(){
    cout << stringToInteger("42") << endl;
    cout << stringToInteger("-42") << endl;
    cout << stringToInteger("4193 with words") << endl;
    cout << stringToInteger("words and 8236") << endl;
    cout << stringToInteger("-91283472332") << endl;
    cout << stringToInteger("3.1412") << endl;
    return 0;
}