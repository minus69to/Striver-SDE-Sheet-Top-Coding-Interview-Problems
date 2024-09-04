#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> temp;
        vector<vector<int>> ans;

        utility(nums, l, r, temp, ans);

        return ans;
    }

    void utility(vector<int>& nums, int l, int r, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (l > r)
        {  
            ans.push_back(temp);
            return;
        }
        
        for (int i = l; i <= r; i++)
        {
            temp.push_back(nums[i]);
            swap(nums[l], nums[i]);

            utility(nums, l+1, r, temp, ans);

            temp.pop_back();
            swap(nums[l], nums[i]);
        }
        
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;

    Solution sol;
    ans = sol.permute(nums);

    for(auto x : ans)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}