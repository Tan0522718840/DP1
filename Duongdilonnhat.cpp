#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)

const int N = 150, inf = N*N*N;;
int n, m, F[N][N], a[N][N], ans = -inf;

int main() {

	scanf("%d%d", &n,&m);
	FOR(i,1,m) F[0][i] = F[n+1][i] = -inf;

	FOR(i,1,n) FOR(j,1,m) scanf("%d", &a[i][j]);

	FOR(j,1,m)
        FOR(i,1,n)
            F[i][j] = a[i][j] + max(F[i-1][j-1], max(F[i][j-1], F[i+1][j-1]));

	FOR(i,1,n) ans = max(ans, F[i][m]);

	printf("%d", ans);

	return 0;
}
