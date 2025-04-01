#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        int gcdLen = gcd(str1.length(), str2.length());

        if (str1 + str2 == str2 + str1)
        {
            return str1.substr(0, gcdLen);
        }

        return "";
    }
};

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    Solution solution;
    cout << solution.gcdOfStrings(word1, word2) << endl;

    return 0;
}

// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75