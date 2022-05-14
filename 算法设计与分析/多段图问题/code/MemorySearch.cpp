#include<bits/stdc++.h>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;


int h[N], e[N], ne[N], w[N], idx; //链式向前星
int n, m;
int d[N];
int pre[N];
vector<int> path;
int f[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dp(int u)
{
    int &v = f[u];
    if(v != INF)    //已被搜索过
        return v;
    v = 1e9; //一个较大的数不能是INF
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        int t = dp(j) + w[i];
        if(t < v)
        {
            v = t;
            pre[u] = j;
        }
        
    }
    return v;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m --)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z); //建立反向边
    }
    memset(f, 0x3f, sizeof f);
    f[1] = 0;
    dp(n);

    cout << "The minimum cost is: " << f[n] << endl;
    for(int i = n; pre[i]; i = pre[i]) //倒序路径
        path.push_back(pre[i]);
    reverse(path.begin(), path.end());
    path.push_back(n);
    cout << "The path is: ";
    for(auto x : path)
        cout << x << ' ';
    return 0;
}