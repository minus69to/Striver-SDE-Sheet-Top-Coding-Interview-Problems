#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // Check Condition 1
        int len1 = word1.size(), len2 = word2.size();

        if (len1 != len2)
        {
            return false;
        }

        // Check Condition 2
        unordered_map<char, int> map1, map2;

        for (char x : word1)
        {
            map1[x]++;
        }

        for (char x : word2)
        {
            map2[x]++;
        }

        if (map1.size() != map2.size())
        {
            return false;
        }

        for (auto [key, value] : map1)
        {
            if (map2.count(key) == 0)
            {
                return false;
            }
        }

        for (auto [key, value] : map2)
        {
            if (map1.count(key) == 0)
            {
                return false;
            }
        }

        // Check Condition 3
        vector<int> freq1, freq2;

        for (auto [key, value] : map1)
        {
            freq1.push_back(value);
        }

        for (auto [key, value] : map2)
        {
            freq2.push_back(value);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};

int main()
{
    string word1 = "cabbba", word2 = "aabbcc";

    Solution solution;
    cout << solution.closeStrings(word1, word2);

    return 0;
}