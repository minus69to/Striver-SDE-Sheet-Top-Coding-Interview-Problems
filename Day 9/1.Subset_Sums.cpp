#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> subsetSums(vector<int> arr, int n) 
    {
        vector<int> ans;
        utility(arr, n-1, ans, 0);
        return ans;
    }

    void utility(vector<int> arr, int n, vector<int> &ans, int sum) 
    {
        if (n < 0)
        {
            ans.push_back(sum);
            // cout << sum << " ";
            return;
        }
        
        utility(arr, n-1, ans, sum);
        utility(arr, n-1, ans, sum + arr[n]);
    }
};

int main()
{
    int n = 3;
    vector<int> arr = {5, 2, 1};

    Solution sol;
    vector<int> ans = sol.subsetSums(arr, n);

    for(auto x: ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

// https://www.geeksforgeeks.org/problems/subset-sums2234/1