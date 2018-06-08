/*
846. Hand of Straights
Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.

*/

#include <vector>
#include<iostream>
#include <map>

using namespace std;

bool isNStraightHand(vector<int>& hand, int W) {
    map<int, int>card_count;
    for(auto elem: hand)
        card_count[elem]++;
    for(auto item: card_count)
        if(card_count[item.first] > 0)
            for(int i=W-1; i>=0; --i)
                if((card_count[item.first+i] -= card_count[item.first]) < 0)
                    return false;
    return true;
}

int main(){
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int W = 3;
    isNStraightHand(hand, W);
    return 0;
}