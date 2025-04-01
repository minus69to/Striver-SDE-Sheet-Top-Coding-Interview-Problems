#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result(nums.size(), 1);
        
        int prefix = 1;
        for (int i = 0; i < result.size(); i++)
        {
            result[i] = prefix;
            prefix *= nums[i];
        }
        
        int suffix = 1;
        for (int i = result.size()-1; i >= 0; i--)
        {
            result[i] = result[i] * suffix;
            suffix *= nums[i];
        }
        
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    Solution solution;
    vector<int> result = solution.productExceptSelf(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    
    return 0;
}