#include<bits/stdc++.h>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];   //邻接矩阵存储
int n, m;   //n顶点数，m边数
int d[N];   //距离数组
int res; //答案
bool st[N]; 
vector<int> path;
vector<int> tmp;

void dfs(int u, int cost)
{
    if(cost > res)
        return;
    if(u == n)
    {
        
        if(cost < res)
        {
            res = cost;
            path.assign(tmp.begin(), tmp.end()); //记录路径
        }
        return;
    }
    for(int i = 1; i <= n; i ++)
    {
        if(g[u][i] != INF && !st[i])
        {
            st[i] = true;
            tmp.push_back(i);
            dfs(i, cost + g[u][i]);
            tmp.pop_back();
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    while(m --)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    memset(d, 0, sizeof d);
    res = INF;
    st[1] = true;
    tmp.push_back(1);
    dfs(1, 0);
    cout << "The minimum cost is: " << res << endl;
    cout << "The path is: ";
    for(auto x : path)
        cout << x << ' ';


    return 0;
}