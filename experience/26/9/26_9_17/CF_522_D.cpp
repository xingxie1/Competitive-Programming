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

const int B = 120;
void solve()
{
    int n,q;
    cin >> n >> q;
    vt a(n + 1);
    vt pre(n + 1),nxt(n + 1,n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    umap<int,int> last;
    last.reserve(n * 2);
    for (int i = 1;i <= n;i++) 
    {
        if (last.count(a[i])) pre[i] = last[a[i]];
        last[a[i]] = i;
    }
    last.clear();
    for (int i = n;i >= 1;i--)
    {
        if (last.count(a[i])) nxt[i] = last[a[i]];
        last[a[i]] = i;
    }
    int cnt = (n + B - 1) / B;
    auto bel = [&](int x) 
    {
        return (x - 1) / B;
    };
    vvt f(cnt,vt(cnt,INT_MAX / 2));
    for (int i = 1;i <= n;i++)
    {
        if (pre[i]) 
        {
            int x = bel(pre[i]);
            int y = bel(i);
            f[x][y] = min(f[x][y],i - pre[i]);
        }
    }
    for (int x = cnt - 1;x >= 0;x--)
    {
        for (int y = 0;y < cnt;y++)
        {
            if (x + 1 < cnt) 
            {
                f[x][y] = min(f[x][y],f[x + 1][y]);
            }
            if (y - 1 >= 0)
            {
                f[x][y] = min(f[x][y],f[x][y - 1]);
            }
        }
    }
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        int bl = bel(l);
        int br = bel(r);
        int ans = INT_MAX / 2;
        if (bl + 1 <= br - 1) ans = f[bl + 1][br - 1];
        int right = min(r,(bl + 1) * B);
        for (int i = l;i <= right;i++)
        {
            if (nxt[i] <= r) ans = min(ans,nxt[i] - i);
        }
        if (bl != br)
        {
            int left = br * B + 1;
            for (int i = left;i <= r;i++)
            {
                if (pre[i] >= l) ans = min(ans,i - pre[i]);
            }
        }
        if (ans == INT_MAX / 2) ans = -1;
        cout << ans << endl;
    }

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

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// using i128 = __int128_t;
// using vt = vector<int>;
// using vd = vector<double>;
// using vll = vector<long long>;
// using vvt = vector<vector<int>>;
// using vvd = vector<vector<double>>;
// using vvll = vector<vector<long long>>;
// using vvvt = vector<vector<vector<int>>>;
// using vvvll = vector<vector<vector<long long>>>;
// using pii = pair<int,int>;
// using pll = pair<ll,ll>;
// using pdd = pair<double,double>;
// using vpii = vector<pair<int,int>>;
// using vpll = vector<pair<ll,ll>>;
// using vpdd = vector<pair<double,double>>;
// using vvpii = vector<vector<pair<int,int>>>;
// using vvpll = vector<vector<pair<ll,ll>>>;
// using tri = tuple<int,int,int>;
// using trl = tuple<ll,ll,ll>;
// using vtri = vector<tuple<int,int,int>>;
// using vtrl = vector<tuple<ll,ll,ll>>;
// #define YES cout << "YES" << endl
// #define Yes cout << "Yes" << endl
// #define NO cout << "NO" << endl
// #define No cout << "No" << endl
// #define fi first
// #define se second
// #define umap unordered_map
// #define uset unordered_set
// #define pqueue priority_queue
// #define mset multiset
// #define endl '\n'
// //const int MOD = 998244353;
// //const int MOD = (int)1e9+7;

// class segtree
// {
//     int n;
//     vt mn;
//     void up(int p)
//     {
//         mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
//     }
//     void update(int p,int st,int ed,int i,int v)
//     {
//         if (i == st && i == ed)
//         {
//             mn[p] = v;
//             return ;
//         }
//         int m = st + ed >> 1;
//         if (i <= m) update(p << 1,st,m,i,v);
//         else update(p << 1 | 1,m + 1,ed,i,v);
//         up(p);
//     }
//     int query(int p,int st,int ed,int l,int r)
//     {
//         if (l <= st && r >= ed) return mn[p];
//         int m = st + ed >> 1;
//         int res = INT_MAX / 2;
//         if (l <= m) res = min(res,query(p << 1,st,m,l,r));
//         if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
//         return res;
//     }
// public:
//     segtree (int _n)
//     {
//         n = _n;
//         mn.assign(n << 2,INT_MAX / 2);
//     }
//     void update(int i,int v)
//     {
//         update(1,0,n - 1,i,v);
//     }
//     int query(int l,int r)
//     {
//         return query(1,0,n - 1,l,r);
//     }
// };

// void solve()
// {
//     int n,q;
//     cin >> n >> q;
//     vt a(n);
//     for (int i = 0;i < n;i++) cin >> a[i];
//     vvpii qs(n);
//     for (int i = 0;i < q;i++)
//     {
//         int l,r;
//         cin >> l >> r;
//         l--;r--;
//         qs[r].push_back({l,i});
//     }
//     vt ans(q,-1);
//     umap<int,int> last;
//     last.reserve(n * 2);
//     segtree tr(n);
//     for (int r = 0;r < n;r++)
//     {
//         if (last.count(a[r])) 
//         {
//             tr.update(last[a[r]],r - last[a[r]]);
//         }
//         last[a[r]] = r;
//         for (auto& [l,i] : qs[r])
//         {
//             int res = tr.query(l,r);
//             if (res != INT_MAX / 2) ans[i] = res;
//         }
//     }
//     for (int x : ans) cout << x << endl;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cout << fixed << setprecision(15);
//     int _ = 1;
//     // cin >> _;
//     while (_ --) solve();

//     return 0;
// }