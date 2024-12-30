#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid -1;
                }
            }
        }

        return -1;
    }
};

int main()
{

    vector<int> nums = {8, 9, 0, 1, 2, 3, 4, 5, 6, 7};
    int target = 0;

    Solution sol;
    cout << sol.search(nums, target);

    return 0;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/