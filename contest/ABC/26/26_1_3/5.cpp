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
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    sort(a.begin(),a.end(),[&](const auto& x,const auto& y){
        if (x.fi == y.fi) return x.se > y.se;
        return x.fi < y.fi;
    });
    
    vt g;
    for (auto [b,x] : a)
    {
        auto it = lower_bound(g.begin(),g.end(),x);
        if (it == g.end()) g.push_back(x);
        else *it = x;
    }
    cout << g.size() << endl;
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