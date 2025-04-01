#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxVal = INT_MIN;
        for (int i = 0; i < candies.size(); i++)
        {
            maxVal = max(maxVal, candies[i]);
        }

        vector<bool> result;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i]+extraCandies >= maxVal)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }

        return result;
    }
};

int main()
{
    vector<int> candies = {2,3,5,1,3};
    Solution solution;
    vector<bool> result = solution.kidsWithCandies(candies, 3);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    
    return 0;
}