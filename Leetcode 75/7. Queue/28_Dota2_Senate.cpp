#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> radiant;
        queue<int> dire;

        for (int i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'R')
            {
                radiant.push(i);
            }
            else
            {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty())
        {
            int r_id = radiant.front();
            radiant.pop();

            int d_id = dire.front();
            dire.pop();

            if (r_id < d_id)
            {
                radiant.push(r_id + senate.size());
            }
            else
            {
                dire.push(d_id + senate.size());
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};

int main()
{
    string senate = "DDRRR";
    Solution solution;
    cout << solution.predictPartyVictory(senate);

    return 0;
}

// https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75