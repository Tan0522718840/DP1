#include<bits/stdc++.h>
using namespace std;
int n, a[201], s, l[201][40001];
int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    l[0][0]=1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= s; j++)
        {
            if(l[i-1][j]) l[i][j] = 1;
            if(j >= a[i] && l[i-1][j - a[i]]) l[i][j] = 1;
        }
    if(l[n][s] == 1)cout<<"YES";
    else cout<<"NO";
}
