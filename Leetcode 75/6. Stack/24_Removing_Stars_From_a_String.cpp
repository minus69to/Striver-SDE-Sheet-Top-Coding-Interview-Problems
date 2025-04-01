#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        string ans = "";
        stack<char> stk;

        for (auto x : s)
        {
            if (x != '*')
            {
                stk.push(x);
            }
            else
            {
                stk.pop();
            }
        }

        while (!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    string s = "erase*****";

    Solution solution;
    cout << solution.removeStars(s);

    return 0;
}