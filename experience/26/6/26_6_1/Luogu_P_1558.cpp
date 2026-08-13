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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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
    int n;
    vt tr,add;
    void push_up(int p) 
    {
        tr[p] = tr[p << 1] | tr[p << 1 | 1];
    }
    void apply (int p,int v) 
    {
        tr[p] = v;
        add[p] = v;
    }
    void push_down(int p) 
    {
        if (add[p] != 0) 
        {
            apply(p << 1,add[p]);
            apply(p << 1 | 1,add[p]);
            add[p] = 0;
        }
    }
    void build (int p,int l,int r,const vt& a) 
    {
        if (l == r) 
        {
            tr[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        if (l <= m) build(p << 1,l,m,a);
        if (r > m) build(p << 1 | 1,m + 1,r,a);
        push_up(p);
    }
    void update(int p,int st,int ed,int l,int r,int v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,v);
            return ;
        }
        int m = st + ed >> 1;
        push_down(p);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        push_up(p);
    }
    int query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return tr[p];
        int m = st + ed >> 1;
        int res = 0;
        push_down(p);
        if (l <= m) res |= query(p << 1,st,m,l,r);
        if (r > m) res |= query(p << 1 | 1,m + 1,ed,l,r);
        return res;
    }
public:
    segtree(const vt& a) 
    {
        n = a.size();
        tr.assign(n << 2,0);
        add.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,int v) 
    {
        update(1,0,n - 1,l,r,1 << v);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    vt a(n,1);
    segtree tr(a);
    while (q--) 
    {
        char op;
        cin >> op;
        if (op == 'C') 
        {
            int l,r,c;
            cin >> l >> r >> c;
            l--;r--;c--;
            if (l > r) swap(l,r);
            tr.update(l,r,c);
        }
        else 
        {
            int l,r;
            cin >> l >> r;
            l--;r--;
            if (l > r) swap(l,r);
            int ans = tr.query(l,r);
            cout << popcount(1u * ans) << endl;
        }
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