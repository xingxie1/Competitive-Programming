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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(2 * n);
    for (int i = 0;i < 2 * n;i++) cin >> a[i];
    ranges::sort(a);
    if (n == 1) 
    {
        cout << a[1] - a[0] << endl;
    }
    else if (n % 2) 
    {
        ll ans = 0;
        for (int x : a) ans += abs(x);
        cout << ans << endl;
    }
    else 
    {
        ll ans = 0,sum = 0;
        for (int x : a) ans += abs(x);
        if (n == 2)
        {
            for (int x : a) sum += abs(x - 2);
            ans = min(ans,sum);
            sum = 0;
        }
        for (int i = 0;i < 2 * n - 1;i++) sum += abs(a[i] + 1);
        sum += abs(a[2 * n - 1] - n);
        ans = min(ans,sum);
        cout << ans << endl;
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