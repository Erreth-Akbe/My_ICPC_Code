#include<bits/stdc++.h>
#define ll long long
using namespace std;
int x, y, n;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &x, &y, &n);
		int ans;
		int res = n%x;
		if (res < y)
		{
			ans = (n/x-1)*x+y;
		}
		else
		{
			ans = n/x*x+y;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}

