#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vvt edge(m);
    vvt g(n);
    for (int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        if (a > b) swap(a,b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (m == 0)
    {
        cout << "R";
        for (int i = 1;i < n;i++) cout << "B";
        cout << endl;
        return ;
    }
    vt vis(n);
    vt color(n,-1);
    for (int i = 0;i < n;i++)
    {
        if (color[i] != -1) continue;
        if (g[i].empty()) continue;
        color[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y : g[x])
            {
                if (color[y] == -1) 
                {
                    color[y] = color[x] ^ 1;
                    q.push(y);
                }
            }
        }
    }
    string ans(n,'#');
    int st = 0;
    // for (int x : color) cout << x << " ";
    // cout << endl;
    for (int i = 0;i < n;i++) 
    {
        if (color[i] == -1) continue;
        st = i;
        break;
    }
    for (int i = st;i < n;i++)
    {
        if (color[i] == 0) ans[i] = 'B';
        else if (color[i] == 1) ans[i] = 'R';
        else 
        {
            int last = (i - 1 + n) % n;
            if (color[last] == 0)
            {
                ans[i] = 'R';
                color[i] = 1;
            }
            else 
            {
                ans[i] = 'B';
                color[i] = 0;
            }
        }
    }
    for (int i = st - 1;i >= 0;i--)
    {
        if (color[i] == 0) ans[i] = 'B';
        else if (color[i] == 1) ans[i] = 'R';
        else 
        {
            int last = (i + 1) % n;
            if (color[last] == 0)
            {
                ans[i] = 'R';
                color[i] = 1;
            }
            else 
            {
                ans[i] = 'B';
                color[i] = 0;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

    return 0;
}