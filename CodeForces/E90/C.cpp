#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1100000;
int F[MAXN];
char s[MAXN];
int sum[MAXN];
int n;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(sum, 0, sizeof(sum));
		memset(F, 0, sizeof(F));
		scanf("%s", s+1);
		n = strlen(s+1);
		int maxs = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == '+')
			{
				sum[i] = sum[i-1]-1;
			}
			else if (s[i] == '-')
				sum[i] = sum[i-1]+1;
			if (sum[i] >= 0 && F[sum[i]] == 0)
			{
				F[sum[i]] = i;
				if (sum[i] > maxs)
					maxs = sum[i];
			}
			if(sum[i] == 0)
				F[sum[i]] = i;
		}
		
		ll res = 0;
		for (int i = 0; i < maxs; i++)
		{
//			printf("i: %d F[i]: %d\n", i+1, F[i+1]);
			res += F[i+1];
		}
//		if (maxs == 0)
//		{
//			res -= F[0];
//			res += n;
//		}
//		else
			res += n;
		printf("%lld\n", res);
		
	}
	return 0;
}

