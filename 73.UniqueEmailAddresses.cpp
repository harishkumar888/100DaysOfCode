/*
929. Unique email addresses



*/

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int numUniqueEmails(vector<string>& emails) {
    set<string> s;
    for(auto email:emails){
        string localName = "", domainName = "";
        bool isDomainName = false, ignore = false;
        for(auto c:email){
            if(c == '@' || isDomainName){
                isDomainName = true;
                domainName += c;
            }
            else if(!ignore){
                if(c == '+') ignore = true;
                if(c != '.')
                    localName += c;
            }
        }
        s.insert(localName+domainName);
        localName = "", domainName = "";
    }
    return s.size();
}

int main(){
    vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    cout << numUniqueEmails(emails);
    return 0;
}