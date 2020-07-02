#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 2100;
int n,m,k,s,t,u,v,w,num,num1;
struct Edge {
    int from, to, cap, flow;
};
vector<Edge> edges;
vector<int> G[maxn];
bool vis[maxn];
int d[maxn], cur[maxn];
void Init()
{
    memset(d,0,sizeof d);
    for(int i=0;i<=n+m+4;i++) G[i].clear();
}
void addedge(int from, int to, int cap)
{
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    int m = edges.size();
    G[from].push_back(m-2); G[to].push_back(m-1);
}
bool bfs()
{
    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(s);
    d[s] = 0; vis[s] = 1;
    while (!q.empty())
    {
        int x = q.front(); q.pop();
        for(int i = 0; i < G[x].size(); ++i)
        {
            Edge &e = edges[G[x][i]];
            if (!vis[e.to] && e.cap > e.flow)
            {
                vis[e.to] = 1;
                d[e.to] = d[x] + 1;
                q.push(e.to);
            }
        }
    }
    return vis[t];
}

int dfs(int x,int a)
{
    if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int &i = cur[x]; i < G[x].size(); ++i)
    {
        Edge &e = edges[G[x][i]];
        if (d[e.to] == d[x] + 1 && (f=dfs(e.to, min(a, e.cap-e.flow))) > 0)
        {
            e.flow += f;
            edges[G[x][i]^1].flow -= f;
            flow += f; a -= f;
            if (a == 0) break;
        }
    }
    return flow;
}

int Maxflow(int s, int t)
{
    int flow = 0;
    while (bfs())
    {
        memset(cur,0,sizeof cur);
        flow += dfs(s, INF);
    }
    return flow;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    Init();s=1;t=n+m+3;addedge(s,2,k);
    for(int i=1;i<=n;++i) addedge(s,i+2,1),addedge(2,i+2,1);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&num);
        while(num--)
        {
            scanf("%d",&num1);
            addedge(i+2,num1+n+2,1);
        }
    }
    for(int i=1;i<=m;++i) addedge(i+n+2,t,1);
    printf("%d\n",Maxflow(s,t));
    return 0;
 }
