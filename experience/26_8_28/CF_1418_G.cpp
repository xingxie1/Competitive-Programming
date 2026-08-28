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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    map<ll,ll> hash1,hash2;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        hash1[a[i]] = rng();
        hash2[a[i]] = rng();
    }
    int l = 0,r = 0;
    ll ans = 0;
    map<ll,ll> tot,cntS,cnt;
    vll pre(n + 1);
    cntS[0] = 1;
    while (r < n)
    {
        pre[r + 1] = pre[r];
        int x = a[r];
        tot[x]++;
        cnt[x]++;
        if (tot[x] % 3 == 1) pre[r + 1] ^= hash1[x];
        else if (tot[x] % 3 == 2) pre[r + 1] ^= hash2[x];
        else pre[r + 1] ^= hash1[x] ^ hash2[x];
        while (l < r && cnt[x] > 3) 
        {
            cntS[pre[l]]--;
            cnt[a[l]]--;
            l++;
        }
        ans += cntS[pre[r + 1]];
        cntS[pre[r + 1]]++;
        r++;
    }
    cout << ans << endl;
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