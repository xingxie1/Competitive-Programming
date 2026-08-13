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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,d,h;
    cin >> n >> d >> h;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    double ans = 1.0 * d * h / 2.0 * n;
    for (int i = 1;i < n;i++)
    {
        if (a[i] - a[i - 1] < h)
        {
            double res = h - (a[i] - a[i - 1]);
            double d1 = 1.0 * d * res / h;
            ans -= res * d1 / 2.0;
        }
    }
    cout << fixed << setprecision(10);
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