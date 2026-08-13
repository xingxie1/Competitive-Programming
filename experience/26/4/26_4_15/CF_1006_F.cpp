#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    ll k;
    cin >> n >> m >> k;
    vvll a(n,vll(m));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) cin >> a[i][j];
    }
    int half = (n + m - 2) / 2;
    map<ll,int> cnt[25];
    ll ans = 0;
    auto dfs1 = [&](auto&& self,int r,int c,ll val)
    {
        val ^= a[r][c];
        if (r + c == half) 
        {
            cnt[r][val]++;
            return ;
        }
        if (r + 1 < n) self(self,r + 1,c,val);
        if (c + 1 < m) self(self,r,c + 1,val);
    };
    auto dfs2 = [&](auto&& self,int r,int c,ll val)
    {
        val ^= a[r][c];
        if (r + c == half)
        {
            ll t = k ^ val ^ a[r][c];
            if (cnt[r].count(t)) ans += cnt[r][t];
            return ;
        }
        if (r - 1 >= 0) self(self,r - 1,c,val);
        if (c - 1 >= 0) self(self,r,c - 1,val);
    };
    dfs1(dfs1,0,0,0);
    dfs2(dfs2,n - 1,m - 1,0);
    cout << ans << endl;
    
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