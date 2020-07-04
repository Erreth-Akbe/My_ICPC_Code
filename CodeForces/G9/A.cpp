#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int MAXN = 1000;
int A[MAXN];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (i%2)
				printf("%d ", abs(A[i]));
			else
				printf("%d ", -abs(A[i]));
		}
		printf("\n");
	}
	return 0;
}

