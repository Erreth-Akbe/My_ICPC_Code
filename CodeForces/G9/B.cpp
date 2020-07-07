#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 500;
const int MAXD = 4;
int n, m;
int A[MAXN][MAXN];
int dx[MAXD] = {-1, 0, 1, 0};
int dy[MAXD] = {0, 1, 0, -1};
bool check(int i, int j)
{
	if (i < 0 || i > n-1)
		return false;
	if (j < 0 || j > m-1)
		return false;
	return true;
}
int count(int i, int j)
{
	int cnt = 0;
	for (int d = 0; d < MAXD; d++)
	{
		int x = i+dx[d];
		int y = j+dy[d];
		if (check(x, y) && A[x][y] > 0)
		{
			cnt++;
		}
	}
	return cnt;
}
void add(int i, int j, int num)
{
	for (int d = 0; d < MAXD; d++)
	{
		int x = i+dx[d];
		int y = j+dy[d];
		if (check(x, y) && A[x][y] == 0&&num > 0)
		{
			A[x][y] =1;
			num--;
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &A[i][j]);
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (A[i][j] > 4)
				{
					flag = false;
					break;
				}
				if (((i == 0 && j == 0)
					|| (i == 0 && j == m-1)
					|| (i == n-1 && j == 0)
					|| (i == n-1 && j == m-1)
					) && A[i][j] > 2)
				{
					flag = false;
					break;
				}
				if (((i == 0)||i == n-1 || j == 0 || j == m-1) && A[i][j] > 3)
				{
					flag = false;
					break;
				}
			}
		}
//		printf("AAA\n");
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				printf("%d ", A[i][j]);
//			}
//			printf("\n");
//		}
		if (flag == false)
		{
			printf("NO\n");
			continue;
		}
		else
			printf("YES\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (A[i][j] > 0 && A[i][j] > count(i, j))
				{
//					printf("i: %d j: %d A[i][j]: %d\n", i, j, A[i][j]);
//					printf("count:%d\n", count(i, j));
					add(i, j, A[i][j]-count(i, j));
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (A[i][j] > 0 && A[i][j] < count(i, j))
				{
//					printf("i: %d j: %d A[i][j]: %d\n", i, j, A[i][j]);
//					printf("count:%d\n", count(i, j));
					A[i][j] = count(i, j);
				}
			}
		}
		
//		printf("AAA\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

