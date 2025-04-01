#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxLen = 0, zero = 0, left = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero++;
            }

            while (zero > k)
            {
                if (nums[left] == 0)
                {
                    zero--;
                }
                left++;
            }

            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
    }
};

int main()
{
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;

    Solution solution;
    cout << solution.longestOnes(nums, k);

    return 0;
}

// https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75