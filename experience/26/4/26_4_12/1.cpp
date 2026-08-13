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
    // for (int n = 1;n <= 1000;n++)
    // {
    //     set<int> st;
    //     for (int i = 1;i <= n;i++)
    //     {
    //         for (int j = i;j <= n;j++) st.insert(i ^ j);
    //     }
    //     cout << n << " : " << endl;
    //     for (int x : st) cout << x << " ";
    //     cout << endl;
    // }
    ll n;
    cin >> n;
    if (n <= 2) cout << 1 << endl;
    else cout << (1 << bit_width(1ull * n)) << endl;
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