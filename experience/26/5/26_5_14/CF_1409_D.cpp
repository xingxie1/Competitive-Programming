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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    ll x,s;
    cin >> x >> s;
    string t = to_string(x);
    int n = t.size();
    vt pre(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + (t[i] - '0');
    if (pre[n] <= s) 
    {
        cout << 0 << endl;
        return ;
    }
    ll ans = LLONG_MAX;
    for (int i = n - 2;i >= 0;i--)
    {
        ll all = pre[i];
        ll suf = stoll(t.substr(i + 1));
        ll ta = pow(10,n - i - 1);
        ll p10 = pow(10,n - i - 1);
        ll sum = p10 - suf;
        for (char c = t[i] + 1;c <= '9';c++) 
        {
            if (all + c - '0' <= s) ans = min(ans,sum);
            sum += p10;
        }
    }
    if (ans == LLONG_MAX) 
    {
        ll p10 = pow(10,t.size());
        ans = p10 - x;
    }
    cout << ans << endl;


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