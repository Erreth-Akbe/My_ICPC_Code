#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k;
int main()
{
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		ll ans = 0;
		scanf("%lld%lld%lld", &n, &m, &k);
		if (m < k)
		{
			ll index = 0;
			while (m--)
			{
				index = 1+(index+k-1)%n;
				n--;
			}
			ans = index;
		}
		else
		{
			if (k == 1)
			{
				ans = m;
			}
			else
			{
				ll a = n-m+1;
				ll b = 1;
				ll index = k%a;
				ll x = 0;
				if (index == 0) index = a;
				while (b+x <= m)
				{
					a += x;
					b += x;
					index += k*x;
					index = index%a;
					if (index == 0) index = a;
					x = (a-index)/(k-1)+1;
				} 
				index += (m-b)*k;
				index %= n;
				if (index == 0) index = n;
				ans = index;
			}
		}
		printf("Case #%d: %lld\n", test, ans);
	}
	return 0;
}

