## spfa
```c++
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
bool st[N];
int d[N], pre[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int spfa()
{
    memset(d, 0x3f, sizeof d);
    queue<int> q;
    q.push(1);
    st[1] = true;
    d[1] = 0;
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            
            if(d[j] > d[t] + w[i])
            {
                d[j] = d[t] + w[i];
                pre[j] = t;
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return d[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int t = spfa();
    if(t > 0x3f3f3f3f >> 1)
        cout << "impossible";
    else
        cout << t;
    cout << endl << n << ' ';
    for(int i = n; pre[i] ; i = pre[i]) //倒序输出路径
        cout << pre[i] << ' ';
    return 0;
}
```
