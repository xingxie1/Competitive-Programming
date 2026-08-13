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
    int n,k;
    cin >> n >> k;
    vt a(n);
    map<int,int> cnt;
    for (int i = 0;i < n;i++) cin >> a[i],cnt[a[i]]++;
    for (auto& [x, c] : cnt) 
    {
        if (c % k)
        {
            cout << 0 << endl;
            return ;
        }
    }
    ll ans = 0;
    int l = 0,r = 0;
    map<int,int> c2;
    while (r < n) 
    {
        c2[a[r]]++;
        int t = cnt[a[r]] / k;
        while (l < r && c2[a[r]] > t) 
        {
            c2[a[l]]--;
            l++;
        }
        ans += r - l + 1;
        r++;
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