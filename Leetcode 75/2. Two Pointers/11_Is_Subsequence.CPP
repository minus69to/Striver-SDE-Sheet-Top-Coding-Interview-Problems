#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int sp = 0;

        for (int i = 0; i < t.size(); i++)
        {
            if (sp == s.size())
            {
                return true;
            }
            if (s[sp] == t[i])
            {
                sp++;
            }
        }

        if (sp == s.size())
        {
            return true;
        }

        return false;
    }
};

int main()
{
    string s = "abc", t = "a";

    Solution solution;
    cout << solution.isSubsequence(s, t);

    return 0;
}