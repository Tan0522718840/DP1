#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, a[100], k;
ll f[17][1<<16];

int getbit(int i,int d)
{
	return d >> i & 1;
}
int batbit(int i,int d)
{
	return d | (1 << i);
}
ll F(int i,int d)
{
	if(d == (1 << n) - 1) return 1;
	if(f[i][d] != -1) return f[i][d];

	f[i][d]=0;
	for(int j = 1; j <= n; j++)
		if(getbit(j-1, d) == 0 && abs(a[i] - a[j]) > k)
				f[i][d] += F(j, batbit(j-1,d));

	return f[i][d];
}
main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];

	memset(f, -1, sizeof(f));
	a[0] = -1e9;
	cout << F(0,0);
}
