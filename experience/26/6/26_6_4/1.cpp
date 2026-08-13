#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int MOD1 = 998244353;
const int MOD2 = (int)1e9+7;
const ll BASE = 32953;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vll h1(n + 1),p1(n + 1);
    vll h2(n + 1),p2(n + 1);
    p1[0] = 1;
    p2[0] = 1;
    for (int i = 0;i < n;i++) 
    {
        int x = s[i] - '0' + 1;
        h1[i + 1] = (h1[i] * BASE + x) % MOD1;
        h2[i + 1] = (h2[i] * BASE + x) % MOD2;
        p1[i + 1] = p1[i] * BASE % MOD1;
        p2[i + 1] = p2[i] * BASE % MOD2;
    }
    auto get = [&](int l,int r) 
    {
        ll x1 = (h1[r] - h1[l] * p1[r - l] % MOD1 + MOD1) % MOD1;
        ll x2 = (h2[r] - h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2;
        return pair{x1,x2};
    };
    vector<pair<pll,int>> a;
    for (int i = 0;i + m <= n;i++) 
    {
        a.push_back({get(i,i + m),i});
    }
    ranges::sort(a);
    int ans = 0;
    for (int i = 0;i < a.size();i++) 
    {
        int j = i;
        while (j < a.size() && a[j].fi == a[i].fi) j++;
        int cnt = 0;
        int last = -m;
        for (int t = i;t < j;t++) 
        {
            int pos = a[t].se;
            if (pos >= last + m) 
            {
                cnt++;
                last = pos;
            }
        }
        if (cnt == k) ans++;
        i = j - 1;
    }
    cout << ans << endl;

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