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

void solve()
{
    int n,m,k;
    cin >> n >> m;
    vt a(n);
    for (int i = 0;i < n;i++) 
    {
        string s;
        cin >> s;
        int x = 0;
        for (char c : s) 
        {
            if (c == '1') x = x * 2 + 1;
            else x *= 2;
        }
        a[i] = x;
    }
    cin >> k;
    vt b(k);
    for (int i = 0;i < k;i++) 
    {
        string s;
        cin >> s;
        int x = 0;
        for (char c : s) 
        {
            if (c == '1') x = x * 2 + 1;
            else x *= 2;
        }
        b[i] = x;
    }
    unordered_map<int,int> p;
    for (int mask = 0;mask < 1 << k;mask++)
    {
        int x = 0;
        for (int i = 0;i < k;i++) 
        {
            if (mask >> i & 1) x |= b[i];
        }
        p[mask] = x;
        // cout << mask << " " << x << endl;
    }
    for (int x : a) 
    {
        int ans = 30;
        for (auto& [mask,y] : p) 
        {
            int tmp = x ^ y;
            // cout << tmp << endl;
            if (tmp == 0) 
            {
                ans = min(ans,__builtin_popcount(1u * mask));
                continue;
            }
            int f = 1;
            for (int i = 0;i < m;i++) 
            {
                if ((tmp >> i & 1) && (x >> i & 1)) 
                {
                    f = 0;
                    break;
                }
            }
            if (f) ans = min(ans,__builtin_popcount(1u * mask));
        }
        if (ans == 30) cout << -1 << endl;
        else cout << ans << endl;
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