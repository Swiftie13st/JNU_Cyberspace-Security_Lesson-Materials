```c++
#include<bits/stdc++.h>
using namespace std;

const int N = 510, M = 10010;
int n, m, k;
int d[N], backup[N];
int pre[N];
vector<int> path;

struct{
    int a, b, w;
}edges[M];

int bellman_ford()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for(int i = 0; i < n; i ++)
    {
        memcpy(backup, d, sizeof d);
        for(int j = 0; j < m; j ++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;

            if(d[b] > backup[a] + w)
            {
                pre[b] = a;
                d[b] = backup[a] + w;
            }
        }
    }
    if(d[n] > 0x3f3f3f3f / 2)
        return -1;
    else
        return d[n];
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < m; i ++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }

    
    cout << "The minimum cost is: " << bellman_ford() << endl;
    for(int i = n; pre[i]; i = pre[i]) //倒序路径
        path.push_back(pre[i]);
    reverse(path.begin(), path.end());
    path.push_back(n);
    cout << "The path is: ";
    for(auto x : path)
        cout << x << ' ';
    return 0;
    
    return 0;
}
```