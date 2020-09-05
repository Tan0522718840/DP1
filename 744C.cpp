#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int N, mx[1<<16][140], r[20], b[20], sumr, sumb, ans=2e9;
char c[20];

int main () {
	scanf("%d", &N);
	fo(i, 0, N) {
		scanf(" %c %d %d", &c[i], &r[i], &b[i]);
		sumr += r[i], sumb += b[i];
	}

	fo(i, 0, (1<<N)) fo(j, 0, 140) mx[i][j] = -2e9;
	mx[0][0] = 0;

	fo(i, 0, (1<<N)-1) {
		int nr = 0, nb = 0;

		fo(j, 0, N) if (i&(1<<j)) {
			if (c[j] == 'R') nr++;
			else nb++;
		}

		fo(j, 0, N) if (!(i&(1<<j))) {
			fo(R, 0, 140) {
				int B = mx[i][R];
				if (B == -2e9) continue;
				mx[i^(1<<j)][R + min(r[j], nr)] = max(mx[i^(1<<j)][R + min(r[j], nr)], B + min(b[j], nb));
			}
		}
	}
	fo(i, 0, 140) if (mx[(1<<N)-1][i] != -2e9) {
		ans = min(ans, max(sumr - i, sumb - mx[(1<<N)-1][i]) + N);
	}
	printf("%d\n", ans);
	return 0;
}
