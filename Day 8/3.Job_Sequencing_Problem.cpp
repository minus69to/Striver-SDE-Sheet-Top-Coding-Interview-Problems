#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    bool static comp(const struct Job &a, const struct Job &b)
    {
        if (a.profit == b.profit)
        {
            return a.dead > b.dead;
        }
        else
        {
            return a.profit > b.profit;
        }
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comp);

        int maxD = 0;
        for (int i = 0; i < n; i++)
        {
            maxD = max(maxD, arr[i].dead);
        }

        vector<int> track(maxD + 1, -1);
        // for (int i = 0; i < track.size(); i++)
        // {
        //     cout << i << " -> " << track[i] << endl;
        // }

        int count = 0, value = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (track[j] == -1)
                {
                    track[j] = arr[i].dead;
                    count++;
                    value += arr[i].profit;
                    break;
                }
            }
        }

        return {count, value};
    }
};

int main()
{
    struct Job arr[5] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};

    Solution sol;
    vector<int> ans = sol.JobScheduling(arr, 4);

    cout << ans[0] << " <-> " << ans[1] << endl;

    return 0;
}

// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1