#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define reset(x,y) memset(x, y,sizeof(x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EL putchar('\n');
#define oo 1000006
#define INF 0x3f3f3f3f
ll base=1e9+7;
int m,n;
int f[1<<6][31];
void ReadInPut()
{
    cin >> m >> n;
    if(m > n) swap(m, n);
}
bool check(int i,int k)
{
    int tmp = i | k;
    for(int j = 1; j < m; j++)
        if( !(tmp >> j & 1) && !(tmp >> (j-1) & 1) ) return 0;
    tmp = i & k;
    for(int j = 1; j < m; j++)
        if( (tmp >> j & 1) && (tmp >> (j-1) & 1) ) return 0;
    return 1;
}
int dp(int i, int j)
{
    if(j > n) return 1;
    if(f[i][j] != -1) return f[i][j];

    int res=0;
    for(int k = 0; k < (1<<m); k++)
        if(check(i,k) || j == 1) res += dp(k, j+1);
    f[i][j] = res;
    return res;
}
void Solve()
{
    reset(f, -1);
    cout << dp(0,1) << '\n';
}
main()
{
    int sotest=1;
    cin>>sotest;
    for(int i=1;i<=sotest;i++)
    {
        ReadInPut();
        Solve();
    }
}
