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

class segtree 
{
    vt mx,mn,sum;
    int n;
    void up(int p) 
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
    }
    void update(int p,int st,int ed,int id,int x) 
    {
        if (st == id && ed == id) 
        {
            sum[p] = x;
            mx[p] = x;
            mn[p] = x;
            return ;
        }
        int m = st + ed >> 1;
        if (id <= m) update(p << 1,st,m,id,x);
        else update(p << 1 | 1,m + 1,ed,id,x);
        up(p);
    };
    int query_max(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return mx[p];
        }
        int m = st + ed >> 1;
        int res = 0;
        if (l <= m) res = max(res,query_max(p << 1,st,m,l,r));
        if (r > m) res = max(res,query_max(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
    int query_min(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return mn[p];
        }
        int m = st + ed >> 1;
        int res = INT_MAX;
        if (l <= m) res = min(res,query_min(p << 1,st,m,l,r));
        if (r > m) res = min(res,query_min(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
    int query_sum(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return sum[p];
        }
        int m = st + ed >> 1;
        int res = 0;
        if (l <= m) res += query_sum(p << 1,st,m,l,r);
        if (r > m) res += query_sum(p << 1 | 1,m + 1,ed,l,r);
        return res;
    }
public:
    segtree(int _n) 
    {
        n = _n;
        sum.assign(n << 2,0);
        mx.assign(n << 2,0);
        mn.assign(n << 2,INT_MAX / 2);
    }
    void update(int id,int x) 
    {
        update(1,0,n - 1,id,x);
    }
    int query_max(int l,int r) 
    {
        if (r < l) return 0;
        return query_max(1,0,n - 1,l,r);
    }
    int query_min(int l,int r) 
    {
        if (r < l) return INT_MAX / 2;
        return query_min(1,0,n - 1,l,r);
    }
    int query_sum(int l,int r) 
    {
        if (r < l) return 0;
        return query_sum(1,0,n - 1,l,r);
    }

};
void solve()
{
    int n;
    while (cin >> n)
    {
        vpii a(n);
        for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
        int q;
        cin >> q;
        while (q--)
        {
            string op1,op2;
            int t;
            cin >> op1 >> op2 >> t;
            // cout << op1 << " " << op2 << " " << t << endl;
            int ans = 0;
            segtree tr(n);
            for (int i = 0;i < n;i++)
            {
                int l = ranges::lower_bound(a,pair{a[i].fi - t,-1}) - a.begin();
                int r = i - 1;
                if (r < l) 
                {
                    tr.update(i,a[i].se);
                    continue;
                }
                // cout << l << " " << r << endl;
                // cout << tr.query_min(l,r) << " " << tr.query_max(l,r) << " " << tr.query_sum(l,r) << endl;
                if (op2 == "avg")
                {
                    int sum = tr.query_sum(l,r);
                    double ave = 1.0 * sum / (r - l + 1);
                    if (op1 == "gt") 
                    {
                        if (a[i].se > ave) ans++;
                    }
                    else 
                    {
                        if (a[i].se < ave) ans++;
                    }
                }
                else if (op2 == "min")
                {
                    int mn = tr.query_min(l,r);
                    if (op1 == "gt") 
                    {
                        if (a[i].se > mn) ans++;
                    }
                    else 
                    {
                        if (a[i].se < mn) ans++;
                    }
                }
                else if (op2 == "max")
                {
                    int mx = tr.query_max(l,r);
                    if (op1 == "gt") 
                    {
                        if (a[i].se > mx) ans++;
                    }
                    else 
                    {
                        if (a[i].se < mx) ans++;
                    }
                }
                tr.update(i,a[i].se);
            }
            cout << ans << endl;
        }
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