#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int n,m,N,x,y,ans1=-1,ans2,f[300010],g[300010],num[300010];
bool vis[300010];
void Init()
{
	for(int i=1;i<=n;i++)
	{
		int k=read(),sum=0;
		for(int d;k--;){d=read();sum|=(1<<d-1);}
		f[sum]++;
	}
	for(int i=0;i<=8;i++)
		for(int j=0;j<=N;j++)
			if(j&(1<<i))f[j]+=f[j^(1<<i)];
	for(int i=1;i<=m;i++)
	{
		int c=read(),k=read(),sum=0;
		for(int d;k--;){d=read();sum|=(1<<d-1);}
		if(num[sum])
		{
			if(f[sum]>ans1)ans1=f[sum],ans2=g[sum]+c,x=num[sum],y=i;
			else if(f[sum]==ans1 && c+g[sum]<ans2)ans2=g[sum]+c,x=num[sum],y=i;
		}
		if(g[sum]>c)g[sum]=c,num[sum]=i;
		vis[sum]=1;
	}
}
main()
{
	n=read();m=read();
	N=(1<<9)-1;
	for(int i=0;i<=N;i++)g[i]=2147483647;
	Init();
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			if(vis[i] && vis[j] && i!=j)
			{
				int sum=f[i|j];
				if(sum>ans1)ans1=sum,ans2=g[i]+g[j],x=num[i],y=num[j];
				else if(sum==ans1 && g[i]+g[j]<ans2)ans2=g[i]+g[j],x=num[i],y=num[j];
			}
	printf("%lld %lld",x,y);
	return 0;
}
