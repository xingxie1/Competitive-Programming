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
    ll n,k;
    cin >> n >> k;
    vvt a(n);
    for (int i = 0;i < n;i++) 
    {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0;j < m;j++) cin >> a[i][j];
    }
    vll c(n);
    for (int i = 0;i < n;i++) cin >> c[i];
    ll sum = 0;
    for (int i = 0;i < n;i++) 
    {
        int m = a[i].size();
        if (sum + 1LL * m * c[i] < k) sum += 1LL * m * c[i];
        else 
        {
            ll res = k - sum;
            res = ((res - 1) % m + m) % m;
            cout << a[i][res] << endl;
            // cout << res << endl;
            return ;
        }
    }
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