/*

868. Binary Gap

Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.

If there aren't two consecutive 1's, return 0.


Example 1:

Input: 22
Output: 2
Explanation: 
22 in binary is 0b10110.
In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
The first consecutive pair of 1's have distance 2.
The second consecutive pair of 1's have distance 1.
The answer is the largest of these two distances, which is 2.
Example 2:

Input: 5
Output: 2
Explanation: 
5 in binary is 0b101.
Example 3:

Input: 6
Output: 1
Explanation: 
6 in binary is 0b110.
Example 4:

Input: 8
Output: 0
Explanation: 
8 in binary is 0b1000.
There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.
 

Note:

1 <= N <= 10^9

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Naive solution

int binaryGap_naive(int N) {
    int remainder = N;
    int quotient = N;
    vector<int> brep;
    while(quotient){
        remainder = quotient%2;
        quotient /= 2;
        brep.push_back(remainder);
    }
    int max_dist=0, dist=0;
    bool foundone=false;
    for(auto elem:brep){
        if(elem==1){
            foundone=true;
        }if(elem == 1 && foundone){
            max_dist = max(max_dist, dist);
            dist=0;
        }
        if(foundone)dist++;
    }
    return max_dist;
}


int binaryGap(int N){
    int pos=0, prev_pos=-1, max_len=0;
    while(N){
        pos++;
        if((N & 1) == 1){
            if(prev_pos != -1)
                max_len = max(max_len, pos-prev_pos);
            prev_pos = pos;
        }
        N = N>>1;
    }
    return max_len;
}

int main(){
    int n = 22;
    cout << binaryGap(n) << endl;
    cout << binaryGap_naive(n) << endl;
    return 0;
}
