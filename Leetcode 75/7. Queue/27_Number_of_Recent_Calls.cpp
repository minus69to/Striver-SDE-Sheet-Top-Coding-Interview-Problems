#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
public:
    queue<int> calls;

    RecentCounter()
    {
    }

    int ping(int t)
    {
        calls.push(t);

        while (!calls.empty() && calls.front() < t - 3000)
        {
            calls.pop();
        }

        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{
    RecentCounter *counter = new RecentCounter();

    cout << counter->ping(1) << endl;    // Output: 1
    cout << counter->ping(100) << endl;  // Output: 2
    cout << counter->ping(3001) << endl; // Output: 3
    cout << counter->ping(3002) << endl; // Output: 3 (the call at t=1 is outside the window)
    cout << counter->ping(4000) << endl; // Output: 3 (calls at t=1 and t=100 are outside the window)
    cout << counter->ping(7000) << endl; // Output: 2

    delete counter;

    return 0;
}

// https://leetcode.com/problems/number-of-recent-calls/description/?envType=study-plan-v2&envId=leetcode-75