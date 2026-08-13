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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll ans = 0;
    for (int i = 0;i < n;i++) 
    {
        if (s[i] == '0') continue;
        int j = i;
        int mn = a[i];
        int sum = 0;
        if (i > 0) 
        {
            mn = min(a[i - 1],mn);
            sum += a[i - 1];
        }
        while (j < n && s[j] == '1') 
        {
            sum += a[j];
            mn = min(mn,a[j]);
            j++;
        }
        ans += sum - mn;
        if (i == 0) ans += mn;
        i = j - 1;
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