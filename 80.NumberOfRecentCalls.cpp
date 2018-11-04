/*
Write a class RecentCounter to count recent requests.

It has only one method: ping(int t), where t represents some time in milliseconds.

Return the number of pings that have been made from 3000 milliseconds ago until now.

Any ping with time in [t - 3000, t] will count, including the current ping.

It is guaranteed that every call to ping uses a strictly larger value of t than before.

 

Example 1:

Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
Output: [null,1,2,3,3]
 

Note:

Each test case will have at most 10000 calls to ping.
Each test case will call ping with strictly increasing values of t.
Each call to ping will have 1 <= t <= 10^9.
*/

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        time.push(t);
        
        while(!time.empty() && time.front() < t-3000){
            time.pop();
        }
        return time.size();
    }

    private:
    queue<int> time;
};

int main(){
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1) << endl;
    cout << obj->ping(100) << endl;
    cout << obj->ping(3001) << endl;
    cout << obj->ping(3002) << endl;

    return 0;
}