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
    int l, r, id;
};

void solve()
{
    int n,q;
    cin >> n >> q;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vector<Query> qs(q);
    for (int i = 0; i < q; i++)
    {
        cin >> qs[i].l >> qs[i].r;
        qs[i].id = i;
    }
    int B = sqrt(n) + 1;
    sort(qs.begin(), qs.end(), [&](auto& x,auto& y)
    {
        int bx = x.l / B;
        int by = y.l / B;
        if (bx != by) return bx < by;
        if (bx & 1) return x.r > y.r;
        else return x.r < y.r;
    });
    vt cnt(2e5 + 1);
    vt sum(2e5 + 1);
    vt ans(q);
    int L = 1,R = 0;
    auto bel = [&](int x) 
    {
        return x / B;
    };
    auto add = [&](int x) 
    {
        cnt[x]++;
        if (cnt[x] == 1) sum[bel(x)]++;
    };
    auto del = [&](int x)
    {
        cnt[x]--;
        if (cnt[x] == 0) sum[bel(x)]--;
    };
    for (auto&[l, r, id] : qs)
    {
        while (L > l) add(a[--L]);
        while (R < r) add(a[++R]);
        while (L < l) del(a[L++]);
        while (R > r) del(a[R--]);

        int mex = 0;
        for (int i = 0;;i++) 
        {
            if (sum[i] != B) 
            {
                for (int x = i * B;x < (i + 1) * B;x++) 
                {
                    if (cnt[x] == 0) 
                    {
                        mex = x;
                        break;
                    }
                }
                break;
            }
            mex = (i + 1) * B;
        }
        ans[id] = mex;
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