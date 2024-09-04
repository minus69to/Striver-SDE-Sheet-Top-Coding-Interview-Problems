#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;

    void findPathUtil(vector<vector<int>> &m, int n, int r, int c, string path)
    {
        if (r == n - 1 && c == n - 1)
        {
            if (m[r][c] == 1)
            {
                ans.push_back(path);
            }
            return;
        }

        if ((r < 0 || r >= n) || (c < 0 || c >= n) || m[r][c] == 0)
        {
            return;
        }

        m[r][c] = 0;

        findPathUtil(m, n, r, c + 1, path + 'R');
        findPathUtil(m, n, r, c - 1, path + 'L');
        findPathUtil(m, n, r + 1, c, path + 'D');
        findPathUtil(m, n, r - 1, c, path + 'U');

        m[r][c] = 1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<pair<int, int>> def = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

        if (m[0][0] == 1)
        {
            findPathUtil(m, n, 0, 0, "");
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    int n = maze.size();
    vector<string> result = obj.findPath(maze, n);

    for (const auto &path : result)
    {
        cout << path << endl;
    }

    return 0;
}

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1