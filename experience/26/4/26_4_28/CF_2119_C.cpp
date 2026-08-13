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
    ll n,l,r,k;
    cin >> n >> l >> r >> k;
    if (n % 2)
    {
        cout << l << endl;
        return ;
    }
    if (n == 2) 
    {
        cout << -1 << endl;
        return ;
    }
    if (bit_width(1ull * l) == bit_width(1ull * r)) 
    {
        cout << -1 << endl;
        return ;
    }
    if (k <= n - 2) 
    {
        cout << l << endl;
    }
    else 
    {
        cout << (1LL << bit_width(1ull * l)) << endl;
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