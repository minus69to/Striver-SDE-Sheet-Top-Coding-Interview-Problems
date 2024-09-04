#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

class Solution
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meeting;
        for (int i = 0; i < n; i++)
        {
            meeting.push_back({start[i], end[i]});
        }

        sort(meeting.begin(), meeting.end(), comp);

        int ans = 0, last = 0;

        for (int i = 0; i < n; i++)
        {
            if (meeting[i].first > last)
            {
                ans++;
                last = meeting[i].second;
            }
        }

        return ans;
    }
};

int main()
{
    int n = 6;
    int start[n] = {1, 3, 0, 5, 8, 5};
    int end[n] = {2, 4, 6, 7, 9, 9};

    Solution sol;
    cout << sol.maxMeetings(start, end, n) << endl;

    return 0;
}

// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1