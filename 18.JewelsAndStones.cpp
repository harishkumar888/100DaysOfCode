/*
771. Jewels and Stones

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int numJewelsInStones_stl(string J, string S) {
    int gems = 0;
    for(auto chr:J){
        gems += count(begin(S), end(S), chr);
    }
    return gems;
}

int numJewelsInStones(string J, string S) {
    int gems = 0;
    map<char, int> chr_map;
    for(auto chr:S)
        chr_map[chr]++;

    for(auto chr:J)
        gems += chr_map[chr];
    return gems;
}

int main(){
    cout << numJewelsInStones("aaA", "aBbbzAA");
    return 0;
}
