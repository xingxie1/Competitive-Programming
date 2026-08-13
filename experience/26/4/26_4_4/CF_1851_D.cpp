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

void solve()
{
    int n;
    cin >> n;
    vll a(n - 1);
    for (int i = 0;i < n - 1;i++) cin >> a[i];
    vll d(n - 1);
    d[0] = a[0];
    for (int i = 1;i < n - 1;i++) d[i] = a[i] - a[i - 1];
    ll total = 1LL * n * (n + 1) / 2;
    if (a.back() != total) 
    {
        vt cnt(n + 1);
        for (ll x : d)
        {
            if (x <= 0 || x > n || cnt[x] == 1) 
            {
                cout << "NO" << endl;
                return ;
            }
            cnt[x] = 1;
        }
        cout << "YES" << endl;
    }
    else 
    {
        vt cnt(n + 1);
        vll b;
        for (ll x : d)
        {
            if (x > 0 && x <= n && cnt[x] == 0) cnt[x] = 1;
            else b.push_back(x);
        }
        vll c;
        for (int i = 1;i <= n;i++)
        {
            if (cnt[i] == 0) c.push_back(i);
        }
        if (b.size() == 1 && c.size() == 2)
        {
            if (b[0] == c[0] + c[1]) 
            {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
    
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