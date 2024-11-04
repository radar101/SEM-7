#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    if(ind < 0) return 0;
    if(dp[ind][W] != -1) return dp[ind][W];

    int notTake = knapsack(wt, val, ind - 1, W, dp);
    int take = 0;

    if(W >= wt[ind])
    {
        take = val[ind] + knapsack(wt, val, ind - 1, W - wt[ind], dp);
    }
    return dp[ind][W] = max(notTake, take);
}

int knapsackTabulation(vector<int> &wt, vector<int> &val, int W)
{
	int n = wt.size();
	vector<vector<int>> dp(n, vector<int>(W+1, 0));

	for(int i=wt[0];i <= W; i++)
	{
		dp[0][i] = val[0];
	}

	for(int ind = 1;ind<n;ind++)
	{
		for(int cap = 0;cap<=W;cap++)
		{
			int notTake = dp[ind-1][cap];
			int take = INT_MIN;
			if(cap >= wt[ind])
			{
				take = val[ind] + dp[ind-1][cap-wt[ind]];
			}

			dp[ind][cap] = max(notTake, take);
		}
	}
	return dp[n-1][W];
}


int main()
{
    int n;
    cin >> n;
    vector<int> val(n), weight(n);
    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int W;
    cin >> W;
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    // int ans = knapsack(weight, val, n - 1, W, dp);
    int ans = knapsackTabulation(weight, val, W);
    cout << ans << endl;

    return 0;
}
