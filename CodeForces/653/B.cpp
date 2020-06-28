#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int two = 0;
		int three = 0;
		scanf("%d", &n);
		while (n%2 == 0)
		{
			two++;
			n /= 2;
		}
		while (n%3 == 0)
		{
			three++;
			n /= 3;
		}
		if (n != 1 || two > three)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n", (three-two)+three);
	}
	return 0;
}

