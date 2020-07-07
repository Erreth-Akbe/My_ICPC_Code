#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 130000;
int n;
int A[MAXN];
ll ans[MAXN];
ll sum[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		sum[1] = 0;
		scanf("%d", &n);
		for (int i = 2; i <= n; i++)
		{
			scanf("%d", &A[i]);
			sum[i] = sum[i-1]+A[i];
		}
		ll cur = 0;
		int pos1 = 2;
		int pos2 = n-1;
		ans[1] = 0;
		cur = sum[n];
		ans[2] = sum[n];
		for (int i = 3; i <= n; i++)
		{
			if (i%2)
				ans[i] = ans[i-1]+cur;
			else
			{
				cur += sum[pos2]-sum[pos1];
				ans[i] = ans[i-1]+cur;
				pos1++;
				pos2--;
			 } 
		}
		
		for (int i = 1; i <= n; i++)
		{
			if (i != 1)
				printf(" ");
			printf("%lld", ans[i]);
		}
		printf("\n");
	}
	return 0;
}

