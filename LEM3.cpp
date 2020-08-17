#include<bits/stdc++.h>

using namespace std;
int n,a[100][100],f[17][65540];
int getbit(int i,int d)
{
	return (d>>i)&1;
}
int tatbit(int i,int d)
{
	return d^(1<<i);
}
int F(int i,int d)
{
	if(d==0)return 0;
	if(f[i][d]!=-1) return f[i][d];

	f[i][d]=1e9;
	for(int j = 1; j <= n; j++)
	{
		if(getbit(j-1, d))
			f[i][d] = min(f[i][d], F(j,tatbit(j-1,d)) + a[i][j]);
	}
	return f[i][d];
}
int main()
{
	memset(f,-1,sizeof(f));
	cin>>n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>a[i][j];

	cout<<F(0, (1<<n) - 1);
}
