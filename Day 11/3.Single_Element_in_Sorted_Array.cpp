#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int size = nums.size();

        if (size == 1)
        {
            return nums[0];
        }

        if (nums[0] != nums[1])
        {
            return nums[0];
        }

        if (nums[size - 1] != nums[size - 2])
        {
            return nums[size - 1];
        }

        int low = 1, high = size - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            else if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 8, 9, 9};

    Solution sol;
    cout << sol.singleNonDuplicate(nums) << endl;

    return 0;
}