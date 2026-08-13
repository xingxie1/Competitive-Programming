#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

class segtree {
    int n;
    vll tr,add;
    void up(int p) 
    {
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }
    void down(int p,int ll,int lr)
    {
        if (add[p] != 0) 
        {
            tr[p << 1] += ll * add[p];
            tr[p << 1 | 1] += lr * add[p];
            add[p << 1] += add[p];
            add[p << 1 | 1] += add[p];
            add[p] = 0;
        }
    }
    void build(int p,int l,int r,const vll& a) 
    {
        if (l == r) 
        {
            tr[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void update(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            tr[p] += v * (ed - st + 1);
            add[p] += v;
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return tr[p];
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res +=  query(p << 1,st,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,ed,l,r);
        return res;
    } 
public: 
    segtree(const vll& a) 
    {
        n = a.size();
        tr.assign(n << 2,0);
        add.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    ll query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
    void update(int l,int r,ll v) 
    {
        update(1,0,n - 1,l,r,v);
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (m--) 
    {
        int j;
        cin >> j;
        ll s = tr.query(j,j);
        tr.update(j,j,-s);
        if (s == 0) continue;
        if (s <= n - j - 1) 
        {
            tr.update(j + 1,j + s,1);
        }
        else 
        {
            if (j + 1 <= n - 1) 
            {
                tr.update(j + 1,n - 1,1);
                s -= (n - j - 1);
            }
            ll c = s / n;
            tr.update(0,n - 1,c);
            s %= n;
            if (s > 0) tr.update(0,s - 1,1);
        }
    }
    for (int i = 0;i < n;i++) cout << tr.query(i,i) << " ";
    cout << endl;
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