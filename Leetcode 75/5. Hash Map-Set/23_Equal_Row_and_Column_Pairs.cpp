#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = 0;
        map<vector<int>, int> rowFreq;

        for (auto x : grid)
        {
            rowFreq[x]++;
        }

        for (int j = 0; j < n; j++)
        {
            vector<int> currentCol;
            for (int i = 0; i < n; i++)
            {
                currentCol.push_back(grid[i][j]);
            }

            if (rowFreq.find(currentCol) != rowFreq.end())
            {
                ans += rowFreq[currentCol];
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};

    Solution solution;
    cout << solution.equalPairs(grid);

    return 0;
}