#include <bits/stdc++.h>
using namespace std;

bool check(int mid, int N, int C, vector<int> &v)
{
    int last_pos = -1; // Initialize
    for (int i = 0; i < N; i++)
    {
        if (v[i] - last_pos >= mid || last_pos == -1)
        {
            C--;
            last_pos = v[i];
            
            if (C == 0)
            {
                break;;
            }
        }
    }
    
    return C == 0;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N, C;
        cin >> N >> C;

        vector<int> v;

        int maxC = 0;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);

            if (x > maxC)
            {
                maxC = x;
            }
            
        }
        sort(v.begin(), v.end());

        int lo = 0, hi = maxC;
        while (hi - lo > 1)
        {
            int mid = (hi + lo) / 2;

            if (check(mid, N, C, v))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        if (check(hi, N, C, v))
        {
            cout << hi << endl;
        }
        else
        {
            cout << lo << endl;
        }

        // for (int i = 0; i < N; i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
    }

    return 0;
}

// https://www.spoj.com/problems/AGGRCOW/