#include <bits/stdc++.h>
using namespace std;

int check(int mid, int n, int m)
{
    long long result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= mid;
        if (result > m)
        {
            return 1; // Too high
        }
    }

    if (result < m)
    {
        return -1; // Too low
    }

    return 0; // Equal
}

int NthRoot(int n, int m)
{
    int lo = 1, hi = m;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        int temp = check(mid, n, m);

        if (temp == 1)
        {
            hi = mid; // mid is too high
        }
        else
        {
            lo = mid; // mid is too low or equal
        }
    }

    cout << lo << " " << hi << endl;

    if (check(hi, n, m) == 0)
    {
        return hi;
    }
    else if (check(lo, n, m) == 0)
    {
        return lo;
    }

    return -1;
}

int main()
{
    int n = 9, m = 1953125;
    int result = NthRoot(n, m);
    cout << "The " << n << "th root of " << m << " is: " << result << endl;
    return 0;
}
