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

class segtree
{
private:
    vector<ll> tree;
    vector<ll> lazy;
    int n;
    void push_up(int p)
    {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }
    void push_down(int p,int lenl,int lenr)
    {
        if (lazy[p] != 0)
        {
            lazy[p << 1] += lazy[p];
            lazy[p << 1 | 1] += lazy[p];
            tree[p << 1] += lazy[p] * lenl;
            tree[p << 1 | 1] += lazy[p] * lenr;
            lazy[p] = 0;
        }
    }
    void build(int p,int l,int r,const vector<ll>& a)
    {
        if (l == r) 
        {
            tree[p] = a[l];
            return ;
        }
        int m = l + (r - l) / 2;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        push_up(p);
    }
    //区间[l,r]加上v
    void update(int p,int start,int end,int l,int r,ll v)
    {
        if (l <= start && end <= r) 
        {
            tree[p] += v * (end - start + 1);
            lazy[p] += v;
            return ;
        }
        int m = start + (end - start) / 2;
        push_down(p,m - start + 1,end - m);
        if (l <= m) update(p << 1,start,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,end,l,r,v);
        push_up(p);
    }
    ll query(int p,int start,int end,int l,int r)
    {
        if (l <= start && end <= r) return tree[p];
        int m = start + (end - start) / 2;
        push_down(p,m - start + 1,end - m);

        ll res = 0;
        if (l <= m) res += query(p << 1,start,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,end,l,r);

        return res;
    }
public:
    segtree(const vector<ll>& a) 
    {
        n = a.size();
        tree.assign(4 * n,0);
        lazy.assign(4 * n,0);
        if (n > 0) 
        {
            build(1,0,n - 1,a);
        }
    }
    //区间[l,r]加v
    void update(int l,int r,ll v)
    {
        if (l <= r && l >= 0 && r < n) 
        {
            update(1,0,n - 1,l,r,v);
        }
    }
    //查询区间[l,r] 的和(下标0开始)
    ll query(int l,int r)
    {
        if (l <= r && l >= 0 && r < n) 
        {
            return query(1,0,n - 1,l,r);
        }
        return 0;
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    int ans = 0;
    for (int i = 1;i < n;i++) ans += ((a[i] - a[i - 1]) % 5 + 5) % 5;
    while (q--) 
    {
        int l,r;
        cin >> l >> r;
        l--;r--;
        if (l == r) 
        {
            int x = tr.query(l,l);
            if (l > 0) 
            {
                int x1 = tr.query(l - 1,l - 1);
                ans -= ((x - x1) % 5 + 5) % 5;
                x++;
                ans += ((x - x1) % 5 + 5) % 5;
                x--;
            }
            if (r + 1 < n) 
            {
                int x1 = tr.query(r + 1,r + 1);
                ans -= ((x1 - x) % 5 + 5) % 5;
                x++;
                ans += ((x1 - x) % 5 + 5) % 5;
                x--;
            }
            tr.update(l,r,1);
            cout << ans << endl;
            continue;
        }
        if (l > 0) 
        {
            int x1 = tr.query(l - 1,l - 1);
            int x2 = tr.query(l,l);
            ans -= ((x2 - x1) % 5 + 5) % 5;
            x2++;
            ans += ((x2 - x1) % 5 + 5) % 5;
        }
        if (r + 1 < n) 
        {
            if (l != r || (l == 0)) 
            {
                int x1 = tr.query(r,r);
                int x2 = tr.query(r + 1,r + 1);
                ans -= ((x2 - x1) % 5 + 5) % 5;
                // cout << ans << endl;
                x1++;
                ans += ((x2 - x1) % 5 + 5) % 5;
                // cout << ans << endl;
            }
        }
        cout << ans << endl;
        tr.update(l,r,1);
    }
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