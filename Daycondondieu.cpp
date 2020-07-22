#include<bits/stdc++.h>
using namespace std;
int n,A[100001],L[100001],ans;
main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for(int i = 1; i <= n; i++)
    {
        L[i] = 1;
        for(int j = 1; j < i; j++)
            if(A[j] < A[i]) L[i] = max(L[i],L[j]+1);
        ans = max(ans, L[i]);
    }
    printf("%d", ans);
}
