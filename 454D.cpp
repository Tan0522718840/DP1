#include<cstdio>
#include<cmath> 
using namespace std;

int n;
int a[105];
int dp[105][(1<<16)+5],maps[105][(1<<16)+5];
int zs[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int m[55];

void memset()
{
	for(int i=1;i<=58;i++)
	{
		for(int j=0;j<=15;j++)
		{
			if(i%zs[j]==0)
			{
				m[i]^=(1<<j);
			}
		}
	}
}

void print(int x,int y)
{
	if(!x)return;
	print(x-1,y^m[maps[x][y]]);
	printf("%d ",maps[x][y]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	memset();
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(1<<16);j++)
		{
			dp[i][j]=2147384653;
			for(int k=1;k<=58;k++)
			{
				if((m[k]|j)==j)
				{
					int tmp=abs(k-a[i])+dp[i-1][j^m[k]];
					if(tmp<dp[i][j])
					{
						dp[i][j]=tmp;
						maps[i][j]=k;
					}
				}
			}
		}
	}
	print(n,(1<<16)-1);
}

    	     		  			 					   	   	
