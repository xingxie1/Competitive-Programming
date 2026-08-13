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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int MOD = 998244353;
//const int MOD = (int)1e9+7;


void solve()
{
    int n;
    cin >> n;
    vt a(n);
    map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    ll ans = 0,sum = 0;
    for (auto& [x,c] : cnt) 
    {
        if (c >= 3) ans += 1LL * c * (c - 1) * (c - 2) / 6;
        if (c >= 2) ans += 1LL * c * (c - 1) / 2 * sum;
        sum += c;
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