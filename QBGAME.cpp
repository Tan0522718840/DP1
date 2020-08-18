#include<cstdio>
#include<algorithm>
using namespace std;

#define N 10000
int n, a[8][N];
long long f[256][N];
int state[256], cnt;

inline long long sumCol(int col, int state) {
	long long res = 0;
	for(int i = 0; i < 8; ++i) if(state & 1 << i) res += a[i][col];
	return res;
}

void enter() {
	scanf("%d", &n);
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
}

void solve() {
	for(int st = 0; st < 256; ++st) {
		bool ok = 1;
		for(int i = 0; i < 7 && ok; ++i) ok = (st & 3 << i) != (3 << i);
		if(ok) state[cnt++] = st;
	}
	for(int i = 0; i < cnt; ++i) f[state[i]][0] = sumCol(0, state[i]);

	for(int i = 1; i < n; ++i)
		for(int j = 0; j < cnt; ++j) {
			long long sum = f[state[j]][i] = sumCol(i, state[j]);
			for(int k = 0; k < cnt; ++k)
				if((state[j] & state[k]) == 0)
					f[state[j]][i] = max(f[state[j]][i], sum + f[state[k]][i-1]);
		}

	long long res = f[0][n-1];
	for(int i = 0; i < cnt; ++i) res = max(res, f[state[i]][n-1]);
	int mx = a[0][0];
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < n; ++j)
			mx = max(mx, a[i][j]);
	printf("%lld\n", mx < 0 ? mx : res);
}

main() {
	enter();
	solve();
	return 0;
}
