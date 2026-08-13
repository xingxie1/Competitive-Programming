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
    vpll a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    for (int i = 1;i < n - 1;i++)
    {
        ll a1 = a[i - 1].fi,b1 = a[i - 1].se;
        ll a2 = a[i].fi,b2 = a[i].se;
        ll a3 = a[i + 1].fi,b3 = a[i + 1].se;
        if (a1 * a3 - b1 * b3 == a2 * a2 - b2 * b2 && a3 * b1 + a1 * b3 == 2 * a2 * b2) {}
        else 
        {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
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