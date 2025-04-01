#include <bits/stdc++.h>
using namespace std;

int print1(int val1)
{
    if (val1 > 4)
    {
        return 0;
    }

    // int count = 0;
    // count = 1;

    // count += print1(val1 + 1);
    // cout << count << " ";

    return 1 + print1(val1 + 1);
}

int print2(int val2)
{
    if (val2 > 10)
    {
        return 0;
    }

    // int count = 0;
    // count = 1;

    // count += print2(val2 + 1);
    // cout << count << " ";

    return 1 + print2(val2 + 1);
}

void rec(int val1, int val2)
{
    // int ans1 = print1(val1);

    // int ans2 = print2(val2);

    cout << print1(val1) + print2(val2) << endl;

    cout << "\nEND" << endl;
}

int main()
{
    rec(1, 8);

    return 0;
}