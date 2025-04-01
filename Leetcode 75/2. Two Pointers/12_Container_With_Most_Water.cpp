#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int maxArea = INT_MIN;

        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            maxArea = max(area, maxArea);

            height[left] < height[right] ? left++ : right--;
        }

        return maxArea;
    }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    cout << solution.maxArea(height);

    return 0;
}