#include<bits/stdc++.h>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f, K = 10;
int n, m; 
int g[N][N];
int k; //k表示一共几段
vector<vector<int>> t(K);//顶点在第几层
vector<int> path;
int pre[N];

int f[K][K]; //f[i][j] 表示起点到i层的第j个点的最短距离

int dp(int u, int v)
{
    int &tmp = f[u][v];
    if(tmp != INF)
        return tmp;
    tmp = 1e9;
    
    int ki = t[u - 1].size(), vi = t[u][v];
    for(int i = 0; i < ki; i ++)
    {
        int c = dp(u - 1, i), vj = t[u - 1][i];
        if(c + g[vi][vj] < tmp)
        {
            tmp = c + g[vi][vj];
            pre[vi] = vj;
        }
    }
    return tmp;
}
int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m --)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[y][x] = min(g[y][x], z);
    }
    cout << "Please enter the level of the graph: ";
    cin >> k;
    for(int i = 1; i <= k; i ++)
    {
        int tmp;
        cout << "Please enter the vertices of level " << i << " (enter 0 to end): ";
        while(cin >> tmp && tmp)     //输入0结束
        {
           t[i].push_back(tmp);
        }
    }
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    dp(k, 0);
    cout << "The minimum cost is: " << f[k][0] << endl;
    for(int i = n; pre[i]; i = pre[i]) //倒序路径
        path.push_back(pre[i]);
    reverse(path.begin(), path.end());
    path.push_back(n);
    cout << "The path is: ";
    for(auto x : path)
        cout << x << ' ';
    return 0;
}
 