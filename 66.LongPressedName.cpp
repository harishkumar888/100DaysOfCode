/*
925. Long Pressed Name

Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 

Note:

name.length <= 1000
typed.length <= 1000
The characters of name and typed are lowercase letters.
*/

#include <iostream>
#include <string>

using namespace std;

string rle(string s){
    int i=0, c=1;
    string res;
    while(i<s.size()){
        if(s[i]==s[i+1]){
            c++;
        }
        else{
            res += s[i] + to_string(c);
            c=1;
        }
        i++;
    }
    return res;
}

bool isLongPressedName_naive(string name, string typed) {
    string rle_name = rle(name);
    string rle_typed = rle(typed);
    if(rle_name.size() != rle_typed.size())
        return false;
    int i=1;
    while(i<rle_name.size()){
        if(rle_typed[i] < rle_name[i])
            return false;
        i += 2;
    }
    return true;
}

bool isLongPressedName(string name, string typed, int i = 0, int j = 0) {
    while (j < typed.size()) {
        if (i < name.size() && name[i] == typed[j]) ++i, ++j;
        else if (i > 0 && name[i - 1] == typed[j]) ++j;
        else return false;
    }
    return i == name.size();
}

int main(){
    cout << boolalpha << isLongPressedName("alex", "aaleex") << endl;
    cout << boolalpha << isLongPressedName("saeed", "ssaaedd") << endl;
    cout << boolalpha << isLongPressedName("leelee", "lleeelee") << endl;
    cout << boolalpha << isLongPressedName("laiden", "laiden") << endl;
    return 0;
}
