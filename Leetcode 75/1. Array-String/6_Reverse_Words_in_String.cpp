#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        reverse(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else
            {
                int j = i;
                while (j < s.size() && s[j] != ' ')
                {
                    result.append(1, s[j]);
                    j++;
                }

                reverse(result.end() - (j - i), result.end());
                result.append(1, ' ');
                i = j;
            }
        }

        if (!result.empty())
        {
            result.pop_back();
        }

        return result;
    }
};

int main()
{
    string s = "   leet  code   ";

    Solution solution;
    cout << solution.reverseWords(s);

    return 0;
}