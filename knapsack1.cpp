#include <bits/stdc++.h>

using namespace std;

int w[105],v[105],dp[103][100005];
int main() {
    int N, W;
    cin >> N >> W;

    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][W];

    return 0;
}
