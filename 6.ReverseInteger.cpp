/*
7. Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <iostream>
// #include <stdint.h>
#include <climits>

using namespace std;

int reverse(int n) {
    long long remain = 0;

    while(n){
        remain = remain*10 + n%10;
        n /= 10;
    }
    remain = (remain<INT_MIN || remain>INT_MAX) ? 0:remain;
    return remain;
}

int main() {
//   int n=2147483646;
  int n=8646;

  cout << reverse(n);
  return 0;
}