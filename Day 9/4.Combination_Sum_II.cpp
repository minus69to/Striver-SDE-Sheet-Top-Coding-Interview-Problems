#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        int n = candidates.size();
        vector<int> temp;
        vector<vector<int>> ans;

        utility(candidates, target, n, temp, ans, 0);

        return ans;
    }

    void utility(vector<int> &candidates, int target, int n, vector<int> temp, vector<vector<int>> &ans, int ind)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < n; i++)
        {
            if (i > ind && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            if (candidates[i] > target)
            {
                break;
            }

            temp.push_back(candidates[i]);
            utility(candidates, target - candidates[i], n, temp, ans, i+1);
            temp.pop_back();
        }
    }
};

int main()
{
    vector<int> candidates = {5,3,2,2,1};
    int target = 5;

    Solution sol;

    vector<vector<int>> ans = sol.combinationSum2(candidates, target);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}

// https://leetcode.com/problems/combination-sum/description/