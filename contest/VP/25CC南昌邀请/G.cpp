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
    if (n % 3 == 0) cout << n / 3 << endl;
    else if (n % 3 == 1) 
    {
        if (n == 4 || n == 1) cout << -1 << endl;
        else cout << n / 3 - 1 << endl;
    }
    else if (n % 3 == 2) 
    {
        if (n == 2) cout << -1 << endl;
        else cout << n / 3 << endl;
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