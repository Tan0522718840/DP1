#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int n,dp[100001],k;
int main()
{
    cin >> n >>k;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 2; i <= n; i++)
    {
        dp[i] = 1e9;
        for(int j = 1; j <= k; j++)
        {
            if(i - j <= 0) break;
            dp[i] = min(dp[i], dp[i-j] + abs(arr[i]-arr[i-j]));
        }
    }
    cout << dp[n];
}






