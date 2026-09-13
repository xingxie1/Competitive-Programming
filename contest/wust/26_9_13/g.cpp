#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpll = vector<pair<ll,ll>>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    ranges::sort(b);
    ranges::sort(a);
    vll pre(n + 1);
    vpll tmp;
    for (int i = 0;i < n;i++) tmp.push_back({a[i],0});
    for (int i = 0;i < n;i++) 
    {
        pre[i + 1] = pre[i] + b[i];
        tmp.push_back({pre[i + 1],1});
    }
    ranges::sort(tmp);
    int N = tmp.size();
    priority_queue<pll> pq;
    ll last = -1;
    // for (auto& [x,c] : tmp)
    // {
    //     cout << x << " " << c << endl;
    // }
    for (int i = N - 1;i >= 0;i--) 
    {
        if (tmp[i].se == 0) 
        {
            ll ttt = tmp[i].fi;
            if (last == -1) tmp[i].fi = m - tmp[i].fi;
            else tmp[i].fi = last - tmp[i].fi;
            last = ttt;
        }
        else
        {
            if (last == -1) tmp[i].fi = m - tmp[i].fi;
            else tmp[i].fi = last - tmp[i].fi;
        }
    }
    // cout << "#########" << endl;
    // for (auto& [x,c] : tmp)
    // {
    //     cout << x << " " << c << endl;
    // }
    ll ans = 0;
    ll f = -1;
    int f2 = 0;
    for (int i = N - 1;i >= 0;i--) 
    {
        pq.push({tmp[i].fi,tmp[i].se});
        if (tmp[i].se == 0) f2 = 1;
        if (tmp[i].se == 1) 
        {
            auto [x,o] = pq.top();
            pq.pop();
            ans += x;
            if (o == 1) f = tmp[i].fi; 
        }
        else if (tmp[i].se == 0 && f != -1 && f2) 
        {
            auto [mx,o] = pq.top();
            pq.pop();
            mx += tmp[i].fi - f;
            // cout << tmp[i].fi << " " << f << endl;
            pq.push({mx,1});
            f = -1;
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