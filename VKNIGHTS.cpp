
#include <bits/stdc++.h>
const int N = 110;
const int gain[] = {0, 1, 1, 2, 1, 2, 2, 3};
const int mask1[] = {0, 4, 0, 4, 1, 5, 1, 5};
const int mask2[] = {0, 2, 5, 7, 2, 2, 7, 7};
using namespace std;
int Z[N], F[N][8][8], C[N][8][8];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", Z + i), Z[i]--, Z[i] = Z[i] < 0 ? 0 : (1 << Z[i]);
    F[1][Z[1]][Z[2]] = 0; C[1][Z[1]][Z[2]] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 8; j++)
        if (Z[i] == 0 || (j & Z[i]))
            for(int k = 0; k < 8; k++)
            if (Z[i + 1] == 0 || (k & Z[i + 1])) {
                if (C[i][j][k] == 0) continue;
                int &now = F[i][j][k];
                for(int p = 0; p < 8; p++)
                if ((p & j) == 0) {
                    int t1 = k | mask1[p], t2 = Z[i + 2] | mask2[p];
                    int &next = F[i + 1][t1][t2];
                    if (next < now + gain[p]) {
                        next = now + gain[p];
                        C[i + 1][t1][t2] = C[i][j][k];
                    } else
                    if (next == now + gain[p])
                        C[i + 1][t1][t2] += C[i][j][k];
                }
            }
    int res = 0, cnt = 0;
    for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++)
    if (res < F[n + 1][i][j]) {
        res = F[n + 1][i][j];
        cnt = C[n + 1][i][j];
    }
    else
    if (res == F[n + 1][i][j])
        cnt += C[n + 1][i][j];
    printf("%d %d", res, cnt);
	return 0;
}
