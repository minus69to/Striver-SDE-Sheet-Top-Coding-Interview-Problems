#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<int> col;
    set<int> posD;
    set<int> negD;

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> str(n, string(n, '.'));

        utility(n, 0, str, ans);

        return ans;
    }

    void utility(int n, int r, vector<string> str, vector<vector<string>> &ans)
    {
        if (r == n)
        {
            ans.push_back(str);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (col.find(i) == col.end() && posD.find(r + i) == posD.end() && negD.find(r - i) == negD.end())
            {

                str[r][i] = 'Q';
                col.insert(i);
                posD.insert(r + i);
                negD.insert(r - i);

                utility(n, r + 1, str, ans);

                str[r][i] = '.';
                col.erase(i);
                posD.erase(r + i);
                negD.erase(r - i);
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(4);

    for (const auto &solution : ans)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}

// https://leetcode.com/problems/n-queens/