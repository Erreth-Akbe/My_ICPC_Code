#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200100;
int n; 
ll A[MAXN];
ll B[MAXN];
int num[MAXN];
void init()
{
	
	return ;
 } 

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll sumE = 0;
		int tota = 0;
		int totb = 0;
		init();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
			if (i%2 == 0)
				sumE += num[i];
		}
//		printf("sumE:%lld\n", sumE);
//		printf("A: ");
		for (int i = 0; i+1 < n; i+=2)
		{
			A[tota++] = num[i+1]-num[i];
//			printf("%ld ", A[tota-1]);
		}
//		printf("\nB: ");
		for (int i = 1; i+1 < n; i+=2)
		{
//			printf("num[i]:%lld num[i+1]:%lld\n", num[i], num[i+1]);
			B[totb++] = num[i]- num[i+1];
//			printf("%ld ", B[totb-1]);
		}
//		cout << endl;
		maxadd = 0;
		ll maxadd = max(maxadd, A[0]);
		ll maxs = A[0];
		for (int i = 1; i < tota; i++)
		{
//			printf("amaxd:%lld\n", maxadd);
			maxs = max(maxs+A[i], A[i]);
			maxadd = max(maxadd, maxs);
		}
		maxs = B[0];
		maxadd = max(maxadd, maxs);
		for (int i = 1; i < totb; i++)
		{
//			printf("bmaxd:%lld\n", maxadd);
			maxs = max(maxs+B[i], B[i]);
			maxadd = max(maxadd, maxs);
		}
//		printf("maxd:%lld\n", maxadd);
		printf("%lld\n", sumE+maxadd);
	}
	return 0;
}

