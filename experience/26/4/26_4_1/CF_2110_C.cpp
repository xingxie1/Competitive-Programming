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
    vt d(n);
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> d[i];
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    vt mn(n + 1),mx(n + 1);
    for (int i = 0;i < n;i++)
    {
        auto [l, r] = a[i];
        int low,high;
        if (d[i] == 0)
        {
            low = mn[i];
            high = mx[i];
        }
        else if (d[i] == 1)
        {
            low = mn[i] + 1;
            high = mx[i] + 1;
        }
        else 
        {
            low = mn[i];
            high = mx[i] + 1;
        }
        mn[i + 1] = max(low,l);
        mx[i + 1] = min(high,r);
        if (mn[i + 1] > mx[i + 1]) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    int h = mn[n];
    int sum = mn[n];
    for (int i = n - 1;i >= 0;i--)
    {
        if (d[i] != -1) 
        {
            sum -= d[i];
            continue;
        }
        if (sum - 1 >= mn[i] && sum - 1 <= mx[i]) 
        {
            d[i] = 1;
            sum--;
        }
        else d[i] = 0;
    }
    for (int x : d) cout << x << " ";
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