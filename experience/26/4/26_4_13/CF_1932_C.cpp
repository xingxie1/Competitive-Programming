#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

ll qpow(ll a,ll b,int m)
{
    ll ret = 1;
    if (b == -1) return a;
    while (b)
    {
        if (b & 1) ret = a * ret % m;
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n),b;
    for (int i = 0;i < n;i++) cin >> a[i];
    string s;
    cin >> s;
    int l = 0,r = n - 1;
    for (char c : s)
    {
        if (c == 'L') b.push_back(a[l++]);
        else b.push_back(a[r--]);
    }
    ranges::reverse(b);
    vt ans;
    ll sum = 1;
    for (int x : b) 
    {
        sum = sum * x % m;
        ans.push_back(sum);
    }
    ranges::reverse(ans);
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}