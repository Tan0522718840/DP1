#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, a[21][21], f[21][1<<20];
ll D[21][1<<20];
int F(int i,int d)
{
	if(i > n) {D[i][d] = 1; return 0;}
	if(f[i][d] != -1) return f[i][d];

	f[i][d]=0;
	for(int j = 0; j < n; j++)
		if(!(d >> j & 1))
		{
			int nmask = d | (1<<j);
			int tmp = F(i+1, nmask) + a[i][j+1];
			if(tmp == f[i][d]) D[i][d] += D[i+1][nmask];
			if(tmp > f[i][d]) f[i][d] = tmp, D[i][d] = D[i+1][nmask];
		}

	return f[i][d];
}
main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];

	memset(f, -1, sizeof(f));
	cout << F(1,0); cout << " " << D[1][0];
}

