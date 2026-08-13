#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

vector<int> bfs(vector <vector<int>>& g,int i)
{
    int n = g.size();
    vector<int> dis(n,-1);
    queue<int> q;
    q.push(i);
    dis[i] = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        for (int j : g[i])
        {
            if (dis[j] == -1)
            {
                dis[j] = dis[i] + 1;
                q.push(j);
            }
        }
    }
    return dis;
}
void solve()
{
    int n;
    cin >> n;
    vector <vector<int>> g(n + 1);
    int a,b;
    cin >> a >> b;
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    unordered_map<int,int> leaf;
    for (int i = 1;i <= n;i++)
    {
        if (g[i].size() == 1) leaf[i] = 1;
    }
    vector <int> da = bfs(g,a);
    vector <int> db = bfs(g,b);

    int flag = 1;//0 r 1 p 
    for (int i = 1;i <= n;i++)
    {
        if (leaf.count(i))
        {
            int l = 2 * (da[i] - 1);
            int r = db[i] - 1;
            if (l < r) 
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag) cout << "purple" << endl;
    else cout << "red" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}