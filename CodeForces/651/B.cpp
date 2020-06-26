#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int n2;
const int MAXN = 3100;
int A[MAXN];
int O[MAXN];
int E[MAXN];
int tote, toto;
int DIV(int x)
{
	return x/2*2;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		n2= 2*n;
		tote = toto = 0;
		for (int i = 1; i <= n2; i++)
		{
			scanf("%d", &A[i]);
			if (A[i]%2)
			{
				O[++toto] = i;
			}
			else
			{
				E[++tote] = i;
			}
		}
		if (tote%2 == 0 && toto %2 == 0)
		{
			if (tote > 2)
				tote -=2;
			else
				toto-=2;
		}
		for (int i = 1; i <= DIV(tote); i+=2)
		{
			printf("%d %d\n", E[i], E[i+1]); 
		}
		for (int i = 1; i <= DIV(toto); i+=2)
		{
			printf("%d %d\n", O[i], O[i+1]); 
		}
	}
	return 0;
}

