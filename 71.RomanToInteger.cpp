/*

*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int i = 0, n = s.size(), res = 0;
    while(i<n){
        int cur = m[s[i]];
        int next = m[s[i+1]];
        if(cur >= next){
            res += cur;
            i++;
        }else{
            res += next - cur;
            i += 2;
        }
    }
    return res;
}

int main(){
    cout << romanToInt("III") << endl;
    cout << romanToInt("IV") << endl;
    cout << romanToInt("IX") << endl;
    cout << romanToInt("LVIII") << endl;
    cout << romanToInt("MCMXCIX") << endl;
    return 0;
}