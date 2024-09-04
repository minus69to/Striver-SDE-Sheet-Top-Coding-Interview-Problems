#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> numbers;
        int factorial = 1;

        for (int i = 1; i <= n; i++)
        {
            factorial *= i; // Calculation factorial
            numbers.push_back(i);
        }

        string ans = "";
        int rem = k - 1;     // Here remainder = k
        int div = factorial; // Here divisor = factorial
        int quot = 0;        // Here quotient initiaized

        while (n >= 1)
        {
            div = div / n;
            quot = rem / div;
            rem = rem % div;

            ans += to_string(numbers[quot]);
            numbers.erase(numbers.begin() + quot);

            n--;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.getPermutation(7, 399) << endl;

    return 0;
}