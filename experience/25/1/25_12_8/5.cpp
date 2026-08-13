#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        g[b].push_back(a);
    }
    int Q;
    cin >> Q;
    vector<int> good(n + 1);
    while (Q--)
    {
        int t,v;
        cin >> t >> v;
        if (t == 1)
        {
            if (!good[v])
            {
                queue<int> q;
                q.push(v);
                good[v] = 1;
                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    for (int y : g[x])
                    {
                        if (!good[y])
                        {
                            good[y] = 1;
                            q.push(y);
                        }
                    }
                }
            }
        }
        else 
        {
            if (good[v]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}