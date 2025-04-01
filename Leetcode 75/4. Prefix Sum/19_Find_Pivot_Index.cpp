#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> leftSum(len, 0);
        vector<int> rightSum(len, 0);

        for (int i = 1; i < len; i++)
        {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        for (int i = len - 2; i >= 0; i--)
        {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < len; i++)
        {
            if (leftSum[i] == rightSum[i])
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {2, 1, -1};
    Solution solution;
    cout << solution.pivotIndex(nums);

    return 0;
}