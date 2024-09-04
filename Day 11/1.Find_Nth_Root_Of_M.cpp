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
            return 1;
        }
    }

    if (result < m)
    {
        return -1;
    }

    return 0; // For equal
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
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }

    // cout << lo << " " << hi << endl;

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
    // cout << "HELLO\n";
    cout << NthRoot(9, 1953125);

    return 0;
}

// https://www.naukri.com/code360/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website