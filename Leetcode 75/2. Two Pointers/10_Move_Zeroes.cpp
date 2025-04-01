#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int placeNonzero = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            print(nums);
            if (nums[i] != 0)
            {
                swap(nums[placeNonzero], nums[i]);
                placeNonzero++;
            }
            print(nums);
            cout << endl;
        }
    }

    void print(vector<int> &nums)
    {
        for (auto x : nums)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> nums = {1, 0, 2, 3, 0, 4};
    Solution solution;
    solution.moveZeroes(nums);

    for (auto x : nums)
    {
        cout << x << " ";
    }

    return 0;
}
