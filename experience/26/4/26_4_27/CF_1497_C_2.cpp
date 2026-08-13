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
    ll t = n / 2,mx = 0;
    for (int i = 0;i < k - 3;i++) cout << 1 << " ";
    n -= (k - 3);
    if (n % 4 == 0) cout << n / 2 << " " << n / 2 / 2 << " " << n / 2 / 2 << endl;
    else 
    {
        int m = n / 2;
        if (n % 2) cout << m << " " << m << " " << n - 2 * m << endl;
        else if (n % 4 == 2) cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2 << endl;
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