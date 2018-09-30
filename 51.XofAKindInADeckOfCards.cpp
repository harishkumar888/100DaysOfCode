/*
914. X of a Kind in a Deck of Cards
DescriptionHintsSubmissionsDiscussSolution
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.
 

Example 1:

Input: [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
Example 2:

Input: [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
Example 3:

Input: [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: [1,1]
Output: true
Explanation: Possible partition [1,1]
Example 5:

Input: [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2]

Note:

1 <= deck.length <= 10000
0 <= deck[i] < 10000
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool hasGroupsSizeX_naive(vector<int>& deck) {
    int n = deck.size();
    map<int, int> mp;
    bool hasGrp = false;
    for(auto elem: deck){
        mp[elem]++;
    }
    
    for(int i=2; i<10000; ++i){
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second%i != 0){
                break;
            }
            else{
                if(next(it) == mp.end()){
                    hasGrp = true;
                    break;
                }
            }
        }
        if(hasGrp) break;
    }
    return hasGrp;
}

bool hasGroupsSizeX(vector<int>& deck){
    int n= deck.size(), res = 0;
    map<int, int> count;
    for(auto elem:deck)
        count[elem]++;
    for(auto i:count)
        res = __gcd(i.second, res);

    return res>1;    
}

int main(){
    vector<int> deck = {1,2,3,4,4,3,2,1};
    cout << boolalpha << hasGroupsSizeX(deck);
    return 0;
}