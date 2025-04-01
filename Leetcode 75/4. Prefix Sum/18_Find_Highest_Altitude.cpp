#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int ans = 0, count = 0;

        for (int i = 0; i < gain.size(); i++)
        {
            count += gain[i];
            ans = max(ans, count);
        }

        return ans;
    }
};

int main()
{
    vector<int> gain = {-4, -3, -2, -1, 4, 3, 2};
    Solution solution;
    cout << solution.largestAltitude(gain);

    return 0;
}