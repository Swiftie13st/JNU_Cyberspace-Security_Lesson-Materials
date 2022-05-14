#include<bits/stdc++.h>
using namespace std;

const int N = 510;
int g[N][N];
int n, m;
int d[N];
bool st[N];
int pre[N]; 
vector<int> path;

int dijkstra()
{
    memset(d, 0x3f, sizeof(d)); 
    d[1] = 0;
    for(int i = 1; i < n; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n; j ++)
            if(!st[j] && (t == -1 || d[t] > d[j]))//如果没有更新过，则进行更新， 或者发现更短的路径，则进行更新
                t = j;
        st[t] = true;
        
        for(int j = 1; j <= n; j ++)
            if(!st[j])
            {
                if(d[j] > d[t] + d[t] + g[t][j])
                {
                    pre[j] = t; //存储前一个点
                    d[j] = d[t] + g[t][j];
                    
                }
            }
                
    }
    return d[n] == 0x3f3f3f3f ? -1 : d[n];
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
    cout << "The minimum cost is: " << dijkstra() << endl;
    for(int i = n; pre[i]; i = pre[i]) //倒序路径
        path.push_back(pre[i]);
    reverse(path.begin(), path.end());
    path.push_back(n);
    cout << "The path is: ";
    for(auto x : path)
        cout << x << ' ';


    return 0;
}