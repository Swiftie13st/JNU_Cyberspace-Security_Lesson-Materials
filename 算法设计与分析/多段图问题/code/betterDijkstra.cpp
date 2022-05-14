#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 510;

int h[N], e[N], ne[N], w[N], idx; //链式向前星
int n, m;
bool st[N];
int d[N];
int pre[N];
vector<int> path;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size())
    {
        auto x = heap.top();
        heap.pop();
        auto t = x.second, dist = x.first;
        if(st[t])
            continue;
        st[t] = true;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] > dist + w[i])
            {
                d[j] = dist + w[i];
                pre[j] = t;
                heap.push({d[j], j});
            }
        }
    }
    return d[n] == 0x3f3f3f3f ? -1 : d[n];
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