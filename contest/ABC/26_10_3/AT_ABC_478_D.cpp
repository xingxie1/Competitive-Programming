#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

class segtree
{
private:
    vector<ll> tr;
    vector<ll> add;
    int n;
    void up(int p)
    {
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }
    void down(int p,int lenl,int lenr)
    {
        if (add[p] != 0)
        {
            add[p << 1] += add[p];
            add[p << 1 | 1] += add[p];
            tr[p << 1] += add[p] * lenl;
            tr[p << 1 | 1] += add[p] * lenr;
            add[p] = 0;
        }
    }
    void build(int p,int l,int r,const vector<ll>& a)
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
    //区间[l,r]加上v
    void update(int p,int start,int end,int l,int r,ll v)
    {
        if (l <= start && end <= r) 
        {
            tr[p] += v * (end - start + 1);
            add[p] += v;
            return ;
        }
        int m = start + (end - start) / 2;
        down(p,m - start + 1,end - m);
        if (l <= m) update(p << 1,start,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,end,l,r,v);
        up(p);
    }
    ll query(int p,int start,int end,int l,int r)
    {
        if (l <= start && end <= r) return tr[p];
        int m = start + (end - start) / 2;
        down(p,m - start + 1,end - m);

        ll res = 0;
        if (l <= m) res += query(p << 1,start,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,end,l,r);

        return res;
    }
public:
    segtree(const vector<ll>& a) 
    {
        n = a.size();
        tr.assign(4 * n,0);
        add.assign(4 * n,0);
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
    map<int,set<pii>> p;
    while (q--) 
    {
        int l,r,x;
        cin >> l >> r >> x;
        l--;r--;
        auto& st = p[x];
        auto it = st.lower_bound({l,-1});
        if (it != st.begin())
        {
            auto pre = prev(it);
            if (pre->se >= l)
            {
                l = min(l,pre->fi);
                r = max(r,pre->se);
                st.erase(pre);
            }
        }
        while (it != st.end() && it->fi <= r) 
        {
            r = max(r,it->se);
            it = st.erase(it);
        }
        st.insert({l,r});
    }   
    vll tmp(n);
    segtree tr(tmp);
    for (auto& [x,a] : p)
    {
        for (auto& [l,r] : a) 
        {
            tr.update(l,r,1);
        }
    }
    for (int i = 0;i < n;i++) cout << tr.query(i,i) << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}