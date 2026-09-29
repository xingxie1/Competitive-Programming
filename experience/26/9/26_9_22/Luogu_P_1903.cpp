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

struct Query
{
    int l,r,t,id;
};
struct Change 
{
    int pos,val;
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    int B = pow(n,2.0 / 3) + 1;
    vector<Query> qs;
    vector<Change> cs;
    int qid = 0;
    for (int i = 0;i < q;i++)
    {
        char op;
        cin >> op;
        if (op == 'Q') 
        {
            int l,r;
            cin >> l >> r;
            qs.push_back({l,r,(int)cs.size(),qid});
            qid++;
        }
        else 
        {
            int pos,x;
            cin >> pos >> x;
            cs.push_back({pos,x});
        }
    }
    sort(qs.begin(),qs.end(),[&](auto& x,auto& y){
        int xl = x.l / B;
        int yl = y.l / B;
        int xr = x.r / B;
        int yr = y.r / B;
        if (xl != yl) return xl < yl;
        if (xr != yr) 
        {
            if (xl % 2) return xr > yr;
            return xr < yr;
        }
        if (xr % 2) return x.t > y.t;
        return x.t < y.t;
    });
    int L = 1,R = 0,T = 0;
    int res = 0;
    vt cnt(1e6 + 5);
    auto add = [&](int x) 
    {
        if (cnt[x] == 0) res ++;
        cnt[x]++;
    };
    auto del = [&](int x) 
    {
        cnt[x]--;
        if (cnt[x] == 0) res--;
    };
    auto update = [&](int id) 
    {
        auto&[pos,val] = cs[id];
        if (L <= pos && pos <= R) 
        {
            del(a[pos]);
            add(val);
        }
        swap(a[pos],val);
    };
    vt ans(qs.size());
    for (auto& [l,r,t,id] : qs)
    {
        while (T < t) 
        {
            update(T);
            T++;
        }
        while (T > t) 
        {
            T--;
            update(T);
        }
        while (R < r) add(a[++R]);
        while (R > r) del(a[R--]);
        while (L < l) del(a[L++]);
        while (L > l) add(a[--L]);
        ans[id] = res;
    }
    for (int x : ans) cout << x << endl;
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