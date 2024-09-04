
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2,3,5,6,7};
    int toFind = 4;

    int lo = 0, hi = v.size() - 1, mid = 0;

    while (hi - lo > 1)
    {
        mid = (hi+lo)/2;

        if (v[mid] < toFind)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    
    if (toFind == v[lo])
    {
        cout << lo << endl;
    }
    else if (toFind == v[hi])
    {
        cout << hi << endl;
    }
    else
    {
        cout << "Not found!" << endl;
    }

    return 0;
}