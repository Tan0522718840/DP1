#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int n,dp[100001];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<n;i++)
    {
        if(i==1)
        {
            dp[i]=dp[i-1]+abs(arr[i]-arr[i-1]);
        }
        else
        dp[i]+=min(dp[i-1] + abs(arr[i]-arr[i-1]), dp[i-2] + abs(arr[i]-arr[i-2]));
    }
    cout<<dp[n-1]<<endl;
}





