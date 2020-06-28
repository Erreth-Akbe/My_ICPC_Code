#include<bits/stdc++.h>
#define ll long long
using namespace std;
stack <int> st;
int n;
const int MAXN = 500;
char s[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int cnt = 0;
		scanf("%d", &n);
		scanf("%s", s+1);
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == '(')
			{
				st.push(i);
			}
			else if (s[i] == ')' && st.size())
			{
				st.pop();
			}
			else if (s[i] == ')' && st.empty())
			{
				cnt++;
			}
		}
		cnt += st.size();
		while (st.size()) st.pop();
		printf("%d\n", cnt/2);
	}	
	 
	return 0;
}

