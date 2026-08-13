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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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
    ll n;
    cin >> n;
    vll a;
    ll N = n;
    for (ll i = 2;i * i <= N;i++) 
    {
        while (n % i == 0) 
        {
            n /= i;
            a.push_back(i);
        }
    }
    if (n > 1) a.push_back(n);
    map<ll,int> cnt;
    for (ll x : a) cnt[x]++;
    ll mx = 0,xx = 0;
    for (auto& [x,c] : cnt) 
    {
        if (c > mx) 
        {
            mx = c;
            xx = x;
        }
    }
    vll ans;
    while (mx--) ans.push_back(xx);
    for (ll x : a) if (x != xx) ans.push_back(x);
    int m = ans.size();
    int j = -1;
    for (int i = 0;i < m - 1;i++) 
    {
        if (ans[i + 1] % ans[i]) 
        {
            j = i;
            break;
        }
    }
    if (j != -1) for (int i = j + 1;i < m;i++) ans[j] *= ans[i];
    while (j != -1 && ans.size() > j + 1) ans.pop_back();
    cout << ans.size() << endl;
    for (ll x : ans) cout << x << " ";
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