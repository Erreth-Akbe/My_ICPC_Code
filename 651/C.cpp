#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
bool check(ll x)
{
	if (x == 2) return true;
	ll tot = 0;	
	ll tote = 0;
	while (x%2 == 0)
	{
		x/=2;	
		tot++;	
	}
	ll bar = sqrt(x);
	int i = 3;
	for (int i = 3; i <= bar; i++)
	{
		while (x%i == 0)
		{
			x /= i;
			tote++;
		}
	}
	if (x != 1) tote ++;
//	printf("tote: %d\n", tote);
	if (tot == 1)
	{
		if(tote == 1) return false;
		else return true;	
	}
	else
	{
		if (tote != 0) return true;
		else return false;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &n);
		if (check(n))
			printf("Ashishgup\n");
		else
			printf("FastestFinger\n");
	}
	return 0;
}

