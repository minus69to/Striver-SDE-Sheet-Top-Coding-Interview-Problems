#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    bool static comp(const struct Item &a, const struct Item &b)
    {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr + n, comp);

        double ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= w)
            {
                ans += arr[i].value;
                w -= arr[i].weight;
            }
            else
            {

                ans += ((double)arr[i].value / arr[i].weight) * w;
                break;
            }
        }

        return ans;
    }
};

int main()
{
    int n = 3;
    int w = 50;

    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};

    struct Item items[3];

    for (int i = 0; i < n; i++)
    {
        items[i].value = value[i];
        items[i].weight = weight[i];
    }

    Solution sol;
    cout << sol.fractionalKnapsack(w, items, n) << endl;

    return 0;
}

// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1