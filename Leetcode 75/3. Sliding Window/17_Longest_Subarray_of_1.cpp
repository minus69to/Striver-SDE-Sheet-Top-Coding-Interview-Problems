#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans = 0, zero = 0, left = 0;

        for (int i = left; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero++;
            }

            while (zero > 1)
            {
                if (nums[left] == 0)
                {
                    zero--;
                }

                left++;
            }

            ans = max(ans, i - left + 1);
        }

        return ans - 1;
    }
};

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    Solution solution;
    cout << solution.longestSubarray(nums);

    return 0;
}