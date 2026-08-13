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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    int n,x,y;
    cin >> n >> x >> y;
    vll f(50);
    f[0] = f[1] = 1;
    for (int i = 2;i < 45;i++) f[i] = f[i - 1] + f[i - 2];
    auto dfs = [&](auto&& self,int n,int x,int y)
    {
        if (n == 1) return 1;
        if (y > f[n - 1] && y <= f[n]) return 0;
        if (y <= f[n - 1]) return self(self,n - 1,y,x);
        return self(self,n - 1,y - f[n],x);
    };
    if (dfs(dfs,n,x,y)) YES;
    else NO;

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