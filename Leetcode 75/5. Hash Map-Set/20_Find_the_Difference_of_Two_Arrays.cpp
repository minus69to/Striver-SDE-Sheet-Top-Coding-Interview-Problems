#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> list1;
        vector<int> list2;

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        for (auto x : set1)
        {
            if (set2.find(x) == set2.end())
            {
                list1.push_back(x);
            }
        }

        for (auto x : set2)
        {
            if (set1.find(x) == set1.end())
            {
                list2.push_back(x);
            }
        }

        return {list1, list2};
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 3}, nums2 = {1, 1, 2, 2};
    // vector<int> nums1 = {1, 2, 3}, nums2 = {2, 4, 6};

    Solution solution;
    vector<vector<int>> ans = solution.findDifference(nums1, nums2);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// https://leetcode.com/problems/find-the-difference-of-two-arrays/?envType=study-plan-v2&envId=leetcode-75