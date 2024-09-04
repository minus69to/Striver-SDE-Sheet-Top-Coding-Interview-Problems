#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int n = candidates.size() - 1;
        vector<int> temp;
        vector<vector<int>> ans;

        utility(candidates, target, n, temp, ans);

        return ans;
    }

    void utility(vector<int>& candidates, int target, int n, vector<int> temp,  vector<vector<int>> &ans) 
    {
        if (n < 0)
        {
            return;
        }
        
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (target < 0)
        {
            return;
        }
        
        utility(candidates, target, n-1, temp, ans);

        temp.push_back(candidates[n]);
        utility(candidates, target - candidates[n], n, temp, ans);
    }
};

int main()
{
    vector<int> candidates = {2,4,3}; 
    int target = 6;

    Solution sol;

    vector<vector<int>> ans = sol.combinationSum(candidates, target);

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