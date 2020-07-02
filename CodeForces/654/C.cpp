#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, n, m;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		bool flag = true;
		scanf("%lld%lld%lld%lld", &a,&b, &n, &m);
		ll minc = min(a, b);
		ll maxc = max(a, b);
		if (m > minc)
			flag = false;
		else if (n > minc-m+maxc)
			flag = false;
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

