#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1100000;
int n; 
int A[MAXN];
int prime[MAXN];
bool vis[MAXN];
int tot;
vector <ll> mp[MAXN];
void init()
{
	for (int i = 2; i*i < MAXN; i++)
	{
		if(!vis[i])
		{
			for (int j = i*i; j < MAXN; j += i)
			{
				vis[j] = true;
			}
		}
	}
	for  (int i = 2; i <= MAXN; i++)
	{
		if (!vis[i])
		{
			prime[tot++] = i;
		}
	}
	for (int i = 0; i < MAXN; i++)
		mp[i].push_back(0);
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	init();
	for (int i = 1; i <= n; i++)
	{
		int tmp = A[i];
		for (int j = 0; j < tot && prime[j]*prime[j] <= tmp; j++)
		{
			if (tmp % prime[j] == 0)
			{
				mp[prime[j]].push_back(i);
				while (tmp%prime[j] == 0) tmp /= prime[j];
			}
		}
		if (tmp > 1) mp[tmp].push_back(i);
	}
	ll ans = 0;
	for (int i = 0; i < tot; i++)
	{
		for (int j = 1; j < mp[prime[i]].size(); j++)
		{
			ans += (mp[prime[i]][j] - mp[prime[i]][j-1])*((ll)n-mp[prime[i]][j]+1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

