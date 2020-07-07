#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXF = 4;
const int MAXS = 100;
const int MAXN = 4;
int tmp[MAXF];
const char S[MAXS][MAXS] = {"Typically Otaku",
							"Eye-opener",
							"Young Traveller",
							"Excellent Traveller" ,
							"Contemporary Xu Xiake"};
int A[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int cnt = 0;
		for (int i = 0; i < MAXN; i++)
		{
			scanf("%d", &A[i]);
			if (A[i]) cnt++;
		}
		printf("%s\n", S[cnt]);
	}
	return 0;
}

