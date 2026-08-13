#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(m);
    map<int,vt> g;
    int mn = INT_MAX,mx = 0;
    for (int i = 0;i < m;i++) 
    {
        cin >> a[i];
        int x = a[i] / 100;
        mn = min(mn, x);
        mx = max(mx, x);
        g[x].push_back(a[i]);
    }
    vt b;
    for (auto& [x, f] : g)
    {
        for (int y : f) b.push_back(y);
    }
    vector ans(n,vector<int>(6));
    int l = 0,r = m - 1,cnt = 0;
    for (int i = 0;i < n;i++)
    {
        ans[i][0] = b[l++];
        ans[i][1] = b[r--];
        if (cnt >= (n + 1) / 2)
        {
            ans[i][0] = ans[i - (n + 1) / 2][1];
            ans[i][1] = ans[i - (n + 1) / 2][0];
        }
        cnt++;
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 2;j < 6;j++)
        {
            ans[i][j] = ans[i][j - 2];
        }
    }
    for (int i = 0;i < n;i++) 
    {
        for (int x : ans[i]) cout << x << " ";
        cout << endl;
    }
    
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