/*

877. Stone Game

Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

Example 1:

Input: [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.

Note:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles) is odd.

*/

#include <iostream>
#include <vector>

using namespace std;

// incorrect answer. Need to use DP
bool stoneGame(vector<int>& piles) {
    int alex=0, lee=0, n=piles.size();
    for(int i=0; i<n; ++i){
        if(i==0 || i%2==0){
            if(piles.front() >= piles.back()){
                alex += piles.front();
                piles.erase(piles.begin());
            }
            else{
                alex += piles.back();
                piles.erase(piles.end()-1);
            }
        }
        else{
            if(piles.front() >= piles.back()){
                lee += piles.front();
                piles.erase(piles.begin());
            }
            else{
                lee += piles.back();
                piles.erase(piles.end()-1);
            }
        }
    }
    return alex > lee;
}

int main(){
    // vector<int> v = {5,3,4,5};
    vector<int> v = {3,7,2,3};
    cout << boolalpha << stoneGame(v);
    return 0;
}
