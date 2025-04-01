#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }

        unordered_set<int> s;

        for (auto [key, value] : m)
        {
            if (s.find(value) == s.end())
            {
                s.insert(value);
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<int> arr = {1, 2};

    Solution solution;
    cout << solution.uniqueOccurrences(arr);

    return 0;
}