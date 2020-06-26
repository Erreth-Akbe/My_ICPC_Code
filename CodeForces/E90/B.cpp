#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXS = 300;
int n;
char s[MAXS];
int tot0;
int tot1;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int tot1 =  0, tot0 = 0;
		scanf("%s", s+1);
		n = strlen(s+1);
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == '0' )
				tot0++;
			if (s[i] == '1')
				tot1++;
		}
		int mint = min(tot1, tot0);
//		printf("tot %d\n", tot);
		if (mint%2)
			printf("DA\n");
		else
			printf("NET\n"); 
	}
	return 0;
}

