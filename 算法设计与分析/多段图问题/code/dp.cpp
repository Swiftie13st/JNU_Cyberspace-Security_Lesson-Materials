#include<bits/stdc++.h>
using namespace std;


const int N = 510, INF = 0x3f3f3f3f, K = 10;
int n, m; 
int g[N][N];
int k; //k表示一共几段
vector<vector<int>> t(K);//顶点在第几层
vector<int> path;
int pre[N];

int f[K][K]; //f[i][j] 表示起点到i层的第j个点的最短距离   f[i][j] = min(f[i - 1][0 ... k] + w[0 ... k])   答案:f[k][0];

void dp()
{
    for(int i = 1; i <= k; i ++)
    {
        int ki = t[i].size(), kj = t[i - 1].size();   //第i和i - 1层有几个点 
        for(int j = 0; j < ki; j ++)
        {
            for(int _ = 0; _ < kj; _ ++)
            {
                int v_ = t[i - 1][_], vi = t[i][j]; 
                if(f[i - 1][_] + g[v_][vi] < f[i][j])
                {
                    f[i][j] = f[i - 1][_] + g[v_][vi];
                    pre[vi] = v_;
                }
            }
        }
    }
}



int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m --)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
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
    dp();
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