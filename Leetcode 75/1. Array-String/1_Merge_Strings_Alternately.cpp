#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int len1 = word1.length();
        int len2 = word2.length();

        for (int i = 1, j = 0; i <= len1; i += 2, j++)
        {
            if (i == len1)
            {
                word1.insert(i, word2, j, len2-j);
            }
            else if(j == len2-1)
            {
                word1.insert(i, 1, word2[j]);
                break;
            }
            else
            {
                word1.insert(i, 1, word2[j]);
            }

            len1++;
        }

        return word1;
    }
};

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    Solution solution;
    cout << solution.mergeAlternately(word1, word2) << endl;

    return 0;
}

// https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan-v2&envId=leetcode-75