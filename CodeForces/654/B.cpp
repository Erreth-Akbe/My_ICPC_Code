#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, r;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &n, &r);
		ll ans;
		if (n >= r+1)
		{
			ans = (r+1)*r/2;
		}
		else
		{
			ans = n*(n-1)/2+1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

