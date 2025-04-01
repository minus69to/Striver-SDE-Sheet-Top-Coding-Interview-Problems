#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap;

        for (auto x : nums)
        {
            freqMap[x]++;
        }

        int operations = 0;

        for (auto [num, count] : freqMap)
        {
            if (count == 0)
            {
                continue;
            }

            int complement = k - num;

            if (num == complement)
            {
                operations += freqMap[num] / 2;
                freqMap[num] -= (count / 2) * 2;
            }
            else if (freqMap.count(complement))
            {
                if (freqMap[complement] > 0)
                {
                    int pairs = min(freqMap[num], freqMap[complement]);
                    operations += pairs;
                    freqMap[num] -= pairs;
                    freqMap[complement] -= pairs;
                }
            }
        }

        return operations;
    }
};

int main()
{
    vector<int> nums = {29, 26, 81, 70, 75, 4, 48, 38, 22, 10, 51, 62, 17, 50, 7, 7, 24, 61, 54, 44, 30, 29, 66, 83, 6, 45, 24, 49, 42, 31, 10, 6, 88, 48, 34, 10, 54, 56, 80, 41, 19};
    int k = 12;

    Solution solution;
    cout << solution.maxOperations(nums, k);

    return 0;
}