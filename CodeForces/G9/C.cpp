#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 400000;
int A[MAXN];
int n;
stack <int> st;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		while (st.size()) st.pop();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &A[i]);
		}
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			if (st.empty())
			{
				st.push(A[i]);
			}
			else
			{
				while (st.size()&&st.top() < A[i])
				{
					st.pop();
				}
				st.push(A[i]);
			}
		}
		if (st.size() != 1)
		{
			flag = false;
		}
		if (flag)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}

