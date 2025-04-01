#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int vowel = 0;
        int maxLen = 0;

        for (int i = 0; i < k; i++)
        {
            maxLen = maxLen + isVowel(s[i]);
        }

        int temp = maxLen;

        for (int i = k; i < s.size(); i++)
        {
            temp = temp + isVowel(s[i]) - isVowel(s[i - k]);

            maxLen = max(temp, maxLen);
        }

        return maxLen;
    }

    int isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return 1;
        }

        return 0;
    }
};

int main()
{
    string s = "abciiidef";
    int k = 3;

    Solution solution;
    cout << solution.maxVowels(s, k);

    return 0;
}