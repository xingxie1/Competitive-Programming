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

void solve()
{
    int n,q;
    cin >> n >> q;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vt b = a;
    int B = sqrt(n);
    int cnt = (n + B - 1) / B;
    for (int i = 1;i <= n;i += B)
    {
        if (i + B <= n + 1) sort(b.begin() + i,b.begin() + i + B);
        else sort(b.begin() + i,b.end());
    }
    vt add(cnt);
    auto bel = [&](int x) 
    {
        return (x - 1) / B;
    };
    auto rebuild = [&](int id)
    {
        int l = id * B + 1;
        int r = min(n,(id + 1) * B);
        for (int i = l;i <= r;i++) b[i] = a[i];
        sort(b.begin() + l,b.begin() + r + 1);
    };
    while (q--)
    {
        char op;
        int l,r,x;
        cin >> op >> l >> r >> x;
        if (op == 'M')
        {
            int bl = bel(l),br = bel(r);
            if (bl == br)
            {
                for (int i = l;i <= r;i++) 
                {
                    a[i] += x;
                }
                rebuild(bl);
            }
            else 
            {
                for (int i = l;i <= (bl + 1) * B;i++) a[i] += x;
                rebuild(bl);
                for (int i = bl + 1;i <= br - 1;i++) add[i] += x;
                for (int i = br * B + 1;i <= r;i++) a[i] += x;
                rebuild(br);
            }
        }
        else 
        {
            int bl = bel(l),br = bel(r);
            int ans = 0;
            if (bl == br)
            {
                for (int i = l;i <= r;i++) 
                {
                    ans += a[i] + add[bel(i)] >= x;
                }
            }
            else 
            {
                for (int i = l;i <= (bl + 1) * B;i++) ans += a[i] + add[bel(i)] >= x;
                for (int i = bl + 1;i <= br - 1;i++) 
                {
                    ans += b.begin() + (i + 1) * B  + 1 - lower_bound(b.begin() + i * B + 1,b.begin() + (i + 1) * B + 1,x - add[i]);
                }
                for (int i = br * B + 1;i <= r;i++) 
                {
                    ans += a[i] + add[bel(i)] >= x;
                }
            }
            cout << ans << endl;
        }
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