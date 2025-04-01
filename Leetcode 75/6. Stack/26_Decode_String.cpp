#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<pair<string, int>> stk;
        string curStr = "";
        int curNum = 0;

        for (char ch : s)
        {
            if (isdigit(ch) == true)
            {
                curNum = curNum * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                stk.push({curStr, curNum});

                curStr = "";
                curNum = 0;
            }
            else if (ch == ']')
            {
                pair<string, int> prev = stk.top();
                stk.pop();

                string prevStr = prev.first;
                int preNum = prev.second;

                string repeat = "";

                for (int i = 0; i < preNum; i++)
                {
                    repeat = repeat + curStr;
                }

                curStr = prevStr + repeat;
            }
            else
            {
                curStr = curStr + ch;
            }
        }

        return curStr;
    }
};

int main()
{
    // string s = "2[abc]3[cd]ef";
    string s = "3[a2[c]]";

    Solution solution;
    cout << solution.decodeString(s);

    return 0;
}

// https://leetcode.com/problems/decode-string/description/?envType=study-plan-v2&envId=leetcode-75