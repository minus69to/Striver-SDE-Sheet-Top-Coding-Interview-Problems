#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            while (left < right && vowels.find(s[left]) == vowels.end())
            {
                left++;
            }

            while (left < right && vowels.find(s[right]) == vowels.end())
            {
                right--;
            }

            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};

int main()
{
    string s = "leetcode";

    Solution solution;
    cout << solution.reverseVowels(s);

    return 0;
}