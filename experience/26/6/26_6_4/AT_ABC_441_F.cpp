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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt w(n),v(n);
    for (int i = 0;i < n;i++) cin >> w[i] >> v[i];
    vvll suf(n + 1,vll(m + 1));
    for (int i = n - 1;i >= 0;i--) 
    {
        for (int x = m;x >= 0;x--) 
        {
            suf[i][x] = max(suf[i][x],suf[i + 1][x]);
            if (x >= w[i]) suf[i][x] = max(suf[i][x],suf[i + 1][x - w[i]] + v[i]);
        }
    }
    ll mx = suf[0][m];
    vll pre(m + 1);
    string ans;
    for (int i = 0;i < n;i++) 
    {
        auto np = pre;
        for (int j = m;j >= w[i];j--) 
        {
            np[j] = max(np[j],pre[j - w[i]] + v[i]);
        }
        ll mmm = 0;
        for (int j = 0;j <= m;j++) 
        {
            mmm = max(mmm,pre[j] + suf[i + 1][m - j]);
        }
        if (mmm < mx) 
        {
            ans += 'A';
            pre = np;
            continue;
        }
        mmm = 0;
        for (int j = 0;j <= m - w[i];j++) 
        {
            mmm = max(mmm,pre[j] + suf[i + 1][m - j - w[i]] + v[i]);
        }
        if (mmm < mx) 
        {
            ans += 'C';
            pre = np;
            continue;
        }
        ans += 'B';
        pre = np;
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