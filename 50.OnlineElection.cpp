/*
911. Online Election

In an election, the i-th vote was cast for persons[i] at time times[i].

Now, we would like to implement the following query function: TopVotedCandidate.q(int t) will return the number of the person that was leading the election at time t.  

Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.

Example 1:

Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
 

Note:

1 <= persons.length = times.length <= 5000
0 <= persons[i] <= persons.length
times is a strictly increasing array with all elements in [0, 10^9].
TopVotedCandidate.q is called at most 10000 times per test case.
TopVotedCandidate.q(int t) is always called with t >= times[0].

*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class TopVotedCandidate {
public:
    map<int, int> votes_t;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int lead = 0;
        vector<int> votes(times.size(), 0);
        for(int i=0; i<times.size(); ++i)
        {
            votes[persons[i]]++;
            if(votes[persons[i]] >= votes[lead])
                lead = persons[i];
            votes_t[times[i]] = lead;
        }
    }
    
    int q(int t) {
        return (--votes_t.upper_bound(t))-> second;
    }
};

int main()
{
    vector<int> persons{0,1,1,0,0,1,0};
    vector<int> times{0,5,10,15,20,25,30};
    TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
    
    cout << obj->q(3) << endl;
    cout << obj->q(12) << endl;
    cout << obj->q(25) << endl;
    cout << obj->q(15) << endl;
    cout << obj->q(24) << endl;
    cout << obj->q(8) << endl;
    return 0;
}
