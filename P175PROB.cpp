#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 20;
int n, k;
int c[MAXN][MAXN];
int dp[1 << MAXN];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &c[i][j]);
        }
    }
    memset(dp, INF, sizeof(dp));
    dp[(1 << n) - 1] = 0;
    for (int mask = (1 << n) - 2; mask >= 1; --mask) {
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1 ^ 1) {
                int premask = mask | 1 << i;
                for (int j = 0; j < n; ++j) {
                    if (mask >> j & 1) {
                        dp[mask] = min(dp[mask], dp[premask] + c[i][j]);
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += mask >> i & 1;
        }
        if (cnt == k) {
            ans = min(ans, dp[mask]);
        }
    }
    printf("%d", ans);
}

