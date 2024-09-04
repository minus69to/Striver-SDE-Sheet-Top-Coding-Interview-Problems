#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> comb;
        set<vector<int>> uniqueComb;

        utility(nums, n - 1, ans, comb, uniqueComb);

        return ans;
    }

    void utility(vector<int> arr, int n, vector<vector<int>> &ans, vector<int> comb, set<vector<int>> &uniqueComb)
    {
        if (n < 0)
        {
            sort(comb.begin(), comb.end());
            if (uniqueComb.find(comb) == uniqueComb.end())
            {
                ans.push_back(comb);
                uniqueComb.insert(comb);
            }
            
            return;
        }

        utility(arr, n - 1, ans, comb, uniqueComb);

        comb.push_back(arr[n]);
        utility(arr, n - 1, ans, comb, uniqueComb);
    }
};

int main()
{
    int n = 5;
    vector<int> nums = {5,2,1};

    Solution sol;
    vector<vector<int>> ans = sol.subsetsWithDup(nums);

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

// https://leetcode.com/problems/subsets-ii/description/