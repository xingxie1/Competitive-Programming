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
    int n;
    vt add,tr;
    void up(int p) {tr[p] = max(tr[p << 1],tr[p << 1 | 1]);};
    void down(int p)
    {
        if (add[p] != 0) 
        {
            apply(p << 1,add[p]);
            apply(p << 1 | 1,add[p]);
            add[p] = 0;
        }
    }
    void apply(int p,int v) 
    {
        tr[p] += v;
        add[p] += v;
    }
    void build(int p,int l,int r,const vt& a) 
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
    void update(int p,int st,int ed,int l,int r,int v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,v);
            return ;
        }
        int m = st + ed >> 1;
        down(p);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    int query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return tr[p];
        int m = st + ed >> 1;
        down(p);
        int res = INT_MIN;
        if (l <= m) res = min(res,query(p << 1,st,m,l,r));
        if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public: 
    segtree (const vt& a) 
    {
        n = a.size();
        tr.assign(n << 2,0);
        add.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,int v) 
    {
        update(1,0,n - 1,l,r,v);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }

};
void solve()
{
    int n,k;
    cin >> n >> k;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    vt b(n);
    segtree tr(b);
    int l = 0,r = 0,ans = 0;
    while (r < n) 
    {
        int x = a[r].fi,y = a[r].se;
        tr.update(x - 1,y - 1,1);
        while (l < r && tr.query(0,n - 1) > k) 
        {
            tr.update(a[l].fi - 1,a[l].se - 1,-1);
            l++;
        }
        ans = max(ans,r - l + 1);
        r++;
        // cout << tr.query(0,n - 1) << endl;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}