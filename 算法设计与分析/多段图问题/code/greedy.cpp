#include<bits/stdc++.h>
using namespace std;

const int N = 510;

int h[N], e[N], ne[N], w[N], idx; //链式向前星
int n, m;
int d[N];
int pre[N];
vector<int> path;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int greedy()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] > d[t] + w[i])
            {
                d[j] = d[t] + w[i];
                pre[j] = t;
                q.push(j);
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
    cout << "The minimum cost is: " << greedy() << endl;
    for(int i = n; pre[i]; i = pre[i]) //倒序路径
        path.push_back(pre[i]);
    reverse(path.begin(), path.end());
    path.push_back(n);
    cout << "The path is: ";
    for(auto x : path)
        cout << x << ' ';
    return 0;
}