#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int minCoins(vector<int> &coins, int M, int V)
	{
		int r = M + 1;
		int c = V + 1;

		vector<int> dp(c, V + 1);
		dp[0] = 0;

		for (int i = 1; i < r; i++)
		{
			for (int j = 1; j < c; j++)
			{
				if (coins[i - 1] <= j)
				{
					dp[j] = min(dp[j], 1 + dp[j - coins[i - 1]]);
				}
				else
				{
					dp[j] = dp[j];
				}
			}
		}

		for (int j = 0; j < c; j++)
		{
			cout << dp[j] << " ";
		}
		cout << endl;

		return (dp[c - 1] > V) ? -1 : dp[c - 1];
	}
};

int main()
{
	int V = 11, M = 4;
	vector<int> coins = {9, 6, 4, 5};

	Solution sol;
	cout << sol.minCoins(coins, M, V) << endl;

	return 0;
}

// https://www.geeksforgeeks.org/problems/number-of-coins1824/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article