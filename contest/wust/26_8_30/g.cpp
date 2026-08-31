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
        vt tmp;
        for (int i = 0;i < n;i++) 
        {
            cin >> a[i].fi >> a[i].se;
            tmp.push_back(a[i].se);
        }
        if (n % 2 == 1) 
        {
            cout << -1 << endl;
            continue;
        }
        ll ans = LLONG_MAX / 2;
        FenwickTree tr(n);
        // 1
        for (int i = 0;i < n;i++) 
        {
            auto check = [&](int x) 
            {
                auto it = ranges::upper_bound(tmp,x) - tmp.begin();
                int cnt = tr.query(1,it);
                return cnt + 1 >= n / 2;
            };
            int l = -1,r = m;
            while (l + 1 < r)
            {
                int mid = (l + r) / 2;
                if (check(mid)) r = mid;
                else l = mid;
            }
            auto it = ranges::upper_bound(tmp,r) - tmp.begin();
            int cnt = tr.query(1,it);
            if (cnt + 1 == n / 2) ans = min(ans,1LL * (a[i].fi + 1) * (r + 1));
            auto id = ranges::lower_bound(tmp,a[i].se) - tmp.begin() + 1;
            tr.update(id,1);
        }
        tr.clear();
        tmp.clear();
        ranges::sort(a,{},[&](auto& b) {
            return b.se;
        });
        for (int i = 0;i < n;i++) tmp.push_back(a[i].fi);
        ranges::sort(tmp);
        //2
        for (int i = 0;i < n;i++) 
        {
            int l = -1,r = m;
            auto check = [&](int x) 
            {
                auto it = ranges::upper_bound(tmp,x) - tmp.begin();
                int cnt = tr.query(1,it);
                return cnt + 1 >= n / 2;
            };
            while (l + 1 < r)
            {
                int mid = l + r >> 1;
                if (check(mid)) r = mid;
                else l = mid;
            }
            auto it = ranges::upper_bound(tmp,r) - tmp.begin();
            int cnt = tr.query(1,it);
            if (cnt + 1 == n / 2) ans = min(ans,1LL * (a[i].se + 1) * (r + 1));
            auto id = ranges::lower_bound(tmp,a[i].fi) - tmp.begin() + 1;
            tr.update(id,1);
        }
        ranges::sort(a,{},[&](auto& b) {
            return -b.fi;
        });
        tmp.clear();
        tr.clear();
        for (int i = 0;i < n;i++) tmp.push_back(a[i].se);
        ranges::sort(tmp);
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        // //3
        // for (int i = 0;i < n;i++) 
        // {
        //     auto id = ranges::lower_bound(tmp,a[i].se) - tmp.begin() + 1;
        //     int j = i;
        //     while (j < n && a[j].fi == a[i].fi) 
        //     {
        //         tr.update(id,1);
        //         j++;
        //     }
        //     i = j - 1;
        //     int l = -1,r = m;
        //     auto check = [&](int x) 
        //     {
        //         auto it = ranges::upper_bound(tmp,x) - tmp.begin();
        //         int cnt = tr.query(1,it);
        //         return cnt + 1 >= n / 2;
        //     };
        //     while (l + 1 < r)
        //     {
        //         int mid = l + r >> 1;
        //         if (check(mid)) r = mid;
        //         else l = mid;
        //     }
        //     auto it = ranges::upper_bound(tmp,r) - tmp.begin();
        //     int cnt = tr.query(1,it);
        //     if (cnt + 1 == n / 2)
        //     {
        //         ans = min(ans,1LL * (m - a[i].fi) * (r + 1));
        //         // cout << ((m - a[i].fi) * (r + 1)) << endl;
        //         // cout << a[i].fi << " " << r << endl;
        //     }
        // }
        // tmp.clear();
        // tr.clear();
        // ranges::sort(a,{},[&](auto& b) {
        //     return b.se;
        // });
        // for (int i = 0;i < n;i++) tmp.push_back(a[i].fi);
        // ranges::sort(tmp);
        // //4
        // // for (int i = 0;i < n;i++) 
        // // {
        // //     int l = -1,r = m;
        // //     auto check = [&](int x) 
        // //     {
        // //         auto it = ranges::upper_bound(tmp,x) - tmp.begin();
        // //         int cnt = tr.query(1,it);
        // //         return cnt + 1 >= n / 2;
        // //     };
        // //     while (l + 1 < r)
        // //     {
        // //         int mid = l + r >> 1;
        // //         if (check(mid)) r = mid;
        // //         else l = mid;
        // //     }
        // //     auto it = ranges::upper_bound(tmp,r) - tmp.begin();
        // //     int cnt = tr.query(1,it);
        // //     if (cnt + 1 == n / 2) ans = min(ans,1LL * (a[i].se + 1) * (r + 1));
        // //     auto id = ranges::lower_bound(tmp,a[i].fi) - tmp.begin() + 1;
        // //     tr.update(id,1);
        // // }
        // // tmp.clear();
        // // tr.clear();
        // // ranges::sort(a);
        // // //5
        // // for (int i = 0;i < n;i++) tmp.push_back(a[i].se);
        // // ranges::sort(tmp);
        // // for (int i = 0;i < n;i++) 
        // // {
        // //     int l = -1,r = m;
        // //     auto check = [&](int x) 
        // //     {
        // //         auto it = ranges::upper_bound(tmp,x) - tmp.begin();
        // //         int cnt = tr.query(1,it);
        // //         return cnt + 1 >= n / 2;
        // //     };
        // //     while (l + 1 < r)
        // //     {
        // //         int mid = l + r >> 1;
        // //         if (check(mid)) r = mid;
        // //         else l = mid;
        // //     }
        // //     auto it = ranges::upper_bound(tmp,r) - tmp.begin();
        // //     int cnt = tr.query(1,it);
        // //     if (cnt + 1 == n / 2) ans = min(ans,1LL * (a[i].fi + 1) * (r + 1));
        // //     auto id = ranges::lower_bound(tmp,a[i].se) - tmp.begin() + 1;
        // //     tr.update(id,1);
        // // }
        // // tmp.clear();
        // // tr.clear();
        // // ranges::sort(a,{},[&](auto& b){
        // //     return -b.se;
        // // });
        // // for (int i = 0;i < n;i++) tmp.push_back(a[i].fi);
        // // ranges::sort(tmp);
        // // //6
        // // for (int i = 0;i < n;i++) 
        // // {
        // //     int l = -1,r = m;
        // //     auto check = [&](int x) 
        // //     {
        // //         auto it = ranges::upper_bound(tmp,x) - tmp.begin();
        // //         int cnt = tr.query(1,it);
        // //         return cnt + 1 >= n / 2;
        // //     };
        // //     while (l + 1 < r)
        // //     {
        // //         int mid = l + r >> 1;
        // //         if (check(mid)) r = mid;
        // //         else l = mid;
        // //     }
        // //     auto it = ranges::upper_bound(tmp,r) - tmp.begin();
        // //     int cnt = tr.query(1,it);
        // //     if (cnt + 1 == n / 2) ans = min(ans,1LL * (m - a[i].se) * (r + 1));
        // //     auto id = ranges::lower_bound(tmp,a[i].fi) - tmp.begin() + 1;
        // //     tr.update(id,1);
        // // }
        // // tmp.clear();
        // // tr.clear();
        // // ranges::sort(a,{},[&](auto& b) {
        // //     return -b.fi;
        // // });
        // // for (int i = 0;i < n;i++) tmp.push_back(a[i].se);
        // // //7
        // // for (int i = 0;i < n;i++) 
        // // {
        // //     int l = -1,r = m;
        // //     auto check = [&](int x) 
        // //     {
        // //         auto it = ranges::upper_bound(tmp,x) - tmp.begin();
        // //         int cnt = tr.query(1,it);
        // //         return cnt + 1 >= n / 2;
        // //     };
        // //     while (l + 1 < r)
        // //     {
        // //         int mid = l + r >> 1;
        // //         if (check(mid)) r = mid;
        // //         else l = mid;
        // //     }
        // //     auto it = ranges::upper_bound(tmp,r) - tmp.begin();
        // //     int cnt = tr.query(1,it);
        // //     if (cnt + 1 == n / 2) ans = min(ans,1LL * (m - a[i].fi) * (r + 1));
        // //     auto id = ranges::lower_bound(tmp,a[i].se) - tmp.begin() + 1;
        // //     tr.update(id,1);
        // // }
        // // tmp.clear();
        // // tr.clear();
        // // ranges::sort(a,{},[&](auto& b){
        // //     return -b.se;
        // // });
        // // for (int i = 0;i < n;i++) tmp.push_back(a[i].fi);
        // // ranges::sort(tmp);
        // // //8
        // // for (int i = 0;i < n;i++) 
        // // {
        // //     int l = -1,r = m;
        // //     auto check = [&](int x) 
        // //     {
        // //         auto it = ranges::upper_bound(tmp,x) - tmp.begin();
        // //         int cnt = tr.query(1,it);
        // //         return cnt + 1 >= n / 2;
        // //     };
        // //     while (l + 1 < r)
        // //     {
        // //         int mid = l + r >> 1;
        // //         if (check(mid)) r = mid;
        // //         else l = mid;
        // //     }
        // //     auto it = ranges::upper_bound(tmp,r) - tmp.begin();
        // //     int cnt = tr.query(1,it);
        // //     if (cnt + 1 == n / 2) ans = min(ans,1LL * (m - a[i].se) * (r + 1));
        // //     auto id = ranges::lower_bound(tmp,a[i].fi) - tmp.begin() + 1;
        // //     tr.update(id,1);
        // // }
        // cout << ans << endl;
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