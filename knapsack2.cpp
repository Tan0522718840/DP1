#include<bits/stdc++.h>
using namespace std;
int n, w, max_val = 1e5, ans;
long long dp[102][100005];
pair<int, int> arr[102];
int main()
{
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
        cin >> arr[i].first >> arr[i].second;

    for(int i = 0; i <= max_val; i++) dp[1][i] = 1000000001;

    dp[1][0] = 0;
    dp[1][arr[1].second] = arr[1].first;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= max_val; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(arr[i].second > j) continue;
            dp[i][j] = min(arr[i].first + dp[i-1][j-arr[i].second], dp[i][j]);
        }
    }

    for(int x = 0; x <= max_val; x++)
        if(dp[n][x] <= w)
            ans=x;

    cout << ans;
    return 0;
}

