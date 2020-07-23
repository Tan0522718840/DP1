#include<bits/stdc++.h>
using namespace std;
int n,L[100001],ans;
struct order
{
    int A,B,C;
}Q[100001];
bool cmp(order A, order B)
{
    return A.B < B.B;
}
main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &Q[i].A);
        scanf("%d", &Q[i].B);
        scanf("%d", &Q[i].C);
    }
    sort(Q+1,Q+1+n,cmp);
    for(int i = 1; i <= n; i++)
    {
        L[i] = Q[i].C;
        for(int j = 1; j < i; j++)
            if(Q[j].B <= Q[i].A) L[i] = max(L[i],L[j]+Q[i].C);
        ans = max(ans, L[i]);
    }
    printf("%d", ans);
}
