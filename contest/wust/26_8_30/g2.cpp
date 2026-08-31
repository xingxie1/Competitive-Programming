#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;
using pii = pair<int,int>;
using vpii = vector<pii>;

class FenwickTree
{
    vt tr;
public:
    FenwickTree (int n) : tr(n + 1) {}
    void update(int i,int v) 
    {
        for (;i < tr.size();i += i & -i) tr[i] += v;
    }
    void clear() 
    {
        for (int i = 1;i < tr.size();i++) tr[i] = 0;
    }
    int pre(int i) 
    {
        int res = 0;
        for (;i > 0;i &= i - 1) 
        {
            res += tr[i];
        }
        return res;
    }
    int query(int l,int r) 
    {
        if (r < l) return 0;
        return pre(r) - pre(l - 1);
    }
};

void solve()
{
    int n,m;
    while (cin >> m >> n)
    {
        vpii a(n);
        for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
        if (n % 2 == 1) 
        {
            cout << -1 << endl;
            continue;
        }
        vpii b1 = a,b2 = a,b3 = a,b4 = a;
        for (auto& [x,y] : b2) x = m - x - 1,y = m - y - 1;
        for (auto& [x,y] : b3)
        {
            int tmp = x;
            x = y;
            y = m - tmp - 1;
        }
        for (auto& [x,y] : b4)
        {
            int tmp = y;
            y = x;
            x = m - tmp - 1;
        }
        auto f = [&](vpii& b)
        {
            ranges::sort(b);
            vt tmp;
            for (int i = 0;i < n;i++) tmp.push_back(b[i].se);
            ranges::sort(tmp);
            tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
            ll ans = LLONG_MAX / 2;
            FenwickTree tr(n);
            for (int i = 0;i < n;i++)
            {
                int j = i; 
                while (j < n && b[j].fi == b[i].fi) 
                {
                    auto id = ranges::lower_bound(tmp,b[j].se) - tmp.begin() + 1;
                    tr.update(id,1);
                    j++;
                }
                i = j - 1;
                int l = -1,r = m;
                auto check = [&](int x) 
                {
                    auto it = ranges::upper_bound(tmp,x) - tmp.begin();
                    int cnt = tr.query(1,it);
                    return cnt >= n / 2;
                };
                while (l + 1 < r)
                {
                    int mid = l + r >> 1;
                    if (check(mid)) r = mid;
                    else l = mid;
                }
                auto it = ranges::upper_bound(tmp,r) - tmp.begin();
                int cnt = tr.query(1,it);
                if (cnt == n / 2)
                {
                    ans = min(ans,1LL * (b[i].fi + 1) * (r + 1));
                }
            }
            // tr.clear();
            // tmp.clear();
            // for (int i = 0;i < n;i++) tmp.push_back(b[i].fi);
            // ranges::sort(b,{},[&](auto& c) {
            //     return c.se;
            // });
            // ranges::sort(tmp);
            // tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
            // for (int i = 0;i < n;i++)
            // {
            //     int j = i;
            //     while (j < n && b[j].se == b[i].se) 
            //     {
            //         auto id = ranges::lower_bound(tmp,b[j].fi) - tmp.begin() + 1;
            //         tr.update(id,1);
            //         j++;
            //     }
            //     i = j - 1;
            //     int l = -1,r = m;
            //     auto check = [&](int x) 
            //     {
            //         auto it = ranges::upper_bound(tmp,x) - tmp.begin();
            //         int cnt = tr.query(1,it);
            //         return cnt >= n / 2;
            //     };
            //     while (l + 1 < r)
            //     {
            //         int mid = l + r >> 1;
            //         if (check(mid)) r = mid;
            //         else l = mid;
            //     }
            //     auto it = ranges::upper_bound(tmp,r) - tmp.begin();
            //     int cnt = tr.query(1,it);
            //     if (cnt == n / 2)
            //     {
            //         ans = min(ans,1LL * (b[i].se + 1) * (r + 1));
            //     }
            // }
            return ans;
        };
        ll ans = min({f(b1),f(b2),f(b3),f(b4)});
        if (ans == LLONG_MAX / 2) cout << -1 << endl;
        else cout << ans << endl;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}