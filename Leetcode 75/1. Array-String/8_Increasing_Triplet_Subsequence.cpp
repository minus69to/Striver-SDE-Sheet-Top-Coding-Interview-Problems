#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int smallest = INT_MAX;
        int smaller = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < smallest)
            {
                smallest = nums[i];
            }
            if (nums[i] > smallest && nums[i] < smaller)
            {
                smaller = nums[i];
            }
            if (nums[i] > smaller)
            {
                // cout << smallest << " " << smaller << " " << nums[i] << endl;
                return true;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {4, 5, 2, 7, 0, 9};
    Solution solution;
    cout << solution.increasingTriplet(nums);

    return 0;
}