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
    int n;
    vpii mx;
    void up(int p)
    {
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void update(int p,int st,int ed,int i,pii v) 
    {
        if (i == st && i == ed)
        {
            mx[p] = max(mx[p],v);
            return ;
        }
        int m = st + ed >> 1;
        if (i <= m) update(p << 1,st,m,i,v);
        else update(p << 1 | 1,m + 1,ed,i,v);
        up(p);
    }
    pii query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return mx[p];
        }
        int m = st + ed >> 1;
        pii res = {0,-1};
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(int _n)
    {
        n = _n;
        mx.assign(n << 2,pair{0,-1});
    }
    void update(int i,pii v)
    {
        update(1,0,n - 1,i,v);
    }
    pii query(int l,int r)
    {
        return query(1,0,n - 1,l,r);
    }
};

void solve()
{
    int n,d;
    cin >> n >> d;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    auto tmp = a;
    ranges::sort(tmp);
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    int m = tmp.size();
    vt r(m + 1),l(m + 1);
    segtree tr(m + 1);
    for (int id = 1;id <= m;id++)
    {
        ll x = tmp[id - 1];
        r[id] = ranges::lower_bound(tmp,x + d) - tmp.begin() + 1;
        l[id] = ranges::upper_bound(tmp,x - d) - tmp.begin();
    }
    int mx = 0,last = -1;
    vt pre(n,-1);
    for (int i = 0;i < n;i++)
    {
        int id = ranges::lower_bound(tmp,a[i]) - tmp.begin() + 1;
        pii best = {0,-1};
        if (l[id] >= 1)
        {
            best = max(best,tr.query(1,l[id]));
        }
        if (r[id] <= m)
        {
            best = max(best,tr.query(r[id],m));
        }
        int cur = best.fi + 1;
        pre[i] = best.se;
        tr.update(id,pair{cur,i});
        if (cur > mx)
        {
            mx = cur;
            last = i;
        }
    }
    cout << mx << endl;
    vt ans;
    while (last != -1) 
    {
        ans.push_back(last);
        last = pre[last];
    }
    ranges::reverse(ans);
    for (int x : ans) cout << x + 1 << " ";
    cout << endl;
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