#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int a = 0, d = 0;
        int plt = 0, ans = 0;

        while (a < n && d < n)
        {
            if (arr[a] <= dep[d])
            {
                plt++;
                ans = max(ans, plt);
                a++;
            }
            else
            {
                plt--;
                d++;
            }
        }
        return ans;
    }
};

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

    int n = 6;

    Solution sol;
    cout << sol.findPlatform(arr, dep, n) << endl;

    return 0;
}

// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1