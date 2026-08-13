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
    int n,L,R;
    cin >> n >> L >> R;
    string s;
    cin >> s;
    vvt dp(n,vt(n));
    vt pre(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + s[i] - '0';
    auto dfs = [&](auto&& self,int l,int r) 
    {
        if (r <= l) return dp[l][r] = 0;
        if (dp[l][r]) return dp[l][r];
        int mx = 0;
        for (int i = l + 1;i <= r;i++) 
        {
            int lenl = i - l,lenr = r - i + 1;
            int c0 = lenl - (pre[i] - pre[l]),c1 = pre[r + 1] - pre[i];
            if (abs(c0 - c1) >= L && abs(c0 - c1) <= R) mx = max(mx,self(self,l,i - 1) + self(self,i,r) + 1);
        }
        return dp[l][r] = mx;
    };
    dfs(dfs,0,n - 1);
    cout << dp[0][n - 1] << endl;
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