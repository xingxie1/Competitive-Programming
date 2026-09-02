#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<ll>;
using pii = pair<int,int>;
using vpii = vector<pii>;
using pll = pair<ll,ll>;
using i128 = __int128_t;

void solve()
{
    int n,m,r;
    cin >> n >> m >> r;
    vpii a(n),b(m);
    map<pii,int> pos;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].fi >> a[i].se;
        pos[{a[i].fi,a[i].se}] = 1;
    }
    for (int i = 0;i < m;i++) cin >> b[i].fi >> b[i].se;
    set<pii> ans;
    for (auto& [x,y] : a)
    {
        auto f = [&](int x1,int y1)
        {
            if (pos.count({x1,y1})) return ;
            // cout << x1 << " " << y1 << endl;
            int f1 = 1,f2 = 1,f3 = 1,f4 = 1;
            int f5 = 1,f6 = 1,f7 = 1,f8 = 1;
            for (auto& [dx,dy] : b)
            {
                if (!pos.count({x1 + dx,y1 + dy})) f1 = 0;
                if (!pos.count({x1 + dy,y1 + dx})) f2 = 0;
                if (!pos.count({x1 - dx,y1 - dy})) f3 = 0;
                if (!pos.count({x1 - dy,y1 - dx})) f4 = 0;

                if (!pos.count({x1 + dx,y1 - dy})) f5 = 0;
                if (!pos.count({x1 + dy,y1 - dx})) f6 = 0;
                if (!pos.count({x1 - dx,y1 + dy})) f7 = 0;
                if (!pos.count({x1 - dy,y1 + dx})) f8 = 0;
            }
            if (f1 || f2 || f3 || f4 || f5 || f6 || f7 || f8) 
            {
                ans.insert({x1,y1});
            }
        };
        f(x + b[0].fi,y + b[0].se);
        f(x - b[0].fi,y - b[0].se);
        f(x + b[0].se,y + b[0].fi);
        f(x - b[0].se,y - b[0].fi);
    }
    if (ans.size() == 0) cout << "Impossible" << endl;
    else if (ans.size() > 1) cout << "Ambiguous" << endl;
    else cout << (ans.begin()->fi) << " " << (ans.begin()->se) << endl;

}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}