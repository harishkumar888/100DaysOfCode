/*
926. Flip String To Monotone Increasing

A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.

 

Example 1:

Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
Example 2:

Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
Example 3:

Input: "00011000"
Output: 2
Explanation: We flip to get 00000000.
 

Note:

1 <= S.length <= 20000
S only consists of '0' and '1' characters.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minFlipsMonoIncr(string S){
    int n = S.size();

    int tot0 = 0;
    for(auto ch:S){
        if(ch == '0'){
            tot0++;
        }
    }

    int res = n+1;

    int cnt0 = 0, cnt1 = 0;
    for(int i=0; i<n; ++i){
        if(S[i] == '0'){
            ++cnt0;
        }
        else{
            ++cnt1;
        }
        res = min(res, cnt1+tot0-cnt0);
    }
    res = min(res, tot0);

    return res;
}

int minFlipsMonoIncr_alt(string S){
    int n = S.size();

    vector<pair<int, int>> front;
    vector<pair<int, int>> back;


    int zeros=0, ones=0;

    //Count all zeros from first
    for(int i=0; i<n; ++i){
        if(S[i] == '0')zeros++;
        else ones++;
        front.push_back({zeros, ones});
    }

    zeros=0, ones=0;
    //Count all ones from back
    for(int i=n-1; i>=0; --i){
        if(S[i] == '0')zeros++;
        else ones++;
        // Note: Insert into the front of the back vector
        back.insert(back.begin(), {zeros, ones});
    }

    //There can be three cases
    //1) Replace all ones
    //2) Replace all zeros
    //3) Check every point where the cost == replacing ones before it + replacing zeros after it
    int minCost = min(zeros, ones);
    for(int i=0; i<n-1; ++i){
        minCost = min(minCost, front[i].second+back[i+1].first);
    }

    return minCost;
}

int main(){
    cout << minFlipsMonoIncr("00110") << endl;
    cout << minFlipsMonoIncr("010110") << endl;
    cout << minFlipsMonoIncr("00011000") << endl;
    cout << minFlipsMonoIncr("00011111") << endl;
    return 0;
}