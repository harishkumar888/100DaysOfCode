/*

867. Prime Palindrome

Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

Example 1:

Input: 6
Output: 7
Example 2:

Input: 8
Output: 11
Example 3:

Input: 13
Output: 101

Input: 1215122
Output: 1218121
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
bool isPrime_naive(int N){
    if(N==2 || N==3) return true;
    if(N==1 || N==4) return false;
    bool b_isPrime = false;
    int i=0;

    for(i=2; i<N/2; ++i){
        if(N%i == 0) break;
    }
    if(i == N/2){
        b_isPrime = true;
    }
    return b_isPrime;
}

bool isPrime(int num){
    if (num < 2 || num % 2 == 0) return num == 2;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}

bool isPali(int N){
    bool b_isPali = false;
    vector<int> num;
    int remainder = N%10, quotient = N/10;
    num.push_back(remainder);
    while(quotient>0){
        remainder = quotient%10;
        quotient /= 10;
        num.push_back(remainder);
    }
    int i=0, j=num.size()-1;
    while(i<=j){
        if(num[i++] != num[j--]) return false;
    }
    return true;
}

bool isPrimePali(int N){
    return isPali(N) && isPrime(N);
}

int smallestPrimePali(int N){
    while(!isPrimePali(N)){
        N++;
    }
    return N;
}
*/


int is_prime(int n) {
    if (n <= 1)
        return 0; 
    int m = (int)(sqrt(n));
    for (int i = 2; i <= m; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int reverse(int n){
    int m = 0;
    while (n) {
        m = m*10 + n % 10;
        n /= 10;
    }
    return m;
}

int is_palindrome(int n){
    return n == reverse(n);
}

int primePalindrome(int N) {
    if (1e7 <= N && N <= 1e8)
        N = 100030001;
    while(1){
        while(is_palindrome(N) == 0) N++;
        if (is_prime(N))
            return N;
        N++;
    }
}

int main() {
    int N = 9989900;
    cout << primePalindrome(N);
    return 0;
}
