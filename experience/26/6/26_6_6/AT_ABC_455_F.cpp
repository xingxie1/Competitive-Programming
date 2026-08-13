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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

class segtree 
{
    int n;
    vll sum1,sum2,add;
    void up(int p) 
    {
        sum1[p] = (sum1[p << 1] + sum1[p << 1 | 1]) % MOD;
        sum2[p] = (sum2[p << 1] + sum2[p << 1 | 1] + sum1[p << 1] * sum1[p << 1 | 1] % MOD) % MOD;
    }
    void apply(int p,ll len,ll v)
    {
        v %= MOD;
        ll c = len * (len - 1) / 2 % MOD;
        sum2[p] = (sum2[p] + (len - 1) * sum1[p] % MOD * v % MOD + c * v % MOD * v % MOD) % MOD;
        sum1[p] = (sum1[p] + v * len % MOD) % MOD;
        add[p] = (add[p] + v) % MOD;
    }
    void down(int p,int st,int ed) 
    {
        if (add[p]) 
        {
            int m = st + ed >> 1;
            apply(p << 1,m - st + 1,add[p]);
            apply(p << 1 | 1,ed - m,add[p]);
            add[p] = 0;
        }
    }
    void update(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,ed - st + 1,v);
            return ;
        }
        int m = st + ed >> 1;
        down(p,st,ed);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    pll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return pair{sum1[p], sum2[p]};
        }
        int m = st + ed >> 1;
        down(p,st,ed);
        if (r <= m) return query(p << 1,st,m,l,r);
        if (l > m) return query(p << 1 | 1,m + 1,ed,l,r);
        auto left = query(p << 1,st,m,l,r);
        auto right = query(p << 1 | 1,m + 1,ed,l,r);
        pll res = {(left.fi + right.fi) % MOD,(left.se + right.se + (left.fi * right.fi) % MOD) % MOD};
        return res;
    }
public:
    segtree(vll& a)
    {
        n = a.size();
        sum1.assign(n << 2,0);
        sum2.assign(n << 2,0);
        add.assign(n << 2,0);
    }
    void update(int l,int r,ll v) 
    {
        update(1,0,n - 1,l,r,v);
    }
    ll query(int l,int r) 
    {
        return query(1,0,n - 1,l,r).se;
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n);
    segtree tr(a);
    while (q--) 
    {
        ll l,r,v;
        cin >> l >> r >> v;
        l--;r--;
        tr.update(l,r,v);
        cout << tr.query(l,r) << endl;
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