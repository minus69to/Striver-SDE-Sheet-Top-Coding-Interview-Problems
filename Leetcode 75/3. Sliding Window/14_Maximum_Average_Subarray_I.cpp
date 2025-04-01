#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int total = 0;

        for (int i = 0; i < k; i++)
        {
            total += nums[i];
        }
        
        int temp = total;

        for (int i = k; i < nums.size(); i++)
        {
            temp = temp + nums[i] - nums[i-k];

            if (temp > total)
            {
                total = temp;
            }
        }
        
        return (double)total/k;
    }
};

int main()
{
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    Solution solution;
    cout << solution.findMaxAverage(nums, 4);

    return 0;
}