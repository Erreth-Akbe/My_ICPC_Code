#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, c;
ll bar;
ll ans1, ans2;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a < c)
		{
			ans1 = 1;
		}
		else
		{
			ans1 = -1;
		}
		if (c < a*b)
		{
			ans2 = b;
		}
		else
		{
			ans2 = -1;
		}
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}

