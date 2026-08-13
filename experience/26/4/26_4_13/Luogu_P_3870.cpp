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
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
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
            lazy[p << 1] = (lazy[p << 1] + lazy[p]) % 2;
            lazy[p << 1 | 1] = (lazy[p << 1 | 1] + lazy[p]) % 2;
            if (lazy[p]) tree[p << 1] = lenl - tree[p << 1];
            if (lazy[p]) tree[p << 1 | 1] = lenr - tree[p << 1 | 1];
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
            tree[p] = end - start + 1 - tree[p];
            lazy[p] = (lazy[p] + v) % 2;
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
    int n,m;
    cin >> n >> m;
    vll a(n);
    segtree tree(a);
    while (m--)
    {
        int c,a,b;
        cin >> c >> a >> b;
        a--;b--;
        if (c == 0) tree.update(a,b,1);
        else cout << tree.query(a,b) << endl;
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