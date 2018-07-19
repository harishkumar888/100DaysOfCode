/*

869. Reordered Power of 2

Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.


Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true
 

Note:

1 <= N <= 10^9

*/

#include <iostream>
#include <set>

using namespace std;

multiset<int> convert(int N){
    multiset<int> res;
    while(N){
        res.insert(N%10);
        N /= 10;
    }
    return res;
}

bool reorderedPowerOf2(int N) {
    multiset<int> N_set;
    int num=0;
    N_set = convert(N);
    for(int i=0;i<32; ++i){
        multiset<int> powerOf2 = convert(1<<i);
        if(N_set == powerOf2)
            return true;
    }
    return false;
}

int main(){
    cout << boolalpha << reorderedPowerOf2(46);
    return 0;
}
