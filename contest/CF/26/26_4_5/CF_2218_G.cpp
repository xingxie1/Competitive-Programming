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
const int MOD = 676767677;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt b(n);
    ll ans = 1;
    for (int i = 0;i < n;i++) cin >> b[i];
    for (int i = i = 1;i < n - 1;i++)
    {
        if (b[i - 1] == b[i] - 1 && b[i] - 1 == b[i + 1]) ans = ans * b[i] % MOD;
        if (b[i] < b[i - 1] && b[i] < b[i + 1]) ans = 0;
    }
    if (b[0])
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