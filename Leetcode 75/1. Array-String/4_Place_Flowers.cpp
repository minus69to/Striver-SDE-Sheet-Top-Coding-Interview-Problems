#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int len = flowerbed.size();
        int putted = 0;

        for (int i = 0; i < len; i++)
        {
            if ((flowerbed[i] == 0) && (i == 0 || flowerbed[i - 1] == 0) && (i == len - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                putted++;
                i++; // Skip the next count(not necessary)
            }
        }

        if (n <= putted)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    vector<int> flowerbed = {0, 0, 1, 0, 1};
    int n = 1;

    Solution solution;
    cout << solution.canPlaceFlowers(flowerbed, n);

    return 0;
}