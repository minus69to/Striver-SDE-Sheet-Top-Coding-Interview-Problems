#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordList(wordDict.begin(), wordDict.end());

        int sLen = s.size();
        vector<bool> dp(sLen + 1, false);
        dp[0] = true;

        for (int i = 1; i <= sLen; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && wordList.find(s.substr(j, i - j)) != wordList.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[sLen];
    }
};

int main()
{
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    if (solution.wordBreak(s, wordDict))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }

    return 0;
}

// https://leetcode.com/problems/word-break/