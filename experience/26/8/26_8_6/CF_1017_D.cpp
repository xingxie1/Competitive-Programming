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
    int n,m,q;
    cin >> n >> m >> q;
    vt w(n),cnt(1 << n);
    for (int i = 0;i < n;i++) cin >> w[i];
    auto get = [&](string& s) 
    {
        int x = 0;
        for (int i = 0;i < n;i++) 
        {
            if (s[i] == '1') x |= 1 << i;
        }
        return x;
    };
    for (int i = 0;i < m;i++)
    {
        string s;
        cin >> s;
        cnt[get(s)]++;
    }
    vt sum(1 << n);
    for (int mask = 0;mask < 1 << n;mask++)
    {
        for (int i = 0;i < n;i++) 
        {
            if (mask >> i & 1) sum[mask] += w[i];
        }
    }
    int all = (1 << n) - 1;
    vvll ans(1 << n,vll(101));
    for (int t = 0;t < 1 << n;t++)
    {
        for (int s = 0;s < 1 << n;s++)
        {
            int same = all ^ s ^ t;
            int v = sum[same];
            if (v <= 100)
            {
                ans[t][v] += cnt[s];
            }
        }
    }
    for (int t = 0;t < 1 << n;t++)
    {
        for (int kk = 1;kk <= 100;kk++)
        {
            ans[t][kk] += ans[t][kk - 1];
        }
    }
    while (q--)
    {
        int k;
        string s;
        cin >> s >> k;
        int t = get(s);
        cout << ans[t][k] << endl;
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