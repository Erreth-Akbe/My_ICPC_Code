#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200100;
int n, k;
int a[MAXN];
bool flag[MAXN];
typedef struct
{
	int val;
	int id;
}node;
bool cmp(node a, node b)
{
	return a.val < b.val;
}
node b[MAXN];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		B[i].id = i;
		B[i].val = A[i];
	}
	sort(B+1, B+1+n, cmp);
	int k2 = k/2;
	for (int i = 1; i <= n; i++)
	{
		
	}
	return 0;
}

