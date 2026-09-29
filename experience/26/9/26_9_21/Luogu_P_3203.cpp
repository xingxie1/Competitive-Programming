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
    int n;
    cin >> n;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    int B = sqrt(n);
    auto bel = [&](int x) 
    {
        return (x - 1) / B;
    };
    vt nxt(n + 1),cnt(n + 1);
    for (int i = n;i >= 1;i--) 
    {
        int to = i + a[i];
        if (to > n || bel(to) != bel(i)) 
        {
            nxt[i] = to;
            cnt[i] = 1;
        }
        else 
        {
            nxt[i] = nxt[to];
            cnt[i] = cnt[to] + 1;
        }
    }
    auto rebuild = [&](int b)
    {
        for (int i = min(n,b * B + B);i >= b * B + 1;i--)
        {
            int to = i + a[i];
            if (to > n || bel(to) != bel(i)) 
            {
                nxt[i] = to;
                cnt[i] = 1;
            }
            else 
            {
                nxt[i] = nxt[to];
                cnt[i] = cnt[to] + 1;
            }
        }
    };
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int i;
            cin >> i;
            i++;
            int ans = 0;
            while (i <= n) 
            {
                ans += cnt[i];
                i = nxt[i];
            } 
            cout << ans << endl;
        }
        else 
        {
            int i,x;
            cin >> i >> x;
            i++;
            a[i] = x;
            rebuild(bel(i));
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