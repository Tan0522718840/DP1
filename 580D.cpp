#include <bits/stdc++.h>
using namespace std;
long long int add[20][20],dp[1000000][20],v[20];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<k;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add[a-1][b-1]=c;
	}
	long long int ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if((i>>j) & 1)
			{
				for(int w=0;w<n;w++){
					if((i>>w) & 1)
						dp[i][j]=max(dp[i][j],dp[i-(1<<j)][w]+v[j]+add[j][w]);
				}
			}
			if(__builtin_popcount(i)==m)
				ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans;

}
