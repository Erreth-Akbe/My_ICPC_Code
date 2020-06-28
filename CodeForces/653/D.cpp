#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 210000;
ll A[MAXN];
pair <ll, ll> B[MAXN];
map <ll, ll> mp;
int n;
int tot;
ll k;
void init()
{
	for (int i = 0; i < k; i++)
	{
		B[i].first = 0;
		B[i].second = i;
	}
	return;
}
bool cmp(pair <ll, ll> a, pair <ll, ll> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		mp.clear();
		tot = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &A[i]);
			int tmp = A[i]%k;
			if (tmp)
				mp[k-tmp]++;
			else
				mp[0]++;
		}
		if (mp[0] == n)
		{
			printf("0\n");
			continue;
		}
		else
		{
			map <ll, ll> :: iterator it;
			for (it = mp.begin(); it != mp.end(); it++)
			{
//				printf("first:%lld  second:%lld\n", it->first, it->second);
				if (it->first == 0) continue;
				B[tot].first = it->second;
				B[tot++].second = it->first;
			}
			sort(B, B+tot, cmp);
			ll ans;
//			printf("B: \n");
//			for (int i = 0; i < tot; i++)
//				printf("\t%lld", B[i].first);
//			printf("\n");
//			for (int i = 0; i < tot; i++)
//				printf("\t%lld", B[i].second);
//			printf("\n");
			ans = (B[tot-1].first-1)*k+B[tot-1].second+1;
			
			printf("%lld\n", ans);
				
		}
		
	}
	return 0;
}

