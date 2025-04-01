#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        if (chars.size() == 1)
        {
            return 1;
        }

        int write = 0;
        int count = 1;

        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == chars[i - 1])
            {
                count++;
            }
            else
            {
                chars[write++] = chars[i - 1];

                if (count > 1)
                {
                    for (char c : to_string(count))
                    {
                        chars[write++] = c;
                    }
                }

                count = 1;
            }
        }

        chars[write++] = chars[chars.size() - 1];
        if (count > 1)
        {
            for (char c : to_string(count))
            {
                chars[write++] = c;
            }
        }

        chars.resize(write);
        return write;
    }
};

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution solution;
    cout << solution.compress(chars);

    return 0;
}