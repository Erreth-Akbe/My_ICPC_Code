#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue <int> q1,q2, qboth;
int n, k;
int now;
ll ans;
void init()
{
	now = 0;
	ans = 0;
	while (q1.size()) q1.pop();
	while (q2.size()) q2.pop();
	while (qboth.size()) qboth.pop();
	return; 
}
int main()
{
	scanf("%d%d", &n, &k);
	init();
	int a, b, t;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &t, &a, &b);
		if (a == 1 && b == 1)
			qboth.push(-t);
		else if(a == 1)
			q1.push(-t);
		else if (b == 1)
			q2.push(-t);
	}
	while (now < k 
			&& ((q1.size() && q2.size()) || qboth.size()))
	{
		if (qboth.empty())
		{
			now++;
			ans += -(q1.top()+q2.top());
			q1.pop(); q2.pop();
		}
		else if (q1.empty() || q2.empty())
		{
			now++;
			ans += -qboth.top();
			qboth.pop();
		}
		else
		{
			int t1, t2, tboth;
			t1 = -q1.top();
			t2 = -q2.top();
			tboth = - qboth.top();
			if (t1+t2 < tboth)
			{
				ans += t1+t2;
				q1.pop();
				q2.pop();
			}
			else
			{
				ans += tboth;
				qboth.pop();
			}
			now++; 
		}
	}
	if (now == k)
		printf("%lld\n", ans);
	else
		printf("-1\n");
	return 0;
}

